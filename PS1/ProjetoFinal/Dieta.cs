using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace ProjetoFinal
{
	public class Dieta
	{
		[PrimaryKey, AutoIncrement]
		public int ID { get; set; }
		public string Nome { get; set; }
		public decimal NecessidadeKcal { get; set; }
		public decimal NecessidadeProt { get; set; }
		public decimal NecessidadeCarb { get; set; }
		public decimal NecessidadeGord { get; set; }

		public Dieta()
		{
		}

		public Dieta(string nome, decimal kcal, decimal prot, decimal carb, decimal gord)
		{
			NecessidadeKcal = kcal;
			NecessidadeProt = prot;
			NecessidadeCarb = carb;
			NecessidadeGord = gord;
			Nome = nome;

			ConexaoLocal conn = new ConexaoLocal();
			ID = conn.GravaDieta(this);
		}

		public void GerarRefeicoes()
		{
			var cafe = new Refeicao(ID, TipoRefeicao.trCafe, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			cafe.MontarAlimentos();

			var lancheManha = new Refeicao(ID, TipoRefeicao.trLancheManha, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			lancheManha.MontarAlimentos();

			var almoco = new Refeicao(ID,TipoRefeicao.trAlmoco, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			almoco.MontarAlimentos();

			var lancheTarde = new Refeicao(ID,TipoRefeicao.trLancheTarde, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			lancheTarde.MontarAlimentos();

			var preTreino = new Refeicao(ID, TipoRefeicao.trPre, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			preTreino.MontarAlimentos();

			var posTreino = new Refeicao(ID, TipoRefeicao.trPos, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			posTreino.MontarAlimentos();

			var ceia = new Refeicao(ID, TipoRefeicao.trCeia, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			ceia.MontarAlimentos();
		}
	}
}
