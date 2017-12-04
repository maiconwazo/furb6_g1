#include "Tuple3.h"



Tuple3::Tuple3()
{
}

Tuple3::Tuple3(float xc, float yc, float zc)
{
	x = xc;
	y = yc;
	z = zc;
}

float Tuple3::getX()
{
	return x;
}

float Tuple3::getY()
{
	return y;
}

float Tuple3::getZ()
{
	return z;
}

void Tuple3::setX(float xc)
{
	x = xc;
}

void Tuple3::setY(float yc)
{
	y = yc;
}

void Tuple3::setZ(float zc)
{
	z = zc;
}

string Tuple3::toString()
{
	return "( " + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + " )";
}
