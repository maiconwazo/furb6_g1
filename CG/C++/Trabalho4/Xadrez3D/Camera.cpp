#include "Camera.h"
#include <iostream>

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::AlternarCamera(Player playerSide)
{
	PlayerSide = playerSide;
}

void Camera::Atualizar()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50.0f, Proporcao, 0.1f, 500.0f);
	gluLookAt(6.0f,10.0f, PlayerSide == player1 ? 25.0f : -13.0f,
			  6.0f, 0.0f, 6.0f,
			  0.0f, 1.0f, 0.0f);

	glutPostRedisplay();
}

void Camera::Reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;
	glViewport(0, 0, width, height);
	Proporcao = (GLfloat)width / (GLfloat)height;
	Atualizar();
}
