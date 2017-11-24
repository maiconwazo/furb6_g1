using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace ProjetoFinal
{
	public class AlimentoRefeicao
	{
		[PrimaryKey, AutoIncrement]
		public int ID { get; set; }
		public int IdAlimento { get; set; }
		public int IdRefeicao { get; set; }
		public decimal Quantidade { get; set; }
		private Alimento alimento;
		
		public AlimentoRefeicao()
		{
		}

		public AlimentoRefeicao(int idRefeicao, int idAlimento, decimal quantidade)
		{
			IdRefeicao = idRefeicao;
			IdAlimento = idAlimento;
			Quantidade = quantidade;

			ConexaoLocal conexao = new ConexaoLocal();
			ID = conexao.GravaAlimentoRefeicao(this);
		}

		public Alimento GetAlimento()
		{
			if (alimento == null)
			{
				ConexaoLocal conn = new ConexaoLocal();
				alimento =  conn.GetAlimento(IdAlimento);
			}

			return alimento;
		}

		public decimal GetTotalKcal()
		{
			return Math.Round(GetAlimento().Kcal * Quantidade, Utils.C_CASAS);
		}

		public decimal GetTotalProteina()
		{
			return Math.Round(GetAlimento().Proteina * Quantidade, Utils.C_CASAS);
		}

		public decimal GetTotalCarboidrato()
		{
			return Math.Round(GetAlimento().Carboidrato * Quantidade, Utils.C_CASAS);
		}

		public decimal GetTotalGordura()
		{
			return Math.Round(GetAlimento().Gordura * Quantidade, Utils.C_CASAS);
		}

		public override string ToString()
		{
			var desc = "";
			desc += "Alimento: " + GetAlimento().ToString();
			desc += "\nQuantidade: " + (GetAlimento().PorcaoPadrao * Quantidade).ToString("###0.00") + " " + GetAlimento().NomeUnidade;
			desc += "\nKcal total: " + GetTotalKcal().ToString("###0.00");
			desc += "\nProt total: " + GetTotalProteina().ToString("###0.00");
			desc += "\nCarbo total: " + GetTotalCarboidrato().ToString("###0.00");
			desc += "\nGordura total: " + GetTotalGordura().ToString("###0.00");
			return desc;
		}
	}
}
