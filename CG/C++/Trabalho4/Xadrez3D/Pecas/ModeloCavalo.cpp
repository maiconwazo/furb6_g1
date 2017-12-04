#include "ModeloCavalo.h"

void ModeloCavalo::PosicionaModelo()
{
	ModeloPeca::PosicionaModelo();
	if (Morta)
		glTranslatef(PositionX, 0.90f, PositionZ);
	else
		glTranslatef(X * 1.5f, 1.02f, Z * 1.5f);
	glScalef(1.05f, 1.05f, 1.05f);
	if (Jogador == player1)
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	else
		if (Jogador == player2)
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
}

ModeloCavalo::ModeloCavalo(OBJModel *objetoGrafico, Player jogador, int x, int z) : ModeloPeca(objetoGrafico, jogador, x, z)
{
}


ModeloCavalo::~ModeloCavalo()
{
}

bool ModeloCavalo::ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8])
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
