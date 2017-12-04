#pragma once
#include "Tuple3.h"
#include <iostream>
#include <string>
using namespace std;
class ModelDimensions
{
private:
	float leftPt;
	float rightPt;
	float topPt;
	float bottomPt; 
	float farPt;
	float nearPt;
public:
	ModelDimensions();
	void set(Tuple3 *vert);
	void update(Tuple3 *vert);
	float getWidth();
	float getHeight();
	float getDepth();
	float getLargest();
	Tuple3 *getCenter();
};

