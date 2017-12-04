#pragma once
#include "ModeloPeca.h"
class ModeloRei : public ModeloPeca
{
protected:
	void PosicionaModelo() override;
public:
	ModeloRei(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloRei();
	bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]) override;
};

