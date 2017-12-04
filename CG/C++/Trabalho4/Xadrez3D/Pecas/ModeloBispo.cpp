#include "ModeloBispo.h"

void ModeloBispo::PosicionaModelo()
{
	ModeloPeca::PosicionaModelo();
	if (Morta)
		glTranslatef(PositionX, 0.90f, PositionZ);
	else
		glTranslatef(X * 1.5f, 1.11f, Z * 1.5f);
	glScalef(1.15f, 1.15f, 1.15f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
}

ModeloBispo::ModeloBispo(OBJModel *objetoGrafico, Player jogador, int x, int z) : ModeloPeca(objetoGrafico, jogador, x, z)
{
}


ModeloBispo::~ModeloBispo()
{
}

bool ModeloBispo::ValidarMovimento(ModeloPeca *alvo, int x, int z, ModeloPeca* matrizPecas[8][8])
{
	if (abs(X - x) == abs(Z - z))
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
