#pragma once
#include "Pecas\ModeloPadrao.h"
#include "Pecas\ModeloPeca.h"
#include <vector>

class Cemiterio
{
	vector<ModeloPeca*> *PecasBrancas;
	vector<ModeloPeca*> *PecasPretas;
public:
	Cemiterio();
	~Cemiterio();

	void AdicionarPeca(ModeloPeca *peca);
	void DesenharCemiterio();
};

