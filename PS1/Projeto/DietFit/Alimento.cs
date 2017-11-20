using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DietFit
{
	public class Alimento
	{
		public string Nome;
		public decimal Proteina;
		public decimal Carboidrato;
		public decimal Gordura;
		public decimal Kcal { get { return (Proteina * 4) + (Carboidrato * 4) + (Gordura * 9); } }
		public decimal PorcaoPadrao;
		public string NomeUnidade;
		
		public Alimento(string nome, decimal prot, decimal carbo, decimal gord, decimal porcaoPadrao, string nomeUnidade)
		{
			Nome = nome;
			Proteina = prot;
			Carboidrato = carbo;
			Gordura = gord;
			PorcaoPadrao = porcaoPadrao;
			NomeUnidade = nomeUnidade;
		}

		public override string ToString()
		{
			var desc = "";
			desc += Nome + ". Kcal: " + Kcal.ToString("##0.00") + ". Prot: " + Proteina.ToString("##0.00") + ". Carbo: " + Carboidrato.ToString("##0.00") + ". Gordura: " + Gordura.ToString("##0.00");
			return desc;
		}
	}
}
