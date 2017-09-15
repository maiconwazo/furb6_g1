#define _USE_MATH_DEFINES

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include <math.h>
#include <cmath>
#include <iostream>

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
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}