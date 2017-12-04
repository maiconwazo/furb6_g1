#include "Jogo.h"

Jogo::Jogo()
{
	Tabuleiro = new ModeloTabuleiro(nullptr);
	CemiterioObj = new Cemiterio();
}


Jogo::~Jogo()
{
}

Player Jogo::GetJogadorAtual()
{
	return JogadorAtual;
}

void Jogo::DesenharJogo()
{
	CemiterioObj->DesenharCemiterio();
	Tabuleiro->Desenhar();
}
