using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;

namespace ProjetoFinal
{
	class ConsultaAlimentosAdapter : BaseAdapter<AlimentoRefeicao>
	{
		private readonly Activity context;
		private readonly List<AlimentoRefeicao> Alimentos;

		public ConsultaAlimentosAdapter(Activity context, List<AlimentoRefeicao> alimentos)
		{
			this.context = context;
			this.Alimentos = alimentos;
		}

		public override AlimentoRefeicao this[int position]
		{
			get
			{
				return Alimentos[position];
			}
		}

		public override int Count
		{
			get
			{
				return Alimentos.Count;
			}
		}

		public override long GetItemId(int position)
		{
			return Alimentos[position].ID;
		}

		public override View GetView(int position, View convertView, ViewGroup parent)
		{
			var view = convertView ?? context.LayoutInflater.Inflate(Resource.Layout.AlimentosLayout, parent, false);

			var nome = view.FindViewById<TextView>(Resource.Id.nomeAlimento);
			var quantidade = view.FindViewById<TextView>(Resource.Id.quantidade);
			var macros = view.FindViewById<TextView>(Resource.Id.macros);

			nome.Text = Alimentos[position].GetAlimento().Nome;
			quantidade.Text = "Quantidade: " + (Alimentos[position].Quantidade * Alimentos[position].GetAlimento().PorcaoPadrao).ToString("##0.00") + " " + Alimentos[position].GetAlimento().NomeUnidade;
			macros.Text = "Macros: Prot. " + Alimentos[position].GetAlimento().Proteina + " Carbo. " + Alimentos[position].GetAlimento().Carboidrato + " Gorduras: " + Alimentos[position].GetAlimento().Gordura;

			return view;
		}		

	}
}