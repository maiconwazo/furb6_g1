using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DietFit
{
	public class AlimentoRefeicao
	{
		public Alimento Alimento;
		public decimal Quantidade;

		public decimal GetTotalKcal()
		{
			return Math.Round(this.Alimento.Kcal * Quantidade, Utils.C_CASAS);
		}

		public decimal GetTotalProteina()
		{
			return Math.Round(this.Alimento.Proteina * Quantidade, Utils.C_CASAS);
		}

		public decimal GetTotalCarboidrato()
		{
			return Math.Round(this.Alimento.Carboidrato * Quantidade, Utils.C_CASAS);
		}

		public decimal GetTotalGordura()
		{
			return Math.Round(this.Alimento.Gordura * Quantidade, Utils.C_CASAS);
		}

		public AlimentoRefeicao(Alimento alimento, decimal quantidade)
		{
			Alimento = alimento;
			Quantidade = quantidade;
		}

		public override string ToString()
		{
			var desc = "";
			desc += "Alimento: " + Alimento.ToString();
			desc += "\nQuantidade: " + (Alimento.PorcaoPadrao * Quantidade).ToString("###0.00") + " " + Alimento.NomeUnidade;
			desc += "\nKcal total: " + GetTotalKcal().ToString("###0.00");
			desc += "\nProt total: " + GetTotalProteina().ToString("###0.00");
			desc += "\nCarbo total: " + GetTotalCarboidrato().ToString("###0.00");
			desc += "\nGordura total: " + GetTotalGordura().ToString("###0.00");
			return desc;
		}
	}
}
