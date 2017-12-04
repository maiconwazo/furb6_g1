#include "ModeloTorre.h"

void ModeloTorre::PosicionaModelo()
{
	ModeloPeca::PosicionaModelo();
	glTranslatef(X * 1.5f, 0.92f, Z * 1.5f);
	glScalef(0.9f, 0.9f, 0.9f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
}

ModeloTorre::ModeloTorre(OBJModel *objetoGrafico, Player jogador, int x, int z) : ModeloPeca(objetoGrafico, jogador, x, z)
{
}


ModeloTorre::~ModeloTorre()
{
}

bool ModeloTorre::ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8])
{
	if (X == x)
	{
		if (Z > z)
		{
			for (int pos = Z - 1; pos > z; pos--)
			{
				if (matrizPecas[pos][X] != nullptr)
					return false;
			}
		}
		else
		{
			for (int pos = Z + 1; pos < z; pos++)
			{
				if (matrizPecas[pos][X] != nullptr)
					return false;
			}
		}

		return true;
	}
	else if (Z == z)
	{
		if (X > x)
		{
			for (int pos = X - 1; pos > x; pos--)
			{
				if (matrizPecas[Z][pos] != nullptr)
					return false;
			}
		}
		else
		{
			for (int pos = X + 1; pos < x; pos++)
			{
				if (matrizPecas[Z][pos] != nullptr)
					return false;
			}
		}

		return true;
	}

	return false;
}
