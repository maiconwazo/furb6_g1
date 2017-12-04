#pragma once
#include "ModeloTabuleiro.h"
#include "Cemiterio.h"
class Jogo
{
private:
	Player JogadorAtual = player1;
public:
	Cemiterio *CemiterioObj;
	ModeloTabuleiro *Tabuleiro;

	Jogo();
	~Jogo();

	Player GetJogadorAtual();
	void DesenharJogo();
};

