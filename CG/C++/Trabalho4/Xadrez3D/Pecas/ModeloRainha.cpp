#include "ModeloRainha.h"

void ModeloRainha::PosicionaModelo()
{
	ModeloPeca::PosicionaModelo();
	if (Morta)
		glTranslatef(PositionX, 0.90f, PositionZ);
	else
		glTranslatef(X * 1.5f, 1.13f, Z * 1.5f);
	glScalef(1.19f, 1.19f, 1.19f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
}

ModeloRainha::ModeloRainha(OBJModel *objetoGrafico, Player jogador, int x, int z) : ModeloPeca(objetoGrafico, jogador, x, z)
{
}


ModeloRainha::~ModeloRainha()
{
}

bool ModeloRainha::ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8])
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
	else if (abs(X - x) == abs(Z - z))
	{
		bool xPositivo = x - X >= 0;
		bool zPositivo = z - Z >= 0;

		int deslocamento = abs(X - x);
		for (int i = 1; i < deslocamento; i++)
		{
			int zPos = 0;
			int xPos = 0;

			if (zPositivo)
				zPos = Z + i;
			else
				zPos = Z - i;

			if (xPositivo)
				xPos = X + i;
			else
				xPos = X - i;

			if (matrizPecas[zPos][xPos] != nullptr)
			{
				return false;
			}
		}

		return true;
	}

	return false;
}
