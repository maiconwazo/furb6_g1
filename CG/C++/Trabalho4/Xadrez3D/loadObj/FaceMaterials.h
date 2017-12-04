#pragma once
#include <map>
#include <iostream>
#include <string>
#include <set>
using namespace std;

class FaceMaterials
{
private:
	map<int, std::string> faceMats;
	map<std::string, int> matCount;

public:
	FaceMaterials();

	void addUse(int faceIdx, string matName);
	string findMaterial(int faceIdx);
	void showUsedMaterials();
};

