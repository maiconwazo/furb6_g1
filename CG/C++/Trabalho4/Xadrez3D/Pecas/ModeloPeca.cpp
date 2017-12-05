#include "ModeloPeca.h"

GLfloat ModeloPeca::GetPositionX()
{
	return PositionX;
}

GLfloat ModeloPeca::GetPositionZ()
{
	return PositionZ;
}

void ModeloPeca::PosicionaModelo()
{
	SetCor(Jogador == player1 ? whiteChess : blackChess);
}

ModeloPeca::ModeloPeca(OBJModel *objetoGrafico, Player jogador, int x, int z) : ModeloPadrao(objetoGrafico)
{	
	Jogador = jogador;
	X = x;
	Z = z;
}


ModeloPeca::~ModeloPeca()
{
}

bool ModeloPeca::ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8])
{
	if (((Z + 1 == z) && (X + 2 == x)) ||
		((Z + 1 == z) && (X - 2 == x)) ||
		((Z - 1 == z) && (X + 2 == x)) ||
		((Z - 1 == z) && (X - 2 == x)) ||
		((X + 1 == x) && (Z + 2 == z)) ||
		((X + 1 == x) && (Z - 2 == z)) ||
		((X - 1 == x) && (Z + 2 == z)) ||
		((X - 1 == x) && (Z - 2 == z)))
		return true;

	return false;
}

bool ModeloPeca::Promover()
{
	return false;
}

bool ModeloPeca::Rei()
{
	return false;
}
