#include "Jogo.h"

Jogo::Jogo() : ModeloPadrao(nullptr)
{
	Tabuleiro = new ModeloTabuleiro(nullptr);
	CemiterioObj = new Cemiterio();
	Mesa = new OBJModel("Modelos/obj/mesa", 1.5f, 221);
	Vidro = new OBJModel("Modelos/obj/vidro", 1.5f, 25);
	Cadeira = new OBJModel("Modelos/obj/cadeira", 1.5f, 6782);
}


Jogo::~Jogo()
{
}

Player Jogo::GetJogadorAtual()
{
	return JogadorAtual;
}

void Jogo::SetJogadorAtual()
{
	JogadorAtual = JogadorAtual == player1 ? player2 : player1;
}

void Jogo::DesenharJogo()
{
	SetCor(blackChess);
	glPushMatrix();
	glScalef(14.0f, 10.0f, 17.0f);
	glTranslatef(0.36f, -0.77f, 0.31f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	Mesa->draw();
	glPopMatrix();

	SetCor(blackChess);
	glPushMatrix();
	glScalef(23.5f, 20.5f, 20.5f);
	glTranslatef(0.25f, -0.42f, -0.30f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
	Cadeira->draw();
	glPopMatrix();

	SetCor(blackChess);
	glPushMatrix();
	glScalef(23.5f, 20.5f, 20.5f);
	glTranslatef(0.25f, -0.42f, 0.75f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	Cadeira->draw();
	glPopMatrix();

	SetCor(whiteChess);
	glBegin(GL_QUADS);
	glVertex3f(-60.0f, -15.0f, -40.0f);
	glVertex3f( 60.0f, -15.0f, -40.0f);
	glVertex3f( 60.0f, -15.0f,  40.0f);
	glVertex3f(-60.0f, -15.0f,  40.0f);
	glEnd();

	SetCor(white);
	glBegin(GL_QUADS);
	glVertex3f(-60.0f, -15.0f, -40.0f);
	glVertex3f( 60.0f, -15.0f, -40.0f);
	glVertex3f( 60.0f,  15.0f, -40.0f);
	glVertex3f(-60.0f,  15.0f, -40.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-60.0f, -15.0f, 40.0f);
	glVertex3f( 60.0f, -15.0f, 40.0f);
	glVertex3f( 60.0f,  15.0f, 40.0f);
	glVertex3f(-60.0f,  15.0f, 40.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f( 60.0f, -15.0f, -40.0f);
	glVertex3f( 60.0f, -15.0f,  40.0f);
	glVertex3f( 60.0f,  15.0f,  40.0f);
	glVertex3f( 60.0f,  15.0f, -40.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-60.0f, -15.0f, -40.0f);
	glVertex3f(-60.0f, -15.0f, 40.0f);
	glVertex3f(-60.0f, 15.0f, 40.0f);
	glVertex3f(-60.0f, 15.0f, -40.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SetCor(glass);
	glPushMatrix();
	glScalef(12.5f, 10.0f, 16.7f);
	glTranslatef(0.41f, -0.02f, 0.33f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	Vidro->draw();
	glPopMatrix();
	glDisable(GL_BLEND);

	CemiterioObj->DesenharCemiterio();
	Tabuleiro->Desenhar();
}
