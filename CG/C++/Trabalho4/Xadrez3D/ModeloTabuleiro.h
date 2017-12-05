#pragma once
#include "Pecas\ModeloPadrao.h"
#include "loadObj\OBJModel.h"
#include "Pecas\ModeloPeca.h"
#include "Pecas\ModeloPeao.h"
#include "Pecas\ModeloTorre.h"
#include "Pecas\ModeloCavalo.h"
#include "Pecas\ModeloBispo.h"
#include "Pecas\ModeloRainha.h"
#include "Pecas\ModeloRei.h"
#include "Pecas\Consts.h"
#include "Cemiterio.h"

class ModeloTabuleiro : ModeloPadrao
{
	ModeloPeca *PecaSelecionada;
	int PosicaoFocada[2] = { 0, 7 };
	bool ModoPecaSelecionada = false;

	OBJModel *ObjPeao;
	OBJModel *ObjTorre;
	OBJModel *ObjCavalo;
	OBJModel *ObjBispo;
	OBJModel *ObjRainha;
	OBJModel *ObjRei;
	OBJModel *ObjQuadrado;
	OBJModel *ObjMoldura;
public:
	bool Acabou = false;
	Player Ganhardor = player1;
	ModeloPeca* MatrizTabuleiro[8][8];
	ModeloTabuleiro(OBJModel *objetoGrafico);
	~ModeloTabuleiro();

	void Desenhar() override;
	bool Clicar(unsigned char key, int x, int y, Player jogadorAtual, Cemiterio *cemiterio);
	void Movimentar(int key, int x, int y, Player jogadorAtual);
};

