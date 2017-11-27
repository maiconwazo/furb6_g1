#include "Materials.h"

Materials::Materials()
{
}

Materials::Materials(string mtlFnm)
{
	string mfnm = "data/" + MODEL_DIR + mtlFnm;
	try {
		cout << "Loading material from " + mfnm;
		ifstream br;
		br.open(mfnm);
		readMaterials(&br);
		br.close();
	}
	catch (exception e) {
		cout << e.what();
	}
}

Tuple3 *Materials::readTuple3(string line)
{
	std::istringstream iss(line);
	string xs, ys, zs;
	try {
		getline(iss, xs, ' ');
		getline(iss, ys, ' ');
		getline(iss, zs, ' ');

		float x = strtof(xs.c_str(), 0);
		float y = strtof(ys.c_str(), 0);
		float z = strtof(zs.c_str(), 0);

		Tuple3 *t = new Tuple3(x, y, z);
		return t;
	}
	catch (exception e) {
		cout << e.what();
	}

	return nullptr;
}

void Materials::readMaterials(ifstream *br)
{
	try {
		string line;
		Material *currMaterial = nullptr;
		while (br->good()) {
			line = br->get();
			line = trim(line);
			if (line.length() == 0) {
				continue;
			}
			if (line.find("newmtl ") == 0) {
				if (currMaterial != nullptr) {
					materials.push_back(currMaterial);
				}
				currMaterial = new Material(line.substr(7));
			}
			else if (line.find("map_Kd ") == 0) {

			}
			else if (line.find("Ka ") == 0) {
				currMaterial->setKa(readTuple3(line));
			}
			else if (line.find("Kd ") == 0) {
				currMaterial->setKd(readTuple3(line));
			}
			else if (line.find("Ks ") == 0) {
				currMaterial->setKs(readTuple3(line));
			}
			else if (line.find("Ns ") == 0) {
				float val = strtof(line.substr(3).c_str(), 0);
				currMaterial->setNs(val);
			}
			else if (line.at(0) == 'd') {
				float val = strtof(line.substr(2).c_str(), 0);
				currMaterial->setD(val);
			}
			else if (line.find("illum ") == 0) {

			}
			else if (line.at(0) == '#') {
				continue;
			}
			else {
				cout << "Ignoring MTL line: " + line;
			}
		}
		materials.push_back(currMaterial);
	}
	catch (exception e) {
		cout << e.what();
	}
}

void Materials::showMaterials()
{
	cout << "No. of materials: " + to_string(materials.size());
	Material *m;
	for (int i = 0; i < materials.size(); i++) {
		m = materials.at(i);
		m->showMaterial();
	}
}

void Materials::renderWithMaterial(string faceMat)
{
	if (faceMat != (renderMatName)) {
		renderMatName = faceMat;
		switchOffTex();
		setMaterialColors(renderMatName);
	}
}

void Materials::switchOffTex()
{
	if (usingTexture) {
		glDisable(GL_TEXTURE_2D);
		usingTexture = false;
		glEnable(GL_LIGHTING);
	}
}

void Materials::setMaterialColors(string matName)
{
	Material *m;
	for (int i = 0; i < materials.size(); i++) {
		m = materials.at(i);
		if (m->hasName(matName)) {
			m->setMaterialColors();
		}
	}
}

string Materials::trim(string & str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == string::npos)
		return "";
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}
