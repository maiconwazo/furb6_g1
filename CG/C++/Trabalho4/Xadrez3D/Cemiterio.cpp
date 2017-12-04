#include "Cemiterio.h"

static float CemiterioPretas[16][2] = {
	{ 9.7f,  8.1f },
	{ 10.3f,  7.5f },
	{ 9.7f,  7.2f },
	{ 9.8f,  6.5f },
	{ 10.4f,  6.0f },
	{ 10.3f,  5.4f },
	{ 9.6f,  5.1f },
	{ 10.2f,  4.5f },
	{ 9.7f,  3.9f },
	{ 10.3f,  3.4f },
	{ 10.1f,  2.8f },
	{ 10.3f,  2.2f },
	{ 9.7f,  2.1f },
	{ 10.3f,  1.4f },
	{ 9.8f,  0.7f },
	{ 10.4f,  0.0f }
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

