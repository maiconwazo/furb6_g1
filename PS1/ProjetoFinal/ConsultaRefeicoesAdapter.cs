using Android.App;
using Android.Views;
using Android.Widget;
using System.Collections.Generic;

namespace ProjetoFinal
{
     public class ConsultaRefeicoesAdapter : BaseAdapter<Refeicao>
    {
        private readonly Activity context;
        private readonly List<Refeicao> Refeicoes;

		public ConsultaRefeicoesAdapter(Activity context, List<Refeicao> refeicoes)
        {
            this.context = context;
            this.Refeicoes = refeicoes;
		}

        public override Refeicao this[int position]
        {
            get
            {
                return Refeicoes[position];
            }
        }

        public override int Count
        {
            get
            {
                return Refeicoes.Count;
            }
        }

        public override long GetItemId(int position)
        {
            return Refeicoes[position].ID;
        }

        public override View GetView(int position, View convertView, ViewGroup parent)
        {
            var view = convertView ?? context.LayoutInflater.Inflate(Resource.Layout.RefeicoesLayout, parent, false);

            var nome = view.FindViewById<TextView>(Resource.Id.refeicao);
            var necessidade = view.FindViewById<TextView>(Resource.Id.necessidades);

			nome.Text = Refeicoes[position].Nome;
			necessidade.Text = "Necessidades calórica: " + Refeicoes[position].NecessidadeKcal;

            return view;
        }
    }
}