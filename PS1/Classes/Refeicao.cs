using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesDieta
{
	public class Refeicao
	{
		public double NecessidadeProt;
		public double NecessidadeCarb;
		public double NecessidadeGord;
		public TipoRefeicao tipo;

		public Refeicao(TipoRefeicao tipoRefeicao, double Prot, double Carb, double Gord)
		{
			tipo = tipoRefeicao;

			var multiplicador = 0.0;
			switch (tipoRefeicao)
			{
				case TipoRefeicao.trCafe:
					multiplicador = 0.15;
					break;
				case TipoRefeicao.trLanche:
					multiplicador = 0.10;
					break;
				case TipoRefeicao.trAlmoco:
					multiplicador = 0.25;
					break;
				case TipoRefeicao.trPre:
					multiplicador = 0.20;
					break;
				case TipoRefeicao.trPos:
					multiplicador = 0.10;
					break;
				case TipoRefeicao.trCeia:
					multiplicador = 0.20;
					break;
			}

			NecessidadeProt = Prot * multiplicador;
			NecessidadeCarb = Carb * multiplicador;
			NecessidadeGord = Gord * multiplicador;
		}

		public void MontarAlimentos()
		{
			List<Alimento> alimentos = BuscarAlimentos();

			// MIN CAL =  alimentos[0].kcal + alimentos[1].kcal .. alimentos[n].kcal
			// alimentos[0].proteina + alimentos[1].proteina .. alimentos[n].proteina >= NecessidadeProt
			// alimentos.Carboidratos >= NecessidadeCarbo
			// alimentos.Gorduras >= NecessidadeGord
			// alimentos.Quantidade >= 0

			//{
			//
			//}
		}

		public List<Alimento> BuscarAlimentos()
		{
			var alimentos = new List<Alimento>();

			// sql - busca online

			return alimentos;
		}
	}
}
