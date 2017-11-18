using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesDieta
{
	class Perfil
	{
		public double Altura;
		public double Peso;
		public int Idade;
		public IndiceAtividadeFisica AtvFisica;
		public Sexo Sexo;

		public void GerarDieta(Objetivo Obj, int QtdRefeicoes) {
			var multPeso = 0.0;
			var multAltura = 0.0;
			var multIdade = 0.0;
			var multAtv = 0.0;
			var valBase = 0;
			switch (Sexo) {
				case Sexo.sMasc:
					multPeso = 13.7;
					multAltura = 5.0;
					multIdade = 6.8;
					valBase = 66;

					if (Idade < 19)
					{
						switch (AtvFisica)
						{
							case IndiceAtividadeFisica.iaSedentario:
								multAtv = 1;
								break;
							case IndiceAtividadeFisica.iaPoucoAtivo:
								multAtv = 1.12;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.24;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.45;
								break;
						}
					}
					else
					{
						switch (AtvFisica)
						{
							case IndiceAtividadeFisica.iaSedentario:
								multAtv = 1;
								break;
							case IndiceAtividadeFisica.iaPoucoAtivo:
								multAtv = 1.12;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.29;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.59;
								break;
						}
					}
					break;
				case Sexo.sFem:
					multPeso = 9.6;
					multAltura = 1.8;
					multIdade = 4.7;
					valBase = 655;


					if (Idade < 19)
					{
						switch (AtvFisica)
						{
							case IndiceAtividadeFisica.iaSedentario:
								multAtv = 1;
								break;
							case IndiceAtividadeFisica.iaPoucoAtivo:
								multAtv = 1.18;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.35;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.60;
								break;
						}
					}
					else
					{
						switch (AtvFisica)
						{
							case IndiceAtividadeFisica.iaSedentario:
								multAtv = 1;
								break;
							case IndiceAtividadeFisica.iaPoucoAtivo:
								multAtv = 1.16;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.27;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.44;
								break;
						}
					}
					break;
			}

			var totalKcal = valBase + ((Peso * multPeso) * multAtv) + (Altura * multAltura) - (Idade * multIdade);
			
			if (Obj == Objetivo.oBulking)
			{
				totalKcal += totalKcal * 0.10;
			}
			else if (Obj == Objetivo.oCutting)
			{
				totalKcal -= totalKcal * 0.10;
			}

			var gramasProt = Peso * 2;
			var gramasGord = Peso;
			var gramasCarb = (totalKcal - (gramasProt * 4) - (gramasGord * 9)) / 4;

			var dieta = new Dieta(totalKcal, gramasProt, gramasCarb, gramasGord, QtdRefeicoes);
			dieta.GerarRefeicoes();
		}
	}
}
