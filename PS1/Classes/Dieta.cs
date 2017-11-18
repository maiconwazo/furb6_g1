using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesDieta
{
	public class Dieta
	{
		public double NecessidadeCal;
		public double NecessidadeProt;
		public double NecessidadeCarb;
		public double NecessidadeGord;

		public Dieta(double Cal, double Prot, double Carb, double Gord, int QtdRefeicoes)
		{
			NecessidadeCal = Cal;
			NecessidadeProt = Prot;
			NecessidadeCarb = Carb;
			NecessidadeGord = Gord;
		}

		public void GerarRefeicoes()
		{
			var cafe = new Refeicao(TipoRefeicao.trCafe, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			cafe.MontarAlimentos();

			var lanche = new Refeicao(TipoRefeicao.trLanche, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			lanche.MontarAlimentos();

			var almoco = new Refeicao(TipoRefeicao.trAlmoco, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			almoco.MontarAlimentos();

			var preTreino = new Refeicao(TipoRefeicao.trPre, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			preTreino.MontarAlimentos();

			var posTreino = new Refeicao(TipoRefeicao.trPos, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			posTreino.MontarAlimentos();

			var ceia = new Refeicao(TipoRefeicao.trCeia, NecessidadeProt, NecessidadeCarb, NecessidadeGord);
			ceia.MontarAlimentos();
		}
	}
}
