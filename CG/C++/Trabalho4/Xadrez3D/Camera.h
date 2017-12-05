#pragma once
#include <glew.h>
#include <freeglut.h>
#include "Pecas\Types.h"
class Camera
{
private:
	const GLfloat P1 = 24.0f;
	const GLfloat P2 = -14.5f;
	GLfloat	Proporcao = 1.0f;
	bool Movimentar = false;
	GLfloat Z = P1;
public:
	Player PlayerSide = player1;

	Camera();
	~Camera();

	void AlternarCamera();
	void Atualizar();
	void Reshape(GLsizei width, GLsizei height);
};

