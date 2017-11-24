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
using Android.Graphics;

namespace ProjetoFinal
{
	[Activity(Label = "Dieta")]
	public class DietaActivity : Activity
	{
		protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			// Create your application here
			SetContentView(Resource.Layout.Dieta);

			EditText edNome = FindViewById<EditText>(Resource.Id.edNomeDieta);
			Button btnGerar = FindViewById<Button>(Resource.Id.btnGerar);
			Button btnBulking = FindViewById<Button>(Resource.Id.btnBulking);
			Button btnCutting = FindViewById<Button>(Resource.Id.btnCutting);
			btnBulking.SetWidth((btnGerar.Width / 2) - 5);
			btnCutting.SetWidth((btnGerar.Width / 2) - 5);
			btnBulking.Left = btnGerar.Left;
			btnCutting.Left = btnGerar.Left + btnBulking.Width + 10;

			btnBulking.Pressed = true;
			btnCutting.Pressed = false;

			if (btnCutting.Pressed)
				btnCutting.SetBackgroundColor(Color.DarkCyan);
			else
				btnCutting.SetBackgroundColor(Color.DarkGreen);

			if (btnBulking.Pressed)
				btnBulking.SetBackgroundColor(Color.DarkCyan);
			else
				btnBulking.SetBackgroundColor(Color.DarkGreen);

			btnGerar.SetBackgroundColor(Color.DarkGreen);

			btnBulking.Click += delegate
				{
					btnBulking.Pressed = true;
					btnCutting.Pressed = false;

					if (btnCutting.Pressed)
						btnCutting.SetBackgroundColor(Color.DarkCyan);
					else
						btnCutting.SetBackgroundColor(Color.DarkGreen);

					if (btnBulking.Pressed)
						btnBulking.SetBackgroundColor(Color.DarkCyan);
					else
						btnBulking.SetBackgroundColor(Color.DarkGreen);
				};

			btnCutting.Click += delegate
			{
				btnCutting.Pressed = true;
				btnBulking.Pressed = false;

				if (btnCutting.Pressed)
					btnCutting.SetBackgroundColor(Color.DarkCyan);
				else
					btnCutting.SetBackgroundColor(Color.DarkGreen);

				if (btnBulking.Pressed)
					btnBulking.SetBackgroundColor(Color.DarkCyan);
				else
					btnBulking.SetBackgroundColor(Color.DarkGreen);
			};

			btnGerar.Click += delegate
			{
				ConexaoLocal conn = new ConexaoLocal();
				Perfil p = conn.GetPerfil();
				if (p != null)
				{
					if (edNome.Text == "")
					{
						Toast.MakeText(this, "Preencha o nome da dieta!", ToastLength.Short).Show();
					}
					else
					{
						var idDieta = p.GerarDieta(edNome.Text, btnBulking.Pressed ? Objetivo.oBulking : Objetivo.oCutting);
						Intent it = new Intent(this, typeof(ConsultaRefeicoesActivity));
						it.PutExtra("id_dieta", idDieta);
						StartActivity(it);
					}
				}
				else
				{
					new AlertDialog.Builder(this)
					.SetPositiveButton("Certo", (sender, args) =>
					{
						StartActivity(typeof(PerfilActivity));
					}
					).SetMessage("Preenchea primeiro os dados de perfil!").SetTitle("Atenção").Show();
				}
			};
		}
	}
}