using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace ProjetoFinal
{
	public class Refeicao
	{
		[PrimaryKey, AutoIncrement]
		public int ID { get; set; }
		public int IdDieta { get; set; }
		public string Nome { get; set; }
		public decimal NecessidadeKcal { get; set; }
		public decimal NecessidadeProt { get; set; }
		public decimal NecessidadeCarb { get; set; }
		public decimal NecessidadeGord { get; set; }
		public TipoRefeicao Tipo { get; set; }

		public Refeicao()
		{
		}

		public Refeicao(int codigoDieta, TipoRefeicao tipoRefeicao, decimal kcal, decimal prot, decimal carb, decimal gord)
		{
			IdDieta = codigoDieta;
			Tipo = tipoRefeicao;

			decimal multiplicador = 0.0m;
			switch (tipoRefeicao)
			{
				case TipoRefeicao.trCafe:
					multiplicador = 0.15m;
					Nome = "Café da manhã";
					break;
				case TipoRefeicao.trLancheManha:
					multiplicador = 0.05m;
					Nome = "Lanche da manhã";
					break;
				case TipoRefeicao.trAlmoco:
					multiplicador = 0.25m;
					Nome = "Almoço";
					break;
				case TipoRefeicao.trLancheTarde:
					multiplicador = 0.05m;
					Nome = "Lanche da tarde";
					break;
				case TipoRefeicao.trPre:
					multiplicador = 0.20m;
					Nome = "Pré treino";
					break;
				case TipoRefeicao.trPos:
					multiplicador = 0.10m;
					Nome = "Pós treino";
					break;
				case TipoRefeicao.trCeia:
					multiplicador = 0.20m;
					Nome = "Ceia";
					break;
			}

			NecessidadeKcal = Math.Round(kcal * multiplicador, Utils.C_CASAS);
			NecessidadeProt = Math.Round(prot * multiplicador, Utils.C_CASAS);
			NecessidadeCarb = Math.Round(carb * multiplicador, Utils.C_CASAS);
			NecessidadeGord = Math.Round(gord * multiplicador, Utils.C_CASAS);

			ConexaoLocal conn = new ConexaoLocal();
			ID = conn.GravaRefeicao(this);
		}

		public void MontarAlimentos()
		{
			List<Alimento> alimentos = BuscarAlimentos();
			if (alimentos != null)
			{
				var posAlimentosBase = new int[alimentos.Count];

				var simplex = new decimal[4, alimentos.Count + 3 /* variáveis de excesso */ + 3 /* variáveis artificiais */ + 1 /* B */];

				/* preenche a tabela com os dados dos alimentos */
				for (var i = 0; i < alimentos.Count; i++)
				{
					posAlimentosBase[i] = -1;
					simplex[0, i] = alimentos[i].Proteina;
					simplex[1, i] = alimentos[i].Carboidrato;
					simplex[2, i] = alimentos[i].Gordura;
					simplex[3, i] = Math.Round((alimentos[i].Proteina * -1) + (alimentos[i].Carboidrato * -1) + (alimentos[i].Gordura * -1), Utils.C_CASAS);
				}

				simplex[0, alimentos.Count] = -1; simplex[0, alimentos.Count + 1] = 0; simplex[0, alimentos.Count + 2] = 0; simplex[0, alimentos.Count + 3] = 1; simplex[0, alimentos.Count + 4] = 0; simplex[0, alimentos.Count + 5] = 0; simplex[0, alimentos.Count + 6] = NecessidadeProt;
				simplex[1, alimentos.Count] = 0; simplex[1, alimentos.Count + 1] = -1; simplex[1, alimentos.Count + 2] = 0; simplex[1, alimentos.Count + 3] = 0; simplex[1, alimentos.Count + 4] = 1; simplex[1, alimentos.Count + 5] = 0; simplex[1, alimentos.Count + 6] = NecessidadeCarb;
				simplex[2, alimentos.Count] = 0; simplex[2, alimentos.Count + 1] = 0; simplex[2, alimentos.Count + 2] = -1; simplex[2, alimentos.Count + 3] = 0; simplex[2, alimentos.Count + 4] = 0; simplex[2, alimentos.Count + 5] = 1; simplex[2, alimentos.Count + 6] = NecessidadeGord;
				simplex[3, alimentos.Count] = 1; simplex[3, alimentos.Count + 1] = 1; simplex[3, alimentos.Count + 2] = 1; simplex[3, alimentos.Count + 3] = 0; simplex[3, alimentos.Count + 4] = 0; simplex[3, alimentos.Count + 5] = 0; simplex[3, alimentos.Count + 6] = (NecessidadeProt * -1) + (NecessidadeCarb * -1) + (NecessidadeGord * -1);

				var colunaTrab = 0;
				while (true)
				{
					colunaTrab = RetornarColunaTrabalho(simplex, alimentos.Count + 6);
					if (colunaTrab == -1)
						break;

					var pivo = RetornarPivo(simplex, colunaTrab);
					if (pivo[1] < alimentos.Count)
					{
						posAlimentosBase[pivo[1]] = pivo[0];
					}
					else if (posAlimentosBase.Contains(pivo[0]))
					{
						posAlimentosBase[Array.IndexOf(posAlimentosBase, pivo[0])] = -1;
					}

					var div = simplex[pivo[0], pivo[1]];
					for (int i = 0; i < simplex.GetLength(1); i++)
					{
						simplex[pivo[0], i] = Math.Round(simplex[pivo[0], i] / div, Utils.C_CASAS);
					}

					for (int i = 0; i < simplex.GetLength(0); i++)
					{
						if (i == pivo[0])
							continue;

						div = simplex[i, pivo[1]];
						for (int j = 0; j < simplex.GetLength(1); j++)
						{
							simplex[i, j] = Math.Round(Math.Round(simplex[i, j], Utils.C_CASAS) - Math.Round(simplex[pivo[0], j] * div, Utils.C_CASAS), Utils.C_CASAS);
							if ((simplex[i, j] != 0) && (Math.Abs(0 - simplex[i, j]) < 0.001m))
								simplex[i, j] = 0m;
						}
					}
				}

				decimal totKcal = 0.0m;
				decimal totProt = 0.0m;
				decimal totCarbo = 0.0m;
				decimal totGord = 0.0m;

				List<AlimentoRefeicao> alimentosRef = new List<AlimentoRefeicao>();
				for (var i = 0; i < alimentos.Count; i++)
				{
					var qtd = 0.0m;
					if (posAlimentosBase[i] > -1)
						qtd = simplex[posAlimentosBase[i], simplex.GetLength(1) - 1];

					if (qtd > 0)
					{
						alimentosRef.Add(new AlimentoRefeicao(ID, alimentos[i].ID, qtd));

						totKcal += alimentosRef[alimentosRef.Count - 1].GetTotalKcal();
						totProt += alimentosRef[alimentosRef.Count - 1].GetTotalProteina();
						totCarbo += alimentosRef[alimentosRef.Count - 1].GetTotalCarboidrato();
						totGord += alimentosRef[alimentosRef.Count - 1].GetTotalGordura();
					}
				}
			}
		}

		public List<Alimento> BuscarAlimentos()
		{
			Conexao con = new Conexao();
			var alimentos = con.BuscarAlimentos(Tipo);
			return alimentos;
		}

		public int RetornarColunaTrabalho(decimal[,] simplex, int qtdColunas)
		{
			var coluna = -1;
			var ultimaLinha = simplex.GetLength(0) - 1;

			var menor = simplex[ultimaLinha, 0];
			if (menor < 0)
			{
				coluna = 0;
			}
			for (var i = 1; i < qtdColunas; i++)
			{
				if ((simplex[ultimaLinha, i] < menor) && (simplex[ultimaLinha, i] < 0))
				{
					menor = simplex[ultimaLinha, i];
					coluna = i;
				}
			}

			return coluna;
		}


		public int[] RetornarPivo(decimal[,] simplex, int colunaTrab)
		{
			var pivo = new int[2];
			pivo[1] = colunaTrab;

			decimal menor = -1.0m;
			if (simplex[0, colunaTrab] > 0)
				menor = simplex[0, simplex.GetLength(1) - 1] / simplex[0, colunaTrab];

			for (var i = 1; i < 3; i++)
			{
				decimal divisao = 0.0m;
				if (simplex[i, colunaTrab] > 0)
					divisao = simplex[i, simplex.GetLength(1) - 1] / simplex[i, colunaTrab];

				if (((divisao < menor) && (divisao > 0)) || ((divisao >= 0) && menor < 0))
				{
					menor = divisao;
					pivo[0] = i;
				}
			}

			return pivo;
		}
	}
}
