#include <glew.h>
#include <freeglut.h>

const float C_BASE_X = 0.0f;
const float C_BASE_Y = 0.0f;
const float C_BASE_Z = 0.0f;
const float C_ALT_TAB = 0.3f + C_BASE_Y;
const float C_LADO_TAB_X = 9.0f + C_BASE_X;
const float C_LADO_TAB_Z = 9.0f + C_BASE_Z;
const GLfloat C_COR_FUNDO[] = { 0.2f, 0.2f, 0.5f, 1.0f };

/* Definições de iluminação */
const GLfloat whiteAmb[] = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat whiteDif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat whiteSpe[] = { 0.5f, 0.5f, 0.5f, 1.0f };

const GLfloat blackAmb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat blackDif[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat blackSpe[] = { 0.3f, 0.3f, 0.3f, 1.0f };

const GLfloat purpleAmb[] = { 0.3f, 0.0f, 0.3f, 1.0f };
const GLfloat purpleDif[] = { 0.3f, 0.0f, 0.3f, 1.0f };
const GLfloat purpleSpe[] = { 0.3f, 0.0f, 0.3f, 1.0f };

const GLfloat blueAmb[] = { 0.0f, 0.0f, 0.3f, 1.0f };
const GLfloat blueDif[] = { 0.0f, 0.0f, 0.6f, 1.0f };
const GLfloat blueSpe[] = { 0.0f, 0.0f, 0.4f, 1.0f };

const GLfloat grayAmb[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat grayDif[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat graySpe[] = { 0.1f, 0.1f, 0.1f, 1.0f };

const GLfloat brownAmb[] = { 0.3f, 0.0f, 0.0f, 1.0f };
const GLfloat brownDif[] = { 0.6f, 0.0f, 0.0f, 1.0f };
const GLfloat brownSpe[] = { 0.3f, 0.0f, 0.0f, 1.0f };

const GLfloat blackChessAmb[] = { 0.16f, 0.06f, 0.05f, 1.0f };
const GLfloat blackChessDif[] = { 0.33f, 0.12f, 0.10f, 1.0f };
const GLfloat blackChessSpe[] = { 0.16f, 0.06f, 0.05f, 1.0f };

const GLfloat whiteChessAmb[] = { 0.5f, 0.45f, 0.30f, 1.0f };
const GLfloat whiteChessDif[] = { 1.0f, 0.90f, 0.60f, 1.0f };
const GLfloat whiteChessSpe[] = { 0.5f, 0.45f, 0.30f, 1.0f };

const GLfloat blueTranspAmb[] = { 0.0f, 0.0f, 0.6f, 0.4f };
const GLfloat blueTranspDif[] = { 0.0f, 0.0f, 0.8f, 0.4f };
const GLfloat blueTranspSpe[] = { 0.0f, 0.0f, 0.7f, 0.4f };

const GLfloat darkBlueTranspAmb[] = { 0.0f, 0.0f, 0.1f, 0.6f };
const GLfloat darkBlueTranspDif[] = { 0.0f, 0.0f, 0.3f, 0.6f };
const GLfloat darkBlueTranspSpe[] = { 0.0f, 0.0f, 0.1f, 0.6f };

enum Player { player1, player2 };
enum Color { white, black, blue, gray, brown, purple, blackChess, whiteChess, blueTransp, darkBlueTransp };
GLfloat proporcao;

Player playerAtual = player1;
Player playerJogando = player1;

float xPeca, zPeca, basePeca;
float matrizPosPecas[8][8][2];
int matrizTabuleiro[8][8] = {
	{ 7, 7, 7, 7, 7, 7, 7, 7 },
	{ 7, 7, 7, 7, 7, 7, 7, 7 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 }
};

int pecaAtual[] = { 0, 7 };
bool modoMovPeca = false;

void desenharPeao(int xCoord, int zCoord) {
	glPushMatrix();
	glTranslatef(matrizPosPecas[xCoord][zCoord][0], C_ALT_TAB, matrizPosPecas[xCoord][zCoord][1]);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(basePeca, 1.0f, 50, 50); 
	glPopMatrix();
}

void configureColor(Color c) {
	switch (c) {
	case white:
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpe);
		break;
	case black:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blackDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blackSpe);
		break;
	case blue:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blueAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blueDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blueSpe);
		break;
	case gray:
		glMaterialfv(GL_FRONT, GL_AMBIENT, grayAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, grayDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, graySpe);
		break;
	case brown:
		glMaterialfv(GL_FRONT, GL_AMBIENT, brownAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brownDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, brownSpe);
		break;
	case purple:
		glMaterialfv(GL_FRONT, GL_AMBIENT, purpleAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purpleDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, purpleSpe);
		break;
	case blackChess:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackChessAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blackChessDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blackChessSpe);
		break;
	case whiteChess:
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteChessAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteChessDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteChessSpe);
		break;
	case blueTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blueTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blueTranspDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blueTranspSpe);
		break;
	case darkBlueTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, darkBlueTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, darkBlueTranspDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, darkBlueTranspSpe);
		break;
	}
}

