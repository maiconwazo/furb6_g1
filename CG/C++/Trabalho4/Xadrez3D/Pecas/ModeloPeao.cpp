#include "ModeloPeao.h"

void ModeloPeao::PosicionaModelo()
{
	ModeloPeca::PosicionaModelo();
	if (Morta) 
		glTranslatef(PositionX, 0.90f, PositionZ);
	else
		glTranslatef(X * 1.5f, 0.90f, Z * 1.5f);
	glScalef(0.9f, 0.9f, 0.9f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
}

ModeloPeao::ModeloPeao(OBJModel *objetoGrafico, Player jogador, int x, int z) : ModeloPeca(objetoGrafico, jogador, x, z)
{
}


ModeloPeao::~ModeloPeao()
{
}

bool ModeloPeao::ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8])
{
	if (((Jogador == player1) && (((x == X) && (Z == 6) && ((z - Z == -1) || (z - Z == -2))) || (z - Z == -1))) ||
		((Jogador == player2) && (((x == X) && (X == 1) && ((z - Z == 1) || (z - Z == 2))) || (z - Z == 1)))) {
		if (((x == X) && (alvo == nullptr)) ||
			((abs(x - X) == 1) && (alvo != nullptr))) {
			return true;
		}
	}

	return false;
}
