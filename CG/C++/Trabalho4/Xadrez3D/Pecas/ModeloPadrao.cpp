#include "ModeloPadrao.h"

GLfloat ModeloPadrao::GetPositionX()
{
	return 0.0f;
}

GLfloat ModeloPadrao::GetPositionZ()
{
	return 0.0f;
}

void ModeloPadrao::SetCor(Cor c)
{
	switch (c) {
	case white:
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpe);
		break;
	case black:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blackDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blackSpe);
		break;
	case blue:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blueAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blueDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blueSpe);
		break;
	case gray:
		glMaterialfv(GL_FRONT, GL_AMBIENT, grayAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, grayDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, graySpe);
		break;
	case brown:
		glMaterialfv(GL_FRONT, GL_AMBIENT, brownAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brownDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, brownSpe);
		break;
	case purple:
		glMaterialfv(GL_FRONT, GL_AMBIENT, purpleAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purpleDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, purpleSpe);
		break;
	case blackChess:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackChessAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blackChessDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blackChessSpe);
		break;
	case whiteChess:
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteChessAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteChessDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteChessSpe);
		break;
	case blueTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, blueTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blueTranspDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blueTranspSpe);
		break;
	case darkBlueTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, darkBlueTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, darkBlueTranspDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, darkBlueTranspSpe);
		break;
	case redTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, redTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, redTranspAmb);
		glMaterialfv(GL_FRONT, GL_SPECULAR, redTranspAmb);
		break;
	case darkRedTransp:
		glMaterialfv(GL_FRONT, GL_AMBIENT, darkRedTranspAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, darkRedTranspAmb);
		glMaterialfv(GL_FRONT, GL_SPECULAR, darkRedTranspAmb);
		break;
	}
}

void ModeloPadrao::PosicionaModelo()
{
}

ModeloPadrao::ModeloPadrao(OBJModel *objetoGrafico)
{
	ObjetoGrafico = objetoGrafico;
}


ModeloPadrao::~ModeloPadrao()
{
}

void ModeloPadrao::Desenhar()
{
	if (ObjetoGrafico != nullptr)
	{
		glPushMatrix();
		PositionX = GetPositionX();
		PositionX = GetPositionZ();
		PosicionaModelo();
		ObjetoGrafico->draw();
		glPopMatrix();
	}
}
