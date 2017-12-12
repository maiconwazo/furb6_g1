#include "OBJModel.h"


OBJModel::OBJModel()
{
}

OBJModel::OBJModel(string nm, float sz, int modelSize)
{
	modelNm = nm;
	maxSize = sz;
	initModelData(modelNm);

	loadModel(modelNm, modelSize);
	centerScale();
	drawToList();
}

void OBJModel::initModelData(string modelNm)
{
	verts = new vector<Tuple3*>();
	normals = new vector<Tuple3*>();
	texCoords = new vector<Tuple3*>();

	faces = new Faces(verts, normals, texCoords);
	faceMats = new FaceMaterials();
	modelDims = new ModelDimensions();
}

void OBJModel::loadModel(string modelNm, int modelSize)
{
	FileName = modelNm;
	FileSize = modelSize;
	string fnm = modelNm + ".obj";
	try {
		ifstream br_model;
		br_model.open(fnm);
		readModel(&br_model);
		br_model.close();
	}
	catch (exception e) {
		cout << e.what();
		terminate();
	}
}

void OBJModel::readModel(ifstream *br)
{
	bool isLoaded = true;
	int lineNum = 0;
	string line;
	bool isFirstCoord = true;
	bool isFirstTC = true;
	int numFaces = 0;

	try {
		while ((br->good()) && isLoaded) {
			double p = lineNum / FileSize;
			Progresso(p * 100);
			lineNum++;
			getline((*br), line);
			if (line.length() > 0) {
				line = trim(line);
				if (line.find("v ") == 0) {

					isLoaded = addVert(line, isFirstCoord);
					if (isFirstCoord) {
						isFirstCoord = false;
					}
				}
				else if (line.find("vt") == 0) {

					isLoaded = addTexCoord(line, isFirstTC);
					if (isFirstTC) {
						isFirstTC = false;
					}
				}
				else if (line.find("vn") == 0) {

					isLoaded = addNormal(line);
				}
				else if (line.find("f ") == 0) {

					isLoaded = faces->addFace(line);
					numFaces++;
				}
				else if (line.find("mtllib ") == 0) {

					materials = new Materials(line.substr(7));
				}
				else if (line.find("usemtl ") == 0) {

					faceMats->addUse(numFaces, line.substr(7));
				}
				else if (line.at(0) == 'g') {

				}
				else if (line.at(0) == 's') {

				}
				else if (line.at(0) == '#') {

					continue;
				}
			}
		}
	}
	catch (exception e) {
		cout << e.what();
		terminate();
	}

	if (!isLoaded) {
		cout << "Error loading model";
		terminate();
	}
}

bool OBJModel::addVert(string line, bool isFirstCoord)
{
	Tuple3 *vert = readTuple3(line);
	if (vert != nullptr) {
		verts->push_back(vert);
		if (isFirstCoord) {
			modelDims->set(vert);
		}
		else {
			modelDims->update(vert);
		}
		return true;
	}
	return false;
}

Tuple3 *OBJModel::readTuple3(string line)
{
	Tokenizer tokens(line, " ");
	tokens.next();
	try {
		float x = strtof(tokens.next().c_str(), 0);
		float y = strtof(tokens.next().c_str(), 0);
		float z = strtof(tokens.next().c_str(), 0);

		return new Tuple3(x, y, z);
	}
	catch (exception e) {
		cout << e.what();
	}

	return nullptr;
}

bool OBJModel::addTexCoord(string line, bool isFirstTC)
{
	if (isFirstTC) {
		hasTCs3D = checkTC3D(line);
	}

	Tuple3 *texCoord = readTCTuple(line);
	if (texCoord != nullptr) {
		texCoords->push_back(texCoord);
		return true;
	}
	return false;
}

bool OBJModel::checkTC3D(string line)
{
	int numTokens = 0;
	Tokenizer tokens("\\s+");
	while (tokens.next() != "")
	{
		numTokens++;
	}

	return numTokens == 4;
}

Tuple3 *OBJModel::readTCTuple(string line)
{
	Tokenizer tokens(line, " ");
	tokens.next();
	try {
		float x = strtof(tokens.next().c_str(), 0);
		float y = strtof(tokens.next().c_str(), 0);

		float z = DUMMY_Z_TC;
		if (hasTCs3D) {
			z = strtof(tokens.next().c_str(), 0);
		}
		return new Tuple3(x, y, z);
	}
	catch (exception e) {
		cout << e.what();
	}

	return nullptr;
}

bool OBJModel::addNormal(string line)
{
	Tuple3 *normCoord = readTuple3(line);
	if (normCoord != nullptr) {
		normals->push_back(normCoord);
		return true;
	}
	return false;
}

void OBJModel::centerScale()
{
	Tuple3 *center = modelDims->getCenter();

	float scaleFactor = 1.0f;
	float largest = modelDims->getLargest();
	if (largest != 0.0f) {
		scaleFactor = (maxSize / largest);
	}

	Tuple3 *vert;
	float x;
	float y;
	float z;
	int size = verts->size();
	for (int i = 0; i < size; i++) {
		vert = verts->at(i);
		x = (vert->getX() - center->getX()) * scaleFactor;
		vert->setX(x);
		y = (vert->getY() - center->getY()) * scaleFactor;
		vert->setY(y);
		z = (vert->getZ() - center->getZ()) * scaleFactor;
		vert->setZ(z);
	}
}

void OBJModel::drawToList()
{
	modelDispList = glGenLists(1);
	glNewList(modelDispList, GL_COMPILE);

	glPushMatrix();
	string *faceMat;
	for (int i = 0; i < faces->getNumFaces(); i++) {
		faceMat = &faceMats->findMaterial(i);
		if ((faceMat != nullptr) && (materials != nullptr)) {
			materials->renderWithMaterial((*faceMat));
		}
		faces->renderFace(i);
	}
	if (materials != nullptr)
	{
		materials->switchOffTex();
	}

	glPopMatrix();

	glEndList();
}

void OBJModel::draw()
{
	glCallList(modelDispList);
}

string OBJModel::trim(string & str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == string::npos)
		return "";
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

void OBJModel::Progresso(int porcentagem)
{
	string bar;

	for (int i = 0; i < 50; i++) {
		if (i < (porcentagem / 2)) {
			bar.replace(i, 1, "=");
		}
		else if (i == (porcentagem / 2)) {
			bar.replace(i, 1, ">");
		}
		else {
			bar.replace(i, 1, " ");
		}
	}

	cout << "\r" "Carregando " + FileName + " [" << bar << "] ";
	cout.width(3);
	cout << porcentagem << "%     " << std::flush;
}