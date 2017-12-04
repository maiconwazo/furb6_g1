#include "Cemiterio.h"

static float CemiterioPretas[16][2] = {
	{ 14.7f, 13.1f },
	{ 15.3f, 12.5f },
	{ 14.7f, 13.2f },
	{ 14.8f, 11.5f },
	{ 15.4f, 11.0f },
	{ 15.3f, 10.4f },
	{ 14.6f, 10.1f },
	{ 15.2f,  9.5f },
	{ 14.7f,  8.9f },
	{ 15.3f,  8.4f },
	{ 15.1f,  7.8f },
	{ 15.3f,  7.2f },
	{ 14.7f,  7.1f },
	{ 15.3f,  6.4f },
	{ 14.8f,  5.7f },
	{ 15.4f,  5.0f }
};

static float CemiterioBrancas[16][2] = {
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

Cemiterio::Cemiterio()
{
	PecasBrancas = new vector<ModeloPeca*>();
	PecasPretas = new vector<ModeloPeca*>();
}

Cemiterio::~Cemiterio()
{
}

void Cemiterio::AdicionarPeca(ModeloPeca *peca)
{
	switch (peca->Jogador)
	{
	case player1:
		PecasBrancas->push_back(peca);
		break;
	case player2:
		PecasPretas->push_back(peca);
		break;
	}
}

void Cemiterio::DesenharCemiterio()
{
	int size = PecasBrancas->size();
	for (int i = 0; i < size; i++) 
	{
		ModeloPeca *peca = PecasBrancas->at(i);
		peca->PositionX = CemiterioBrancas[i][0];
		peca->PositionZ = CemiterioBrancas[i][1];
		peca->Morta = true;
		peca->Desenhar();
	}

	size = PecasPretas->size();
	for (int i = 0; i < size; i++)
	{
		ModeloPeca *peca = PecasPretas->at(i);
		peca->PositionX = CemiterioPretas[i][0];
		peca->PositionZ = CemiterioPretas[i][1];
		peca->Morta = true;
		peca->Desenhar();
	}
}

