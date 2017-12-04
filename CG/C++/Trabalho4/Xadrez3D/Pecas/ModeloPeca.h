#pragma once
#include "ModeloPadrao.h"
#include "Types.h"
#include <glew.h>

class ModeloPeca : public ModeloPadrao
{
protected:
	virtual GLfloat GetPositionX();
	virtual GLfloat GetPositionZ();
	void PosicionaModelo() override;
public: 
	int X;
	int Z;
	Player Jogador;
	bool Morta = false;

	ModeloPeca(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloPeca();

	virtual bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]);
};

