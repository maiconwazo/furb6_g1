using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesDieta
{
	public class AlimentoRefeicao
	{
		public Alimento Alimento;
		public double Quantidade;

		public AlimentoRefeicao(Alimento alimento, int quantidade)
		{
			Alimento = alimento;
			Quantidade = quantidade;
		}
	}
}
