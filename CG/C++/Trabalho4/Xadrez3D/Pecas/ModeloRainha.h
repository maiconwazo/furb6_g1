#pragma once
#include "ModeloPeca.h"
class ModeloRainha : public ModeloPeca
{
protected:
	void PosicionaModelo() override;
public:
	ModeloRainha(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloRainha();
	bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]) override;
};

