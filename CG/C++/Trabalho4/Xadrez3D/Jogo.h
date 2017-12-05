#pragma once
#include "ModeloTabuleiro.h"
#include "Cemiterio.h"
class Jogo:ModeloPadrao
{
private:
	Player JogadorAtual = player1;
	OBJModel *Mesa;
	OBJModel *Vidro;
	OBJModel *Cadeira;
public:
	Cemiterio *CemiterioObj;
	ModeloTabuleiro *Tabuleiro;

	Jogo();
	~Jogo();

	Player GetJogadorAtual();
	void SetJogadorAtual();
	void DesenharJogo();
};

