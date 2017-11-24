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
	[Activity(Label = "ConsultaRefeicoes")]
	public class ConsultaRefeicoesActivity : Activity
	{
		protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			SetContentView(Resource.Layout.ConsultaRefeicoes);

			ConexaoLocal conn = new ConexaoLocal();
			ListView lista = FindViewById<ListView>(Resource.Id.refeicoes);
			lista.FastScrollEnabled = true;
			lista.ItemClick += RefeicaoListView_ItemClick;
			var refeicaoAdapcter = new ConsultaRefeicoesAdapter(this, conn.GetRefeicoes(Intent.GetIntExtra("id_dieta", 0)));
			lista.Adapter = refeicaoAdapcter;
		}

		private void RefeicaoListView_ItemClick(object sender, AdapterView.ItemClickEventArgs e)
		{
			Intent it = new Intent(this, typeof(ConsultaAlimentosActivity));
			it.PutExtra("id_refeicao", (int)e.Id);
			StartActivity(it);
		}
	}
}