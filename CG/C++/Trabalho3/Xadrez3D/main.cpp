#include <glew.h>
#include <freeglut.h>

const float C_BASE_X = 0.0f;
const float C_BASE_Y = 0.0f;
const float C_BASE_Z = 0.0f;
const float C_ALT_TAB = 0.6f + C_BASE_Y;
const float C_LADO_TAB_X = 9.0f + C_BASE_X;
const float C_LADO_TAB_Z = 9.0f + C_BASE_Z;

enum Player { player1, player2 };

Player playerAtual = player1;

GLfloat proporcao;

/* Definições de iluminação */
GLfloat whiteAmb[] = { 0.5f, 0.5f, 0.5f };
GLfloat whiteDif[] = { 1.0f, 1.0f, 1.0f };
GLfloat whiteSpe[] = { 0.5f, 0.5f, 0.5f };

GLfloat blackAmb[] = { 0.0f, 0.0f, 0.0f };
GLfloat blackDif[] = { 0.0f, 0.0f, 0.0f };
GLfloat blackSpe[] = { 0.0f, 0.0f, 0.0f };

GLfloat auxAmb[] = { 0.3f, 0.0f, 0.3f };
GLfloat auxDif[] = { 0.4f, 0.0f, 0.4f };
GLfloat auxSpe[] = { 0.4f, 0.0f, 0.4f };

GLfloat blueAmb[] = { 0.0f, 0.0f, 0.3f };
GLfloat blueDif[] = { 0.0f, 0.0f, 0.6f };
GLfloat blueSpe[] = { 0.0f, 0.0f, 0.4f };

GLfloat grayAmb[] = { 0.1f, 0.1f, 0.1f };
GLfloat grayDif[] = { 0.1f, 0.1f, 0.1f };
GLfloat graySpe[] = { 0.1f, 0.1f, 0.1f };

void desenhaTabuleiro() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, grayAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grayDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, graySpe);

	glBegin(GL_QUADS); // lado esquerdo
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // lado direito
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // lado de trás
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_BASE_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // lado da frente
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_LADO_TAB_Z);
	glEnd();

	glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpe);

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glEnd();

	glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blackDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blackSpe);

	float listraPreta = 0.2f;
	glBegin(GL_QUADS); // listra preta 
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X + listraPreta, C_ALT_TAB, C_BASE_Z + listraPreta);
	glVertex3f(C_BASE_X + listraPreta, C_ALT_TAB, C_LADO_TAB_Z - listraPreta);
	glVertex3f(C_LADO_TAB_X - listraPreta, C_ALT_TAB, C_LADO_TAB_Z - listraPreta);
	glVertex3f(C_LADO_TAB_X - listraPreta, C_ALT_TAB, C_BASE_Z + listraPreta);
	glEnd();

	glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpe);

	float listraBranca = 0.3f;
	glBegin(GL_QUADS); // listra branca 
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X + listraBranca, C_ALT_TAB, C_BASE_Z + listraBranca);
	glVertex3f(C_BASE_X + listraBranca, C_ALT_TAB, C_LADO_TAB_Z - listraBranca);
	glVertex3f(C_LADO_TAB_X - listraBranca, C_ALT_TAB, C_LADO_TAB_Z - listraBranca);
	glVertex3f(C_LADO_TAB_X - listraBranca, C_ALT_TAB, C_BASE_Z + listraBranca);
	glEnd();

	glMaterialfv(GL_FRONT, GL_AMBIENT, blueAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blueDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blueSpe);

	float listraAzul = 0.5f;
	glBegin(GL_QUADS); // listra azul
	glNormal3f(0.0f, C_ALT_TAB + 1.0f, 0.0f); //?
	glVertex3f(C_BASE_X + listraAzul, C_ALT_TAB, C_BASE_Z + listraAzul);
	glVertex3f(C_BASE_X + listraAzul, C_ALT_TAB, C_LADO_TAB_Z - listraAzul);
	glVertex3f(C_LADO_TAB_X - listraAzul, C_ALT_TAB, C_LADO_TAB_Z - listraAzul);
	glVertex3f(C_LADO_TAB_X - listraAzul, C_ALT_TAB, C_BASE_Z + listraAzul);
	glEnd();

	float bordaTotal = 0.6f;
	float xPeca = (C_LADO_TAB_X - bordaTotal * 2) / 8;
	float zPeca = (C_LADO_TAB_Z - bordaTotal * 2) / 8;
	bool black = false;
	bool troca = true;

	for (GLfloat X = 0; X < 8; X++) {
		for (GLfloat Z = 0; Z < 8; Z++) {
			if (troca) {
				black = !black;
			}
			else { troca = true; }

			glBegin(GL_QUADS);

			if ((X < 7) || (Z < 7)) {
				if (black)
				{
					glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmb);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, blackDif);
					glMaterialfv(GL_FRONT, GL_SPECULAR, blackSpe);
				}
				else
				{
					glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
					glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpe);
				}
			}
			else
			{
				glMaterialfv(GL_FRONT, GL_AMBIENT, auxAmb);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, auxDif);
				glMaterialfv(GL_FRONT, GL_SPECULAR, auxSpe);
			}

			glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
			glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB, (Z * xPeca) + bordaTotal);
			glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB, (Z * xPeca) + bordaTotal + zPeca);
			glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB, (Z * xPeca) + bordaTotal + zPeca);
			glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB, (Z * xPeca) + bordaTotal);
			glEnd();
		}

		troca = false;
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaTabuleiro();
	
	glutSwapBuffers();
}

void init(void)
{
	glClearColor(0.1f, 0.1f, 0.6f, 1.0f);

	GLfloat luzPos[] = { C_LADO_TAB_X / 2,  3.0f, C_LADO_TAB_Z / 2, 1.0f };
	GLfloat luzAmb[] = { 0.0f,  0.0f, 0.0f, 1.0f };
	GLfloat luzDif[] = { 1.0f,  1.0f, 1.0f, 1.0f };
	GLfloat luzSpe[] = { 0.0f,  0.0f, 0.0f, 1.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, luzPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT,  luzAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  luzDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzSpe);
}

void refreshCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50, proporcao, 0.1, 500);
	gluLookAt(	C_LADO_TAB_X / 2, C_ALT_TAB + 6.0f, (playerAtual == player1) ? C_LADO_TAB_Z + 8 : C_BASE_Z - 8,
				C_LADO_TAB_X / 2, C_ALT_TAB + 0.0f, C_LADO_TAB_Z / 2,
				0.0f, 1.0f, 0.0f);

	glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;
	glViewport(0, 0, width, height);
	proporcao = (GLfloat)width / (GLfloat)height;
	refreshCamera();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'q': playerAtual = player1;
		break;
	case 'w': playerAtual = player2;
		break;
	}

	refreshCamera();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Xadrez 3D");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	init();
	
	glutMainLoop();
	return 0;
}