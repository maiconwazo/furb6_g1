#include "Mundo.h"

Mundo::Mundo()
{
	glClearColor(C_COR_FUNDO[0], C_COR_FUNDO[1], C_COR_FUNDO[2], C_COR_FUNDO[3]);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	/* Luz */
	GLfloat luzPos[] = { 6.0f,  6.0f, 6.0f, 1.0f };
	GLfloat luzAmb[] = { 0.3f,  0.3f, 0.3f, 1.0f };
	GLfloat luzDif[] = { 0.8f,  0.8f, 0.8f, 1.0f };
	GLfloat luzSpe[] = { 0.3f,  0.3f, 0.3f, 0.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, luzPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzSpe);
	/* */

	CameraObj = new Camera();
	JogoObj = new Jogo();
}


Mundo::~Mundo()
{
}

void Mundo::Desenhar()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	CameraObj->Atualizar();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	JogoObj->DesenharJogo();
	glutSwapBuffers();
}
