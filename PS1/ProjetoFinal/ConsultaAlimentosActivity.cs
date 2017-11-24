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
	[Activity(Label = "ConsultaAlimentosActivity")]
	public class ConsultaAlimentosActivity : Activity
	{
		protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			SetContentView(Resource.Layout.ConsultaAlimentos);

			ConexaoLocal conn = new ConexaoLocal();
			ListView lista = FindViewById<ListView>(Resource.Id.alimentos);
			lista.FastScrollEnabled = true;
			var alimentoAdapter = new ConsultaAlimentosAdapter(this, conn.GetAlimentosRefeicao(Intent.GetIntExtra("id_refeicao", 0)));
			lista.Adapter = alimentoAdapter;
		}
	}
}