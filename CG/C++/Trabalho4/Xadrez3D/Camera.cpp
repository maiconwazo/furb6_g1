#include "Camera.h"
#include <iostream>

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::AlternarCamera()
{
	PlayerSide = PlayerSide == player1 ? player2 : player1;
	Movimentar = true;
}

void Camera::Atualizar()
{
	float x = 5.5f;
	float p = 1;
	if (Movimentar)
	{
		switch (PlayerSide)
		{
		case player1:
			Z = Z + abs(P1 - P2) / 100;
			p = abs(P2 - Z) / abs(P1 - P2);
			if (p < 0.5)
				x = x + (-19.0f * p * 2);
			else
			{
				x = x + (-19.0f * (0.5 - (p - 0.5)) * 2);
			}

			if (Z > P1)
			{
				Z = P1;
				Movimentar = false;
			}
			break;
		case player2:
			Z = Z - abs(P1 - P2) / 100;
			p = abs(P1 - Z) / abs(P1 - P2);
			if (p < 0.5)
				x = x + (19.0f * p*2);
			else
			{
				x = x + (19.0f * (0.5 - (p - 0.5)) * 2);
			}

			if (Z < P2)
			{
				Z = P2;
				Movimentar = false;
			}
			break;
		}
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50.0f, Proporcao, 10.0f, 500.0f);
	gluLookAt(x,10.0f, Z,
			  5.5f, 0.0f, 5.5f,
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
