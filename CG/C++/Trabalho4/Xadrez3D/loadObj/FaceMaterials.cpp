#include "FaceMaterials.h"



FaceMaterials::FaceMaterials()
{
}

void FaceMaterials::addUse(int faceIdx, string matName)
{
	faceMats[faceIdx] = matName;

	if (matCount.find(matName) != matCount.end()) {
		int i = matCount[matName] + 1;
		matCount[matName] = i;
	}
	else {
		matCount[matName] = 1;
	}
}

string FaceMaterials::findMaterial(int faceIdx)
{
	return faceMats[faceIdx];
}