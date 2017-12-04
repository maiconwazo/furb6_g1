#pragma once
#include "ModeloPeca.h"
class ModeloCavalo :public ModeloPeca
{
protected:
	void PosicionaModelo() override;
public:
	ModeloCavalo(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloCavalo();
	bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]) override;
};

