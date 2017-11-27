#pragma comment(lib, "glew32.lib")
#include <vector>
#include <glm.hpp>
#include <glew.h>
#include <freeglut.h>
#include <iostream>    
#include <fstream>     
#include <string>
#include <sstream>
#include <ctime>
#include <windows.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include "object\OBJModel.h"


using namespace std;

const GLfloat C_BASE_X = 0.0f;
const GLfloat C_BASE_Y = 0.0f;
const GLfloat C_BASE_Z = 0.0f;
const GLfloat C_ALT_TAB = 0.3f + C_BASE_Y;
const GLfloat C_LADO_TAB_X = 9.0f + C_BASE_X;
const GLfloat C_LADO_TAB_Z = 9.0f + C_BASE_Z;
const GLfloat C_COR_FUNDO[] = { 0.2f, 0.2f, 0.5f, 1.0f };

/* Definições de iluminação */
const GLfloat whiteAmb[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat whiteDif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat whiteSpe[] = { 0.6f, 0.6f, 0.6f, 1.0f };

const GLfloat blackAmb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat blackDif[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat blackSpe[] = { 0.1f, 0.1f, 0.1f, 1.0f };

const GLfloat purpleAmb[] = { 0.3f, 0.0f, 0.3f, 1.0f };
const GLfloat purpleDif[] = { 0.3f, 0.0f, 0.3f, 1.0f };
const GLfloat purpleSpe[] = { 0.2f, 0.0f, 0.2f, 1.0f };

const GLfloat blueAmb[] = { 0.0f, 0.0f, 0.3f, 1.0f };
const GLfloat blueDif[] = { 0.0f, 0.0f, 0.6f, 1.0f };
const GLfloat blueSpe[] = { 0.0f, 0.0f, 0.4f, 1.0f };

const GLfloat grayAmb[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat grayDif[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat graySpe[] = { 0.1f, 0.1f, 0.1f, 1.0f };

const GLfloat brownAmb[] = { 0.2f, 0.0f, 0.0f, 1.0f };
const GLfloat brownDif[] = { 0.9f, 0.0f, 0.0f, 1.0f };
const GLfloat brownSpe[] = { 0.4f, 0.0f, 0.0f, 1.0f };

const GLfloat blackChessAmb[] = { 0.16f, 0.06f, 0.05f, 1.0f };
const GLfloat blackChessDif[] = { 0.33f, 0.12f, 0.10f, 1.0f };
const GLfloat blackChessSpe[] = { 0.10f, 0.02f, 0.02f, 1.0f };

const GLfloat whiteChessAmb[] = { 0.5f, 0.45f, 0.30f, 1.0f };
const GLfloat whiteChessDif[] = { 1.0f, 0.90f, 0.60f, 1.0f };
const GLfloat whiteChessSpe[] = { 0.3f, 0.25f, 0.10f, 1.0f };

const GLfloat blueTranspAmb[] = { 0.0f, 0.0f, 0.6f, 0.4f };
const GLfloat blueTranspDif[] = { 0.0f, 0.0f, 0.8f, 0.4f };
const GLfloat blueTranspSpe[] = { 0.0f, 0.0f, 0.5f, 0.4f };

const GLfloat darkBlueTranspAmb[] = { 0.0f, 0.0f, 0.1f, 0.6f };
const GLfloat darkBlueTranspDif[] = { 0.0f, 0.0f, 0.3f, 0.6f };
const GLfloat darkBlueTranspSpe[] = { 0.0f, 0.0f, 0.1f, 0.6f };

const GLfloat redTranspAmb[] = { 0.8f, 0.0f, 0.8f, 0.6f };
const GLfloat redTranspDif[] = { 1.0f, 0.0f, 1.0f, 0.6f };
const GLfloat redTranspSpe[] = { 0.6f, 0.0f, 0.6f, 0.6f };

const GLfloat darkRedTranspAmb[] = { 0.1f, 0.0f, 0.1f, 0.8f };
const GLfloat darkRedTranspDif[] = { 0.3f, 0.0f, 0.3f, 0.8f };
const GLfloat darkRedTranspSpe[] = { 0.1f, 0.0f, 0.1f, 0.8f };

enum Player { player1, player2 };
enum Color { white, black, blue, gray, brown, purple, blackChess, whiteChess, blueTransp, darkBlueTransp, redTransp, darkRedTransp };
enum Peca { nenhum, peao1, torre1, cavalo1, bispo1, rainha1, rei1, peao2, torre2, cavalo2, bispo2, rainha2, rei2 };
GLfloat proporcao;

Player playerAtual = player1;
Player playerJogando = player1;
vector<OBJModel*> *loader;

int quadradoAtual[] = { 0, 7 };
bool modoMovPeca = false;
GLfloat xPeca, zPeca, basePeca;
Peca cemiterio1[16] = {}, cemiterio2[16] = {};

std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
std::vector< glm::vec3 > temp_vertices;
std::vector< glm::vec2 > temp_uvs;
std::vector< glm::vec3 > temp_normals;

float cemiterioPos1[16][2] = {
	{  9.7f,  8.1f },
	{ 10.3f,  7.5f },
	{  9.7f,  7.2f },
	{  9.8f,  6.5f },
	{ 10.4f,  6.0f },
	{ 10.3f,  5.4f },
	{  9.6f,  5.1f },
	{ 10.2f,  4.5f },
	{  9.7f,  3.9f },
	{ 10.3f,  3.4f },
	{ 10.1f,  2.8f },
	{ 10.3f,  2.2f },
	{  9.7f,  2.1f },
	{ 10.3f,  1.4f },
	{  9.8f,  0.7f },
	{ 10.4f,  0.0f }
};

float cemiterioPos2[16][2] = {
	{ -0.6f,  0.0f },
	{ -1.2f,  0.7f },
	{ -0.7f,  1.4f },
	{ -1.3f,  2.1f },
	{ -0.7f,  2.2f },
	{ -0.9f,  2.8f },
	{ -0.7f,  3.4f },
	{ -1.3f,  3.9f },
	{ -0.8f,  4.5f },
	{ -1.6f,  5.1f },
	{ -0.7f,  5.4f },
	{ -0.6f,  6.0f },
	{ -1.3f,  6.5f },
	{ -1.3f,  7.2f },
	{ -0.7f,  7.5f },
	{ -1.3f,  8.1f }
};

float matrizPosPecas[8][8][2];
int matrizTabuleiro[8][8] = {
	{ 8, 9,10,11,12,10, 9, 8 },
	{ 7, 7, 7, 7, 7, 7, 7, 7 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 2, 3, 4, 5, 6, 4, 3, 2 }
};

bool bLoaded;
int iAttrBitField;
int iNumFaces;

struct pecaSelecionada {
	Peca tipo;
	int X;
	int Z;
} pecaSelecionada;

Peca retornaPecaXZ(int X, int Z) {
	return Peca(matrizTabuleiro[Z][X]);
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
	case redTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, redTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, redTranspAmb);
		glMaterialfv(GL_FRONT, GL_SPECULAR, redTranspAmb);
		break;
	case darkRedTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, darkRedTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, darkRedTranspAmb);
		glMaterialfv(GL_FRONT, GL_SPECULAR, darkRedTranspAmb);
		break;
	}
}

void desenharPeca(Peca p, float xCoord, float yCoord, float zCoord) {
	switch (p) {
	case peao1:
	case peao2:
		glPushMatrix();
		glTranslatef(xCoord, yCoord + 0.48f, zCoord);
		glScalef(0.65f, 0.65f, 0.65f);
		glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
		loader->at(0)->draw();
		glPopMatrix();
		break;
	case torre1:
	case torre2:
		glPushMatrix();
		glTranslatef(xCoord, yCoord + 0.51f, zCoord);
		glScalef(0.68f, 0.68f, 0.68f);
		glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
		loader->at(1)->draw();
		glPopMatrix();
		break;
	case cavalo1:
	case cavalo2:
		glPushMatrix();
		glTranslatef(xCoord, yCoord + 0.63f, zCoord);
		glScalef(0.88f, 0.88f, 0.88);
		if (p == cavalo1)
			glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
		else
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

		loader->at(2)->draw();
		glPopMatrix();
		break;
	case bispo1:
	case bispo2:
		glPushMatrix();
		glTranslatef(xCoord, yCoord + 0.67f, zCoord);
		glScalef(0.9f, 0.9f, 0.9f);
		glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
		loader->at(3)->draw();
		glPopMatrix();
		break;
	case rainha1:
	case rainha2:
		glPushMatrix();
		glTranslatef(xCoord, yCoord + 0.76f, zCoord);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
		loader->at(4)->draw();
		glPopMatrix();
		break;
	case rei1:
	case rei2:
		glPushMatrix();
		glTranslatef(xCoord, yCoord + 0.84f, zCoord);
		glScalef(1.2f, 1.2f, 1.2f);
		glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
		loader->at(5)->draw();
		glPopMatrix();
		break;
	}
}

void adicionarNoCemiterio(Peca p) {
	if (p > 6) {
		for (int i = 0; i < sizeof(cemiterio2); i++) {
			if (cemiterio2[i] == nenhum) {
				cemiterio2[i] = p;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < sizeof(cemiterio1); i++) {
			if (cemiterio1[i] == nenhum) {
				cemiterio1[i] = p;
				break;
			}
		}
	}
}

void desenhaPecaCemiterio(Peca p, int pos) {
	if (p < 7) {
		configureColor(white);
		desenharPeca(p, cemiterioPos1[pos][0], 0.0f, cemiterioPos1[pos][1]);
	}
	else
	{
		configureColor(black);
		desenharPeca(p, cemiterioPos2[pos][0], 0.0f, cemiterioPos2[pos][1]);
	}
}

void desenhaTabuleiro() {
	configureColor(gray);

	glBegin(GL_QUADS); // lado esquerdo
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // lado direito
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // lado de trás
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_BASE_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // lado da frente
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_LADO_TAB_X, C_BASE_Y, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_BASE_Y, C_LADO_TAB_Z);
	glEnd();

	configureColor(white);

	GLfloat bordaTotal = 0.6f;

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z + bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z + bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_BASE_Z);
	glEnd();

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z - bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z - bordaTotal);
	glVertex3f(C_LADO_TAB_X, C_ALT_TAB, C_LADO_TAB_Z);
	glEnd();

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X + bordaTotal, C_ALT_TAB, C_BASE_Z);
	glVertex3f(C_BASE_X + bordaTotal, C_ALT_TAB, C_LADO_TAB_Z);
	glVertex3f(C_BASE_X, C_ALT_TAB, C_LADO_TAB_Z);
	glEnd();

	glBegin(GL_QUADS); // topo principal
	glNormal3f(0.0f, 1.0f, 0.0f);
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
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB, (Z * xPeca) + bordaTotal);
			glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB, (Z * xPeca) + bordaTotal + zPeca);
			glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB, (Z * xPeca) + bordaTotal + zPeca);
			glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB, (Z * xPeca) + bordaTotal);
			glEnd();

			matrizPosPecas[X][Z][0] = ((Z * xPeca) + bordaTotal) + (zPeca / 2);
			matrizPosPecas[X][Z][1] = ((X * xPeca) + bordaTotal) + (xPeca / 2);

			if ((playerAtual == playerJogando) && (X == quadradoAtual[0]) && (Z == quadradoAtual[1])) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBegin(GL_QUADS);
				configureColor(blueTransp);
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal);
				glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal + zPeca);
				configureColor(darkBlueTransp);
				glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal + zPeca);
				glVertex3f((X * xPeca) + bordaTotal + xPeca, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal);
				glEnd();
				glEnable(GL_BLEND);
			}

			if ((modoMovPeca) && (X == pecaSelecionada.X) && (Z == pecaSelecionada.Z)) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBegin(GL_QUADS);
				configureColor(redTransp);
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal);
				glVertex3f((X * xPeca) + bordaTotal, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal + zPeca);
				configureColor(darkRedTransp);
				glVertex3f((GLfloat)(X * xPeca) + bordaTotal + xPeca, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal + zPeca);
				glVertex3f((GLfloat)(X * xPeca) + bordaTotal + xPeca, C_ALT_TAB + 0.005, (Z * xPeca) + bordaTotal);
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
	float x = 2.0f, z = 2.5f;
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(C_BASE_X - x, C_BASE_Y, C_BASE_Z - z);
	glVertex3f(C_BASE_X - x, C_BASE_Y, C_LADO_TAB_Z + z);
	glVertex3f(C_LADO_TAB_X + x, C_BASE_Y, C_LADO_TAB_Z + z);
	glVertex3f(C_LADO_TAB_X + x, C_BASE_Y, C_BASE_Z - z);
	glEnd;

	desenhaTabuleiro();

	for (int z = 0; z < 8; z++) {
		for (int x = 0; x < 8; x++) {
			if (matrizTabuleiro[z][x] > 0) {
				if (matrizTabuleiro[z][x] < 7)
					configureColor(white);
				else
					configureColor(black);

				desenharPeca(Peca(matrizTabuleiro[z][x]), matrizPosPecas[z][x][0], C_ALT_TAB, matrizPosPecas[z][x][1]);
			}
		}
	}

	for (int i = 0; i < 16; i++) {
		desenhaPecaCemiterio(cemiterio1[i], i);
	}

	for (int i = 0; i < 16; i++) {
		desenhaPecaCemiterio(cemiterio2[i], i);
	}

	glutSwapBuffers();
}

