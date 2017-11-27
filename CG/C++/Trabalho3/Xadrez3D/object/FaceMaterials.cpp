#include "FaceMaterials.h"



FaceMaterials::FaceMaterials()
{
}

void FaceMaterials::addUse(int faceIdx, string matName)
{
	if (faceMats.find(faceIdx) != faceMats.end()) {
		// face index already present
		cout << "Face index " << to_string(faceIdx) << " changed to use material " << matName;
	}
	faceMats[faceIdx] = matName;

	// store how many times matName has been used by faces
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

void FaceMaterials::showUsedMaterials()
{
	cout << "No. of materials used: " + to_string(matCount.size());

	set<string> keys;
	for (map<string, int>::iterator it = matCount.begin(); it != matCount.end(); ++it) {
		keys.insert(it->first);
	}

	int count;
	for (string matName : keys) {
		count = matCount[matName];

		cout << matName + ": " + to_string(count);
	}
}
