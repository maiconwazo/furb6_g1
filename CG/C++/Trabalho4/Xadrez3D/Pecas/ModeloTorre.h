#pragma once
#include "ModeloPeca.h"
class ModeloTorre : public ModeloPeca
{
protected:
	void PosicionaModelo() override;
public:
	ModeloTorre(OBJModel *objetoGrafico, Player jogador, int x, int z);
	~ModeloTorre();
	bool ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8]) override;
};