void init(void)
{
	glClearColor(C_COR_FUNDO[0], C_COR_FUNDO[1], C_COR_FUNDO[2], C_COR_FUNDO[3]);
	glEnable(GL_DEPTH_TEST);

	GLfloat luzPos[] = { C_LADO_TAB_X / 2,  6.0f, C_LADO_TAB_Z / 2, 1.0f };
	GLfloat luzAmb[] = { 0.0f,  0.0f, 0.0f, 1.0f };
	GLfloat luzDif[] = { 1.0f,  1.0f, 1.0f, 1.0f };
	GLfloat luzSpe[] = { 0.3f,  0.3f, 0.3f, 0.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, luzPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzSpe);

	loader = new vector<OBJModel*>;
	loader->push_back(new OBJModel("Modelos/obj/peao", 1.5f, true));
	loader->push_back(new OBJModel("Modelos/obj/torre", 1.5f, true));
	loader->push_back(new OBJModel("Modelos/obj/cavalo", 1.5f, true));
	loader->push_back(new OBJModel("Modelos/obj/bispo", 1.5f, true));
	loader->push_back(new OBJModel("Modelos/obj/rainha", 1.5f, true));
	loader->push_back(new OBJModel("Modelos/obj/rei", 1.5f, true));
}

void refreshCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50, proporcao, 0.1, 500);
	gluLookAt(C_LADO_TAB_X / 2, C_ALT_TAB + 6.0f, (playerAtual == player1) ? C_LADO_TAB_Z + 8 : C_BASE_Z - 8,
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

bool validarMovPeca(Peca p, Peca alvo, int posVelha[], int posNova[]) {
	int xv = posVelha[0];
	int xn = posNova[0];

	int zv = posVelha[1];
	int zn = posNova[1];

	if ((xv == xn) && (zv == zn))
		return false;

	switch (p)
	{
	case peao1:
	case peao2:
		if (((playerAtual == player1) && (((posNova[0] == posVelha[0]) && (posVelha[1] == 6) && ((posNova[1] - posVelha[1] == -1) || (posNova[1] - posVelha[1] == -2))) || (posNova[1] - posVelha[1] == -1))) ||
			((playerAtual == player2) && (((posNova[0] == posVelha[0]) && (posVelha[1] == 1) && ((posNova[1] - posVelha[1] == 1) || (posNova[1] - posVelha[1] == 2))) || (posNova[1] - posVelha[1] == 1)))) {
			if (((posNova[0] == posVelha[0]) && (alvo == 0)) ||
				((abs(posNova[0] - posVelha[0]) == 1) && (alvo > 0))) {
				return true;
			}
		}

		return false;
	case torre1:
	case torre2:
		if (xv == xn)
		{
			if (zv > zn)
			{
				for (int pos = zv - 1; pos > zn; pos--)
				{
					if (matrizTabuleiro[pos][xv] > 0)
						return false;
				}
			}
			else
			{
				for (int pos = zv + 1; pos < zn; pos++)
				{
					if (matrizTabuleiro[pos][xv] > 0)
						return false;
				}
			}

			return true;
		}
		else if (zv == zn)
		{
			if (xv > xn)
			{
				for (int pos = xv - 1; pos > xn; pos--)
				{
					if (matrizTabuleiro[zv][pos] > 0)
						return false;
				}
			}
			else
			{
				for (int pos = xv + 1; pos < xn; pos++)
				{
					if (matrizTabuleiro[zv][pos] > 0)
						return false;
				}
			}

			return true;
		}

		return false;
	case cavalo1:
	case cavalo2:
		break;
	case bispo1:
		break;
	case rainha1:
		break;
	case rei1:
		break;
	case bispo2:
		break;
	case rainha2:
		break;
	case rei2:
		break;
	default: return false;
		break;
	}

	return false;
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
	case 32:
		Peca p = retornaPecaXZ(quadradoAtual[0], quadradoAtual[1]);
		if ((modoMovPeca) || ((((playerAtual == player1) && (p < 7)) || ((playerAtual == player2)) && (p > 6)) && (p > 0))) {
			if (!modoMovPeca) {
				modoMovPeca = true;
				pecaSelecionada.tipo = retornaPecaXZ(quadradoAtual[0], quadradoAtual[1]);
				pecaSelecionada.X = quadradoAtual[0];
				pecaSelecionada.Z = quadradoAtual[1];
			}
			else
			{
				modoMovPeca = false;
				int posVelha[2] = { pecaSelecionada.X, pecaSelecionada.Z };
				if (validarMovPeca(pecaSelecionada.tipo, p, posVelha, quadradoAtual)) {
					if ((p == 0) || ((playerAtual == player1) && (p > 6)) || ((playerAtual == player2) && (p < 7))) {
						if (p > 0) {
							adicionarNoCemiterio(p);
						}
						matrizTabuleiro[pecaSelecionada.Z][pecaSelecionada.X] = 0;
						if (((playerAtual == player1 && quadradoAtual[1] == 0) && p == 1) || ((playerAtual == player2 && quadradoAtual[1] == 7) && p == 7)) {
							matrizTabuleiro[quadradoAtual[1]][quadradoAtual[0]] = 5;
						}
						else
						{
							matrizTabuleiro[quadradoAtual[1]][quadradoAtual[0]] = pecaSelecionada.tipo;
						}
					}
				}
			}
			break;
		}
	}

	display();
	refreshCamera();
}

void keyboardSpecial(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if ((playerAtual == player1) && (quadradoAtual[0] > 0)) quadradoAtual[0]--;
		else if ((playerAtual == player2) && (quadradoAtual[0] < 7)) quadradoAtual[0]++;
		break;
	case GLUT_KEY_RIGHT:
		if ((playerAtual == player1) && (quadradoAtual[0] < 7)) quadradoAtual[0]++;
		else if ((playerAtual == player2) && (quadradoAtual[0] > 0)) quadradoAtual[0]--;
		break;
	case GLUT_KEY_UP:
		if ((playerAtual == player1) && (quadradoAtual[1] > 0)) quadradoAtual[1]--;
		else if ((playerAtual == player2) && (quadradoAtual[1] < 7)) quadradoAtual[1]++;
		break;
	case GLUT_KEY_DOWN:
		if ((playerAtual == player1) && (quadradoAtual[1] < 7)) quadradoAtual[1]++;
		else if ((playerAtual == player2) && (quadradoAtual[1] > 0)) quadradoAtual[1]--;
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