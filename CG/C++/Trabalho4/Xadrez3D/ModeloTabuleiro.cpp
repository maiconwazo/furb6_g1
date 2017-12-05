#include "ModeloTabuleiro.h"
#include <typeinfo>

ModeloTabuleiro::ModeloTabuleiro(OBJModel *objetoGrafico) : ModeloPadrao(objetoGrafico)
{
	for (int x = 0; x < 8; x++)
		for (int z = 0; z < 9; z++)
			MatrizTabuleiro[x][z] = nullptr;

	ObjQuadrado = new OBJModel("Modelos/obj/quadrado", 1.5f, 36);
	ObjMoldura = new OBJModel("Modelos/obj/moldura", 1.5f, 61);

	ObjPeao = new OBJModel("Modelos/obj/peao", 1.5f, 4644);
	MatrizTabuleiro[1][0] = new ModeloPeao(ObjPeao, player2, 0, 1);
	MatrizTabuleiro[1][1] = new ModeloPeao(ObjPeao, player2, 1, 1);
	MatrizTabuleiro[1][2] = new ModeloPeao(ObjPeao, player2, 2, 1);
	MatrizTabuleiro[1][3] = new ModeloPeao(ObjPeao, player2, 3, 1);
	MatrizTabuleiro[1][4] = new ModeloPeao(ObjPeao, player2, 4, 1);
	MatrizTabuleiro[1][5] = new ModeloPeao(ObjPeao, player2, 5, 1);
	MatrizTabuleiro[1][6] = new ModeloPeao(ObjPeao, player2, 6, 1);
	MatrizTabuleiro[1][7] = new ModeloPeao(ObjPeao, player2, 7, 1);

	MatrizTabuleiro[6][0] = new ModeloPeao(ObjPeao, player1, 0, 6);
	MatrizTabuleiro[6][1] = new ModeloPeao(ObjPeao, player1, 1, 6);
	MatrizTabuleiro[6][2] = new ModeloPeao(ObjPeao, player1, 2, 6);
	MatrizTabuleiro[6][3] = new ModeloPeao(ObjPeao, player1, 3, 6);
	MatrizTabuleiro[6][4] = new ModeloPeao(ObjPeao, player1, 4, 6);
	MatrizTabuleiro[6][5] = new ModeloPeao(ObjPeao, player1, 5, 6);
	MatrizTabuleiro[6][6] = new ModeloPeao(ObjPeao, player1, 6, 6);
	MatrizTabuleiro[6][7] = new ModeloPeao(ObjPeao, player1, 7, 6);

	ObjTorre = new OBJModel("Modelos/obj/torre", 1.5f, 3127);
	MatrizTabuleiro[0][0] = new ModeloTorre(ObjTorre, player2, 0, 0);
	MatrizTabuleiro[0][7] = new ModeloTorre(ObjTorre, player2, 7, 0);

	MatrizTabuleiro[7][0] = new ModeloTorre(ObjTorre, player1, 0, 7);
	MatrizTabuleiro[7][7] = new ModeloTorre(ObjTorre, player1, 7, 7);

	ObjCavalo = new OBJModel("Modelos/obj/cavalo", 1.5f, 62501);
	MatrizTabuleiro[0][1] = new ModeloCavalo(ObjCavalo, player2, 1, 0);
	MatrizTabuleiro[0][6] = new ModeloCavalo(ObjCavalo, player2, 6, 0);

	MatrizTabuleiro[7][1] = new ModeloCavalo(ObjCavalo, player1, 1, 7);
	MatrizTabuleiro[7][6] = new ModeloCavalo(ObjCavalo, player1, 6, 7);

	ObjBispo = new OBJModel("Modelos/obj/bispo", 1.5f, 5100);
	MatrizTabuleiro[0][2] = new ModeloBispo(ObjBispo, player2, 2, 0);
	MatrizTabuleiro[0][5] = new ModeloBispo(ObjBispo, player2, 5, 0);

	MatrizTabuleiro[7][2] = new ModeloBispo(ObjBispo, player1, 2, 7);
	MatrizTabuleiro[7][5] = new ModeloBispo(ObjBispo, player1, 5, 7);

	ObjRainha = new OBJModel("Modelos/obj/rainha", 1.5f, 75529);
	MatrizTabuleiro[0][4] = new ModeloRainha(ObjRainha, player2, 4, 0);
	MatrizTabuleiro[7][4] = new ModeloRainha(ObjRainha, player1, 4, 7);

	ObjRei = new OBJModel("Modelos/obj/rei", 1.5f, 4367);
	MatrizTabuleiro[0][3] = new ModeloRei(ObjRei, player2, 3, 0);
	MatrizTabuleiro[7][3] = new ModeloRei(ObjRei, player1, 3, 7);
}


