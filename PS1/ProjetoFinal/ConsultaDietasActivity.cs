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
	[Activity(Label = "ConsultaDietasActivity")]
	public class ConsultaDietasActivity : Activity
	{
		protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			SetContentView(Resource.Layout.ConsultaDietas);

			ConexaoLocal conn = new ConexaoLocal();
			ListView lista = FindViewById<ListView>(Resource.Id.dietas);
			lista.FastScrollEnabled = true;
			var dietaAdapter = new ConsultaDietasAdapter(this, conn.GetDietas());
			lista.Adapter = dietaAdapter;

			Button btnAdd = FindViewById<Button>(Resource.Id.adicionarDieta);
			Button btnDel = FindViewById<Button>(Resource.Id.deletarDieta);
			btnAdd.Click += delegate
			{
				StartActivity(typeof(DietaActivity));
			};

			btnDel.Click += delegate
			{
				dietaAdapter.ModeDelete = true;
			};

			lista.ItemClick += delegate (object sender, AdapterView.ItemClickEventArgs e)
			{
				var msg = "";
				if (conn.DeletarDieta((int)e.Id))
				{
					msg = "Dieta deletada com sucesso!";
				}
				else
				{
					msg = "Erro ao deletar dieta!";
				}
				
				Toast.MakeText(this, msg, ToastLength.Short).Show();
				dietaAdapter.Dietas.Remove(dietaAdapter.Dietas[e.Position]);
				dietaAdapter.NotifyDataSetChanged();
			};

		}
	}
}