#pragma once
#include "ModeloPeca.h"
class ModeloBispo : public ModeloPeca
{
protected:
	void PosicionaModelo() override;
public:
	ModeloBispo(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloBispo();
	bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]) override;
};

