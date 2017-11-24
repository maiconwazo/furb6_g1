using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace ProjetoFinal
{
	public class Alimento
	{
		[PrimaryKey, AutoIncrement]
		public int ID { get; set; }
		public string Nome { get; set; }
		public decimal Proteina { get; set; }
		public decimal Carboidrato { get; set; }
		public decimal Gordura { get; set; }
		public decimal Kcal { get { return (Proteina * 4) + (Carboidrato * 4) + (Gordura * 9); } }
		public decimal PorcaoPadrao { get; set; }
		public string NomeUnidade { get; set; }
		public int IndiceAux;

		public Alimento()
		{
		}

		public Alimento(string nome, decimal prot, decimal carbo, decimal gord, decimal porcaoPadrao, string nomeUnidade)
		{
			Nome = nome;
			Proteina = prot;
			Carboidrato = carbo;
			Gordura = gord;
			PorcaoPadrao = porcaoPadrao;
			NomeUnidade = nomeUnidade;

			ConexaoLocal conn = new ConexaoLocal();
			ID = conn.GravaAlimento(this);
		}

		public override string ToString()
		{
			var desc = "";
			desc += Nome + ". Kcal: " + Kcal.ToString("##0.00") + ". Prot: " + Proteina.ToString("##0.00") + ". Carbo: " + Carboidrato.ToString("##0.00") + ". Gordura: " + Gordura.ToString("##0.00");
			return desc;
		}
	}
}
