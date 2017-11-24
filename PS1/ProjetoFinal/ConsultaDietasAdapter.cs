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
	class ConsultaDietasAdapter : BaseAdapter<Dieta>
	{

		private readonly Activity context;
		public readonly List<Dieta> Dietas;
		public bool ModeDelete;

		public ConsultaDietasAdapter(Activity context, List<Dieta> dietas)
		{
			this.context = context;
			this.Dietas = dietas;
		}

		public override Dieta this[int position]
		{
			get
			{
				return Dietas[position];
			}
		}

		public override int Count
		{
			get
			{
				return Dietas.Count;
			}
		}

		public override long GetItemId(int position)
		{
			return Dietas[position].ID;
		}

		public override View GetView(int position, View convertView, ViewGroup parent)
		{
			var view = convertView ?? context.LayoutInflater.Inflate(Resource.Layout.DietaLayout, parent, false);

			var nome = view.FindViewById<TextView>(Resource.Id.nomeDieta);
			var kcal = view.FindViewById<TextView>(Resource.Id.kcal);

			nome.Text = Dietas[position].Nome;
			kcal.Text = "Total de calorias: " + Dietas[position].NecessidadeKcal.ToString("##0,00");

			return view;
		}

	}
}