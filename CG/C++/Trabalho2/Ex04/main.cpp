#define _USE_MATH_DEFINES

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include <math.h>
#include <cmath>
#include <iostream>

double fPonto1, fPonto2 = 0.0;
double sPonto1 = 100.0, sPonto2 = 100.0;
double ang = 45;

double RetornaRaio(double x1, double y1) {
	double soma = 0.0;
	double v1, v2 = 0.0;
	if (fPonto1 < x1) {
		v1 = x1;
		v2 = fPonto1;
	}
	else if (fPonto1 > x1) {
		v1 = fPonto1;
		v2 = x1;
	}
	else {
		v1 = v2 = 0.0;
	}

	soma = pow(v1 - v2, 2) + pow(y1, 2);

	double result = sqrt(soma);
	return result;
}

double RetornaX(double angulo, double raio)
{
	return (raio * cos(M_PI * angulo / 180.0));
}

double RetornaY(double angulo, double raio)
{
	return (raio * sin(M_PI * angulo / 180.0));
}

void SRU() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glVertex2f(-200.0f, 0.0f);
	glVertex2f(200.0f, 0.0f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, -200.0f);
	glVertex2f(0.0f, 200.0f);
	glEnd();
}

void renderScene(void)
{
	int cont = 0;
	int rad = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.86f, 0.86f, 0.86f, 0.86f);
	gluOrtho2D(-400.0f, 400.0f, -400.0f, 400.0f);
	SRU();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glVertex2d(fPonto1, fPonto2);
	glVertex2d(sPonto1, sPonto2);
	glEnd();

	glFlush();
}

void keyPressed(unsigned char key, int x, int y) {
	double raio = 0.0;
	double d1 = 0.0;
	switch (key) {
	case 'q':
		if (fPonto1 > -200.0)
		{
			fPonto1 -= 10.0;
			sPonto1 -= 10.0;
			renderScene();
		}
		break;
	case 'w':
		if (fPonto1 < 200.0)
		{
			fPonto1 += 10.0;
			sPonto1 += 10.0;
			renderScene();
		}
		break;
	case 'a':
		raio = RetornaRaio(sPonto1, sPonto2) + 10;
		sPonto1 = RetornaX(ang, raio) + fPonto1;
		sPonto2 = RetornaY(ang, raio);
		renderScene();
		break;
	case 's':
		raio = RetornaRaio(sPonto1, sPonto2) - 10;
		sPonto1 = RetornaX(ang, raio) + fPonto1;
		sPonto2 = RetornaY(ang, raio);
		renderScene();
		break;
	case 'z':
		raio = RetornaRaio(sPonto1, sPonto2);
		ang += 10;
		sPonto1 = RetornaX(ang, raio) + fPonto1;
		sPonto2 = RetornaY(ang, raio);
		renderScene();
		break;
	case 'x':
		raio = RetornaRaio(sPonto1, sPonto2);
		ang -= 10;
		sPonto1 = RetornaX(ang, raio) + fPonto1;
		sPonto2 = RetornaY(ang, raio);
		renderScene();
		break;
	}
}

void reshape(int x, int y) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, x, y);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(700, 300);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL First Window");

	glutDisplayFunc(renderScene);
	glutKeyboardFunc(keyPressed);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}