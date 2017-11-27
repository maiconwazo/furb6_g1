#pragma once
#include <string>

using namespace std;

class Tuple3
{
private:
	float x, y, z;
public:
	Tuple3();
	Tuple3(float xc, float yc, float zc);

	float getX();
	float getY();
	float getZ();
	void setX(float xc);
	void setY(float yc);
	void setZ(float zc);
	string toString();
};

