using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesDieta
{
	public class Alimento
	{
		public double Proteina;
		public double Carboidrato;
		public double Gordura;
		public double Kcal;
		public string Unidade;
		
		public Alimento(double prot, double carbo, double gord, double kcal, string unidade)
		{
			Proteina = prot;
			Carboidrato = carbo;
			Gordura = gord;
			Unidade = unidade;
			Kcal = kcal;
		}
	}
}
