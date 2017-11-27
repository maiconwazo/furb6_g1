#include "ModelDimensions.h"

ModelDimensions::ModelDimensions()
{
	leftPt = 0.0f;
	rightPt = 0.0f;
	topPt = 0.0f;
	bottomPt = 0.0f;
	farPt = 0.0f;
	nearPt = 0.0f;
}

void ModelDimensions::set(Tuple3 *vert)
{
	rightPt = vert->getX();
	leftPt = vert->getX();

	topPt = vert->getY();
	bottomPt = vert->getY();

	nearPt = vert->getZ();
	farPt = vert->getZ();
}

void ModelDimensions::update(Tuple3 *vert)
{
	if (vert->getX() > rightPt) {
		rightPt = vert->getX();
	}
	if (vert->getX() < leftPt) {
		leftPt = vert->getX();
	}
	if (vert->getY() > topPt) {
		topPt = vert->getY();
	}
	if (vert->getY() < bottomPt) {
		bottomPt = vert->getY();
	}
	if (vert->getZ() > nearPt) {
		nearPt = vert->getZ();
	}
	if (vert->getZ() < farPt) {
		farPt = vert->getZ();
	}
}

float ModelDimensions::getWidth()
{
	return rightPt - leftPt;
}

float ModelDimensions::getHeight()
{
	return topPt - bottomPt;
}

float ModelDimensions::getDepth()
{
	return nearPt - farPt;
}

float ModelDimensions::getLargest()
{
	float height = getHeight();
	float depth = getDepth();

	float largest = getWidth();
	if (height > largest) {
		largest = height;
	}
	if (depth > largest) {
		largest = depth;
	}
	return largest;
}

Tuple3 *ModelDimensions::getCenter()
{
	float xc = (rightPt + leftPt) / 2.0f;
	float yc = (topPt + bottomPt) / 2.0f;
	float zc = (nearPt + farPt) / 2.0f;
	return new Tuple3(xc, yc, zc);
}

void ModelDimensions::reportDimensions()
{
	Tuple3 *center = getCenter();

	cout << "x Coords: " + to_string(leftPt) + " to " + to_string(rightPt);
	cout << "  Mid: " + to_string(center->getX()) + "; Width: " + to_string(getWidth());

	cout << "y Coords: " + to_string(bottomPt) + " to " + to_string(topPt);
	cout << "  Mid: " + to_string(center->getY()) + "; Height: " + to_string(getHeight());

	cout << "z Coords: " + to_string(nearPt) + " to " + to_string(farPt);
	cout << "  Mid: " + to_string(center->getZ()) + "; Depth: " + to_string(getDepth());
}
