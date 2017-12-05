#pragma comment(lib, "glew32.lib")
#include <glew.h>
#include <freeglut.h>
#include "Mundo.h"

Mundo *MundoObj;

void display() 
{
	MundoObj->Desenhar();
}

void reshape(GLsizei width, GLsizei height)
{
	MundoObj->CameraObj->Reshape(width,height);
}

void keyboard(unsigned char key, int x, int y)
{
	if (MundoObj->JogoObj->Tabuleiro->Clicar(key, x, y, MundoObj->JogoObj->GetJogadorAtual(), MundoObj->JogoObj->CemiterioObj))
	{
		if (MundoObj->JogoObj->Tabuleiro->Acabou)
		{
			glutLeaveMainLoop();
		}
		else
		{
			MundoObj->JogoObj->SetJogadorAtual();
			MundoObj->CameraObj->AlternarCamera();
		}
	}

	MundoObj->Desenhar();
}

void keyboardSpecial(int key, int x, int y)
{
	MundoObj->JogoObj->Tabuleiro->Movimentar(key, x, y, MundoObj->JogoObj->GetJogadorAtual());
	MundoObj->Desenhar();
}

void idle()
{
	MundoObj->CameraObj->Atualizar();
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Xadrez 3D");
	
	MundoObj = new Mundo();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);													   
	glutSpecialFunc(keyboardSpecial);
	glutIdleFunc(idle);
	glutMainLoop();
	
	if (MundoObj->JogoObj->Tabuleiro->Ganhardor == player1)
	{
		cout << "#############################################################################################" << "\n";
		cout << "#          ###   ########           ###   ######   ###          ###           ########   ####" << "\n";
		cout << "#   ####   ###   ########   #####   ###   ######   ###   ##########   #####   ######     ####" << "\n";
		cout << "#   ####   ###   ########   #####   #####   ##   #####   ##########   #####   ########   ####" << "\n";
		cout << "#          ###   ########           #######    #######       ######           ########   ####" << "\n";
		cout << "#   ##########   ########   #####   ########   #######   ##########   ###   ##########   ####" << "\n";
		cout << "#   ##########         ##   #####   ########   #######          ###   #####   ######       ##" << "\n";
		cout << "#############################################################################################" << "\n";
	}
	else
	{
		cout << "#############################################################################################" << "\n";
		cout << "#          ###   ########           ###   ######   ###          ###           ####       ####" << "\n";
		cout << "#   ####   ###   ########   #####   ###   ######   ###   ##########   #####   ###   ###   ###" << "\n";
		cout << "#   ####   ###   ########   #####   #####   ##   #####   ##########   #####   ###  ####   ####" << "\n";
		cout << "#          ###   ########           #######    #######       ######           #######   #####" << "\n";
		cout << "#   ##########   ########   #####   ########   #######   ##########   ###   #######    ######" << "\n";
		cout << "#   ##########         ##   #####   ########   #######          ###   #####   ###         ###" << "\n";
		cout << "#############################################################################################" << "\n";
	}

	cout << "#############################################################################################" << "\n";
	cout << "##################   ####################   ###   ###      #####   ##########################" << "\n";
	cout << "###################   ##################   ####   ###   #   ####   ##########################" << "\n";
	cout << "####################   ######   #######   #####   ###   ###   ##   ##########################" << "\n";
	cout << "#####################   ####      ####   ######   ###   ####   #   ##########################" << "\n";
	cout << "######################   ##   ##   ##   #######   ###   #####      ##########################" << "\n";
	cout << "#######################     ######     ########   ###   ######     ##########################" << "\n";
	cout << "#############################################################################################" << "\n";
	cin.ignore();
	return 0;
}