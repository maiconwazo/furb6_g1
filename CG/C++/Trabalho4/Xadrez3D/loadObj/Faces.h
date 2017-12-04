#pragma once
#include <vector>
#include "Tuple3.h"
#include <iostream>
#include <glew.h>
#include "Tokenizer.h"
using namespace std;
class Faces
{
private:
	const float DUMMY_Z_TC = -5.0F;

	vector<vector<int>> facesVertIdxs;
	vector<vector<int>> facesTexIdxs;
	vector<vector<int>> facesNormIdxs;

	vector<Tuple3*> *verts;
	vector<Tuple3*> *normals;
	vector<Tuple3*> *texCoords;
public:
	Faces();
	Faces(vector<Tuple3*> *vs, vector<Tuple3*> *ns, vector<Tuple3*> *ts);
	bool addFace(string line);
	string addFaceVals(string faceStr);
	void renderFace(int i);
	int getNumFaces();
};

