using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DietFit
{
	class Perfil
	{
		public decimal Altura;
		public decimal Peso;
		public int Idade;
		public IndiceAtividadeFisica AtvFisica;
		public Sexo Sexo;
		public string Mensagem;

		public void GerarDieta(Objetivo Obj) {
			decimal multPeso = 0.0m;
			decimal multAltura = 0.0m;
			decimal multIdade = 0.0m;
			decimal multAtv = 0.0m;
			decimal valBase = 0m;
			switch (Sexo) {
				case Sexo.sMasc:
					multPeso = 13.7m;
					multAltura = 5.0m;
					multIdade = 6.8m;
					valBase = 66m;

					if (Idade < 19)
					{
						switch (AtvFisica)
						{
							case IndiceAtividadeFisica.iaSedentario:
								multAtv = 1;
								break;
							case IndiceAtividadeFisica.iaPoucoAtivo:
								multAtv = 1.12m;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.24m;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.45m;
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
								multAtv = 1.12m;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.29m;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.59m;
								break;
						}
					}
					break;
				case Sexo.sFem:
					multPeso = 9.6m;
					multAltura = 1.8m;
					multIdade = 4.7m;
					valBase = 655m;


					if (Idade < 19)
					{
						switch (AtvFisica)
						{
							case IndiceAtividadeFisica.iaSedentario:
								multAtv = 1;
								break;
							case IndiceAtividadeFisica.iaPoucoAtivo:
								multAtv = 1.18m;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.35m;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.60m;
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
								multAtv = 1.16m;
								break;
							case IndiceAtividadeFisica.iaAtivo:
								multAtv = 1.27m;
								break;
							case IndiceAtividadeFisica.iaMuitoAtivo:
								multAtv = 1.44m;
								break;
						}
					}
					break;
			}

			decimal totalKcal = valBase + ((Peso * multPeso) * multAtv) + (Altura * multAltura) - (Idade * multIdade);
			
			if (Obj == Objetivo.oBulking)
			{
				totalKcal += totalKcal * 0.10m;
			}
			else if (Obj == Objetivo.oCutting)
			{
				totalKcal -= totalKcal * 0.10m;
			}

			decimal gramasProt = Peso * 2;
			decimal gramasGord = Peso;
			decimal gramasCarb = (totalKcal - (gramasProt * 4) - (gramasGord * 9)) / 4;

			var dieta = new Dieta(totalKcal, gramasProt, gramasCarb, gramasGord);
			dieta.GerarRefeicoes();
			Mensagem = dieta.Mensagem;
		}
	}
}
