#pragma once
#include "ModeloPeca.h"
class ModeloPeao : public ModeloPeca
{
protected:
	void PosicionaModelo() override;
public:
	ModeloPeao(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloPeao();
	bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]) override;
	bool Promover() override;
};

