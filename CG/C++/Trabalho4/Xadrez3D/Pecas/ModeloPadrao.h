#pragma once
#include "Types.h"
#include "Consts.h"
#include "..\loadObj\OBJModel.h"
class ModeloPadrao
{
protected:
	virtual GLfloat GetPositionX();
	virtual GLfloat GetPositionZ();
	OBJModel *ObjetoGrafico;
	void SetCor(Cor c);
	virtual void PosicionaModelo();
public:
	GLfloat PositionX;
	GLfloat PositionZ;

	ModeloPadrao(OBJModel *objetoGrafico);
	~ModeloPadrao();

	virtual void Desenhar();
};

