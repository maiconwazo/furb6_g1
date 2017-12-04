#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Tuple3.h"
#include <stdio.h>
#include <sstream>
#include "Material.h"
using namespace std;
class Materials
{
private:
	const string MODEL_DIR = "";
	vector<Material*> materials;

	string renderMatName = "";
	bool usingTexture = false;
public:
	Materials();
	Materials(string mtlFnm);

	Tuple3 *readTuple3(string line);

	void readMaterials(ifstream *br);
	void renderWithMaterial(string faceMat);
	void switchOffTex();
	void setMaterialColors(string matName);
	string trim(string& str);
};