void desenhaTabuleiro() {
	configureColor(gray);

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

	configureColor(white);

	float bordaTotal = 0.6f;

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z + bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z + bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z - bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z - bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glEnd();

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X + bordaTotal, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X + bordaTotal, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glEnd();

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X - bordaTotal, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X - bordaTotal, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glEnd();

	bool useBlack = false;
	bool troca = true;

	xPeca = (C_LADO_TAB_X - bordaTotal * 2) / 8;
	zPeca = (C_LADO_TAB_Z - bordaTotal * 2) / 8;
	basePeca = (xPeca > zPeca) ? zPeca / 3 : xPeca / 3;

	for (int X = 0; X < 8; X++) {
		for (int Z = 0; Z < 8; Z++) {
			if (troca) {
				useBlack = !useBlack;
			}
			else { troca = true; }

			glBegin(GL_QUADS);
			configureColor(useBlack ? blackChess : whiteChess);
			glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
			glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB,			(Z * xPeca) + bordaTotal);
			glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB,			(Z * xPeca) + bordaTotal + zPeca);
			glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB, (Z * xPeca) + bordaTotal + zPeca);
			glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB, (Z * xPeca) + bordaTotal);
			glEnd();

			matrizPosPecas[X][Z][0] = ((Z * xPeca) + bordaTotal) + (zPeca / 2);
			matrizPosPecas[X][Z][1] = ((X * xPeca) + bordaTotal) + (xPeca / 2);

			if ((playerAtual == playerJogando) && (X == pecaAtual[0]) && (Z == pecaAtual[1])) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBegin(GL_QUADS);
				configureColor(blueTransp);
				glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
				glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal);
				glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal + zPeca);
				configureColor(darkBlueTransp);
				glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal + zPeca);
				glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal);
				glEnd();
				glEnable(GL_BLEND);
			}
		}
		troca = false;
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	configureColor(brown);
	glBegin(GL_QUADS);
	float x = 1.0f, z = 1.5f;
	glNormal3f(0.0f, C_ALT_TAB + 1, 0.0f); //?
	glVertex3f(C_BASE_X - x,		C_BASE_Y,	C_BASE_Z - z		);
	glVertex3f(C_BASE_X - x,		C_BASE_Y,	C_LADO_TAB_Z + z	);
	glVertex3f(C_LADO_TAB_X + x,	C_BASE_Y,	C_LADO_TAB_Z + z	);
	glVertex3f(C_LADO_TAB_X + x,	C_BASE_Y,	C_BASE_Z - z		);
	glEnd;

	desenhaTabuleiro();

	for (int x = 0; x < 8; x++) {
		for (int z = 0; z < 8; z++) {
			if (matrizTabuleiro[x][z] < 6)
				configureColor(white);
			else
				configureColor(black);

			switch (matrizTabuleiro[x][z]) {
			case 1: desenharPeao(x, z); 
				break;
			case 7: desenharPeao(x, z);
				break;
			}			
		}
	}

	glutSwapBuffers();
}

void init(void)
{
	glClearColor(C_COR_FUNDO[0], C_COR_FUNDO[1], C_COR_FUNDO[2], C_COR_FUNDO[3]);
	glEnable(GL_DEPTH_TEST);

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
	case 'a': playerJogando = player1;
		break;
	case 's': playerJogando = player2;
		break;
	case 32: modoMovPeca = !modoMovPeca;
		break;
	}

	display;
	refreshCamera();
}

void keyboardSpecial(int key, int x, int y) {
		switch (key)
		{
		case GLUT_KEY_LEFT: 
			if ((playerAtual == player1) && (pecaAtual[0] > 0)) pecaAtual[0]--;
			else if ((playerAtual == player2) && (pecaAtual[0] < 8)) pecaAtual[0]++;
			break;
		case GLUT_KEY_RIGHT: 
			if ((playerAtual == player1) && (pecaAtual[0] < 7)) pecaAtual[0]++;
			else if ((playerAtual == player2) && (pecaAtual[0] > 0)) pecaAtual[0]--;
			break;
		case GLUT_KEY_UP: 
			if ((playerAtual == player1) && (pecaAtual[1] > 0)) pecaAtual[1]--;
			else if ((playerAtual == player2) && (pecaAtual[1] < 8)) pecaAtual[1]++;
			break;
		case GLUT_KEY_DOWN: 
			if ((playerAtual == player1) && (pecaAtual[1] < 7)) pecaAtual[1]++;
			else if ((playerAtual == player2) && (pecaAtual[1] > 0)) pecaAtual[1]--;
			break;
		}

	display;
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
	glutSpecialFunc(keyboardSpecial);
	init();
	
	glutMainLoop();
	return 0;
}