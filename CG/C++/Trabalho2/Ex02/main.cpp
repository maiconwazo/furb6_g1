#define _USE_MATH_DEFINES

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include <math.h>
#include <cmath>
#include <iostream>

double valorX1 = 400.0;
double valorY1 = 400.0;
double valorX2 = 400.0;
double valorY2 = 400.0;

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
	gluOrtho2D(-valorX1, valorY1, -valorX2, valorY2);
	SRU();

	glColor3f(0.0f, 0.0f, 1.0f);
	glPointSize(2.0f);
	glLineWidth(3.0f);
	glBegin(GL_POINTS);
	while (cont != 72) {
		glVertex2d(RetornaX(rad, 100), RetornaY(rad, 100));
		cont++;
		rad = rad + 6;
	}
	glEnd();
	glFlush();
}

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'z':
		if (valorX1 > 100) {
			valorX1 -= 10.0;
			valorY1 -= 10.0;
			valorX2 -= 10.0;
			valorY2 -= 10.0;
			renderScene();
		}
		break;
	case 'x':
		if (valorY1 < 600) {
			valorX1 += 10.0;
			valorY1 += 10.0;
			valorX2 += 10.0;
			valorY2 += 10.0;
			renderScene();
		}
		break;
	case 'a':
		if (valorY1 < 600) {
			valorX1 -= 10.0;
			valorY1 += 10.0;
			renderScene();
		}
		break;
	case 'd':
		if (valorY1 > 200) {
			valorX1 += 10.0;
			valorY1 -= 10.0;
			renderScene();
		}
		break;
	case 'w':
		if (valorY2 > 200) {
			valorX2 += 10.0;
			valorY2 -= 10.0;
			renderScene();
		}
		break;
	case 's':
		if (valorY2 < 600) {
			valorX2 -= 10.0;
			valorY2 += 10.0;
			renderScene();
		}
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
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL First Window");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();

	return 0;
}