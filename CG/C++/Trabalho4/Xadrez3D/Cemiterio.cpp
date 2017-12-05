#include "Cemiterio.h"

static float CemiterioPretas[16][2] = {
	{ -2.6f,  0.0f },
	{ -3.2f,  0.9f },
	{ -2.5f,  1.8f },
	{ -3.3f,  2.5f },
	{ -2.2f,  3.3f },
	{ -2.9f,  4.0f },
	{ -2.2f,  4.6f },
	{ -3.3f,  5.4f },
	{ -2.5f,  6.0f },
	{ -3.6f,  6.8f },
	{ -2.8f,  7.5f },
	{ -3.6f,  8.1f },
	{ -2.3f,  8.9f },
	{ -3.3f,  9.7f },
	{ -2.7f, 10.5f },
	{ -3.3f, 11.4f }
};

static float CemiterioBrancas[16][2] = {
	{ 12.7f, 11.5f },
	{ 13.3f, 10.4f },
	{ 12.7f,  9.3f },
	{ 13.0f,  8.5f },
	{ 13.4f,  7.8f },
	{ 13.8f,  7.0f },
	{ 12.6f,  6.8f },
	{ 13.2f,  6.0f },
	{ 12.7f,  5.2f },
	{ 13.8f,  4.5f },
	{ 13.0f,  4.0f },
	{ 13.3f,  3.3f },
	{ 12.5f,  2.8f },
	{ 13.0f,  2.1f },
	{ 12.8f,  1.5f },
	{ 13.0f,  0.8f }
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

