#pragma once
#include "Pecas\Consts.h"
#include <glew.h>
#include <freeglut.h>
#include <vector>
#include "loadObj\OBJModel.h"
#include "Jogo.h"
#include "Camera.h"
using namespace std;
class Mundo
{
public:
	Jogo *JogoObj;
	Camera *CameraObj;

	Mundo();
	~Mundo();

	void Desenhar();
};

