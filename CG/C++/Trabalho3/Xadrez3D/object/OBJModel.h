#pragma once
#include <vector>
#include "FaceMaterials.h"
#include "Tuple3.h"
#include "Faces.h"
#include "Materials.h"
#include "ModelDimensions.h"
#include <glew.h>
using namespace std;

class OBJModel
{
private:
	const float DUMMY_Z_TC = -5.0F;
	vector<Tuple3*> *verts;
	vector<Tuple3*> *normals;
	vector<Tuple3*> *texCoords;
	bool hasTCs3D = true;

	Faces *faces;
	FaceMaterials *faceMats; 
	Materials *materials;
	ModelDimensions *modelDims;
	string modelNm;
	float maxSize;
	int modelDispList; 
public:
	OBJModel();
	OBJModel(string nm, float sz, bool showDetails);
	void initModelData(string modelNm);
	void loadModel(string modelNm);
	void readModel(ifstream *br);
	bool addVert(string line, bool isFirstCoord);
	Tuple3 *readTuple3(string line);
	bool addTexCoord(string line, bool isFirstTC);
	bool checkTC3D(string line);
	Tuple3 *readTCTuple(string line);
	bool addNormal(string line);
	void centerScale();
	void drawToList();
	void draw();
	void reportOnModel();
	string trim(string& str);
};

