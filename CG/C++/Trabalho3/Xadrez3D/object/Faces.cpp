#include "Faces.h"

Faces::Faces()
{
}

Faces::Faces(vector<Tuple3*> *vs, vector<Tuple3*> *ns, vector<Tuple3*> *ts)
{
	verts = vs;
	normals = ns;
	texCoords = ts;
}

bool Faces::addFace(string line)
{
	try {
		line = line.substr(2);
		Tokenizer stc(line, " ");
		string token;
		int numTokens = 0;
		while ((token = stc.next()) != "")
		{
			numTokens++;
		}
		Tokenizer st(line, " ");

		vector<int> v;
		vector<int> vt;
		vector<int> vn;

		for (int i = 0; i < numTokens; i++) {
			string faceToken = addFaceVals(st.next());

			int numSeps = 0;
			Tokenizer st2c(faceToken, "/");
			while ((token = st2c.next()) != "")
			{
				numSeps++;
			}

			Tokenizer st2(faceToken, "/");
			v.push_back(stoi(st2.next()));
			vt.push_back((numSeps > 1) ? stoi(st2.next()) : 0);
			vn.push_back((numSeps > 2) ? stoi(st2.next()) : 0);
		}
		// store the indicies for this face
		facesVertIdxs.push_back(v);
		facesTexIdxs.push_back(vt);
		facesNormIdxs.push_back(vn);
	}
	catch (exception e) {
		cout << "Incorrect face index";
		cout << e.what();
		return false;
	}
	return true;
}

string Faces::addFaceVals(string faceStr)
{
	string sb;
	string prevCh = "x";
	for (int k = 0; k < faceStr.size(); k++) {
		if (faceStr.at(k) == '/' && prevCh == "/") {
			sb.append("0");
		}
		prevCh = faceStr.at(k);
		sb.append(prevCh);
	}
	return sb;
}

void Faces::renderFace(int i)
{
	if (i >= facesVertIdxs.size()) {
		return;
	}
	vector<int> vertIdxs = facesVertIdxs.at(i);
	int polytype;
	if (vertIdxs.size() == 3) {
		polytype = GL_TRIANGLES;
	}
	else if (vertIdxs.size() == 4) {
		polytype = GL_QUADS;
	}
	else {
		polytype = GL_POLYGON;
	}
	glBegin(polytype);

	vector<int> normIdxs = facesNormIdxs.at(i);
	vector<int> texIdxs = facesTexIdxs.at(i);

	Tuple3 *vert;
	Tuple3 *norm;
	Tuple3 *texCoord;
	for (int f = 0; f < vertIdxs.size(); f++) {

		if (normIdxs.at(f) != 0) {
			norm = normals->at(normIdxs.at(f) - 1);
			glNormal3f(norm->getX(), norm->getY(), norm->getZ());
		}

		if (texIdxs.at(f) != 0) {
			texCoord = texCoords->at(texIdxs.at(f) - 1);
			if (texCoord->getZ() == DUMMY_Z_TC) {
				glTexCoord2f(texCoord->getX(), texCoord->getY());
			}
			else {
				glTexCoord3f(texCoord->getX(), texCoord->getY(), texCoord->getZ());
			}
		}

		vert = verts->at(vertIdxs[f] - 1);
		glVertex3f(vert->getX(), vert->getY(), vert->getZ());
	}

	glEnd();
}

int Faces::getNumFaces()
{
	return facesVertIdxs.size();
}
