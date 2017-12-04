#pragma once
#include <glew.h>
#include <freeglut.h>
#include "Pecas\Types.h"
class Camera
{
private:
	GLfloat	Proporcao = 1.0f;
public:
	Player PlayerSide = player1;

	Camera();
	~Camera();

	void AlternarCamera(Player playerSide);
	void Atualizar();
	void Reshape(GLsizei width, GLsizei height);
};