ModeloTabuleiro::~ModeloTabuleiro()
{
}

void ModeloTabuleiro::Desenhar()
{
	SetCor(brown);
	glPushMatrix();
	glScalef(9.02f, 9.02f, 9.02f);
	glTranslatef(0.58f, 0.0f, 0.58f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
	ObjMoldura->draw();
	glPopMatrix();

	Cor cor = black;
	bool inverte = true;
	for (int X = 0; X < 8; X++) {
		for (int Z = 0; Z < 8; Z++) {
			if (inverte) {
				if (cor == blackChess)
					cor = whiteChess;
				else
					cor = blackChess;
			}
			else { inverte = true; }

			SetCor((X == PosicaoFocada[0] && Z == PosicaoFocada[1]) ? blue : (ModoPecaSelecionada) && (X == PecaSelecionada->X) && (Z == PecaSelecionada->Z) ? redTransp : cor);
			
			glPushMatrix();
			glTranslatef((GLfloat)X * 1.50f, 0.0f, (GLfloat)Z * 1.50f);
			glScalef(1.0f, 1.0f, 1.0f);
			glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
			ObjQuadrado->draw();
			glPopMatrix();
		}

		inverte = false;
	}


	for (int x = 0; x < 8; x++)
		for (int z = 0; z < 8; z++)
			if (MatrizTabuleiro[x][z] != nullptr) 
				MatrizTabuleiro[x][z]->Desenhar();
}

bool ModeloTabuleiro::Clicar(unsigned char key, int x, int y, Player jogadorAtual, Cemiterio *cemiterio)
{
	if (key == 32) {
		ModeloPeca *peca = MatrizTabuleiro[PosicaoFocada[1]][PosicaoFocada[0]];
		if ((ModoPecaSelecionada) || (peca != nullptr && jogadorAtual == peca->Jogador)) {
			if (!ModoPecaSelecionada) {
				ModoPecaSelecionada = true;
				PecaSelecionada = peca;
			}
			else
			{
				ModoPecaSelecionada = false;
				if (PecaSelecionada->ValidarMovimento(peca, PosicaoFocada[0], PosicaoFocada[1], MatrizTabuleiro)) {
					if ((peca == nullptr) || jogadorAtual != peca->Jogador) {
						if (peca != nullptr) {
							cemiterio->AdicionarPeca(peca);
							Acabou = peca->Rei();
							if (Acabou) Ganhardor = PecaSelecionada->Jogador;
						}

						MatrizTabuleiro[PecaSelecionada->Z][PecaSelecionada->X] = nullptr;
						if (jogadorAtual == player1 && PosicaoFocada[1] == 0 && PecaSelecionada->Promover()) {
							MatrizTabuleiro[PosicaoFocada[1]][PosicaoFocada[0]] = new ModeloRainha(ObjRainha, player1, PosicaoFocada[0], PosicaoFocada[1]);
						}
						else 
						if (jogadorAtual == player2 && PosicaoFocada[1] == 7 && PecaSelecionada->Promover()) {
							MatrizTabuleiro[PosicaoFocada[1]][PosicaoFocada[0]] = new ModeloRainha(ObjRainha, player2, PosicaoFocada[0], PosicaoFocada[1]);
						}
						else
						{
							PecaSelecionada->X = PosicaoFocada[0];
							PecaSelecionada->Z = PosicaoFocada[1];
							MatrizTabuleiro[PosicaoFocada[1]][PosicaoFocada[0]] = PecaSelecionada;
						}

						return true;
					}
				}
			}
		}
		return false;
	}
	return false;
}

void ModeloTabuleiro::Movimentar(int key, int x, int y, Player jogadorAtual)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: 
		if ((jogadorAtual == player1) && (PosicaoFocada[0] > 0)) PosicaoFocada[0]--;
		else if ((jogadorAtual == player2) && (PosicaoFocada[0] < 7)) PosicaoFocada[0]++;
		break;
	case GLUT_KEY_RIGHT:
		if ((jogadorAtual == player1) && (PosicaoFocada[0] < 7)) PosicaoFocada[0]++;
		else if ((jogadorAtual == player2) && (PosicaoFocada[0] > 0)) PosicaoFocada[0]--;
		break;
	case GLUT_KEY_UP:
		if ((jogadorAtual == player1) && (PosicaoFocada[1] > 0)) PosicaoFocada[1]--;
		else if ((jogadorAtual == player2) && (PosicaoFocada[1] < 7)) PosicaoFocada[1]++;
		break;
	case GLUT_KEY_DOWN:
		if ((jogadorAtual == player1) && (PosicaoFocada[1] < 7)) PosicaoFocada[1]++;
		else if ((jogadorAtual  == player2) && (PosicaoFocada[1] > 0)) PosicaoFocada[1]--;
		break;
	}
}
