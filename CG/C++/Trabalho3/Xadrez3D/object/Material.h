#pragma once
#include <string>
#include "Tuple3.h"
#include <iostream>
#include <glew.h>
using namespace std;
class Material
{
private:
	string name;

	Tuple3 *ka;
	Tuple3 *kd;
	Tuple3 *ks; 
	float ns;
	float d;
					
	string *texFnm;
public:
	Material(string nm);
	void showMaterial();
	bool hasName(string nm);
	void setMaterialColors();

	float getD();
	float getNs();
	Tuple3 *getKa();
	Tuple3 *getKd();
	Tuple3 *getKs();

	void setD(float val);
	void setNs(float val);
	void setKa(Tuple3 *t);
	void setKd(Tuple3 *t);
	void setKs(Tuple3 *t);
};

