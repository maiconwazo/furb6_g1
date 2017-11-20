using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DietFit
{
	public class Dieta
	{
		public decimal NecessidadeKcal;
		public decimal NecessidadeProt;
		public decimal NecessidadeCarb;
		public decimal NecessidadeGord;
		public string Mensagem;

		public Dieta(decimal kcal, decimal prot, decimal carb, decimal gord)
		{
			NecessidadeKcal = kcal;
			NecessidadeProt = prot;
			NecessidadeCarb = carb;
			NecessidadeGord = gord;
		}

		public void GerarRefeicoes()
		{
			var cafe = new Refeicao(TipoRefeicao.trCafe, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			cafe.MontarAlimentos();
			Mensagem = cafe.Mensagem;

			//var lancheManha = new Refeicao(TipoRefeicao.trLancheManha, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			//lancheManha.MontarAlimentos();

			//var almoco = new Refeicao(TipoRefeicao.trAlmoco, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			//almoco.MontarAlimentos();

			//var lancheTarde = new Refeicao(TipoRefeicao.trLancheTarde, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			//lancheTarde.MontarAlimentos();

			//var preTreino = new Refeicao(TipoRefeicao.trPre, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			//preTreino.MontarAlimentos();

			//var posTreino = new Refeicao(TipoRefeicao.trPos, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			//posTreino.MontarAlimentos();

			//var ceia = new Refeicao(TipoRefeicao.trCeia, NecessidadeKcal, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			//ceia.MontarAlimentos();
		}
	}
}
