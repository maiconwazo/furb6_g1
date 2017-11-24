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
	[Activity(Label = "Perfil")]
	public class PerfilActivity : Activity
	{
		protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			// Create your application here
			SetContentView(Resource.Layout.Perfil);

			EditText edNome = FindViewById<EditText>(Resource.Id.edNome);
			EditText edIdade = FindViewById<EditText>(Resource.Id.edIdade);
			EditText edAltura = FindViewById<EditText>(Resource.Id.edAltura);
			EditText edPeso = FindViewById<EditText>(Resource.Id.edPeso);

			RadioButton rbFem = FindViewById<RadioButton>(Resource.Id.rbFem);
			RadioButton rbMasc = FindViewById<RadioButton>(Resource.Id.rbMasc);

			RadioButton rbLeve = FindViewById<RadioButton>(Resource.Id.rbLeve);
			RadioButton rbModerado = FindViewById<RadioButton>(Resource.Id.rbModerado);
			RadioButton rbElevado = FindViewById<RadioButton>(Resource.Id.rbElevado);
			RadioButton rbIntenso = FindViewById<RadioButton>(Resource.Id.rbIntenso);

			Button btnPerfil = FindViewById<Button>(Resource.Id.btnAddPerfil);

			ConexaoLocal con = new ConexaoLocal();
			Perfil perfil = con.GetPerfil();

			if (perfil != null)
			{
				edNome.Text = perfil.Nome;
				edIdade.Text = perfil.Idade + "";
				edAltura.Text = perfil.Altura + "";
				edPeso.Text = perfil.Peso + "";

				switch (perfil.Sexo)
				{
					case Sexo.sFem:
						rbFem.Checked = true;
						break;
					case Sexo.sMasc:
						rbMasc.Checked = true;
						break;
				}

				switch (perfil.AtvFisica)
				{
					case IndiceAtividadeFisica.iaSedentario:
						rbLeve.Checked = true;
						break;
					case IndiceAtividadeFisica.iaPoucoAtivo:
						rbModerado.Checked = true;
						break;
					case IndiceAtividadeFisica.iaAtivo:
						rbElevado.Checked = true;
						break;
					case IndiceAtividadeFisica.iaMuitoAtivo:
						rbIntenso.Checked = true;
						break;
				}
			}

			btnPerfil.Click += delegate
			{
				if (perfil == null)
				{
					perfil = new Perfil();
				}
				perfil.ID = 1;
				perfil.Nome = edNome.Text;
				perfil.Idade = Int32.Parse(edIdade.Text);
				perfil.Altura = Int32.Parse(edAltura.Text);
				perfil.Peso = Int32.Parse(edPeso.Text);
				perfil.Sexo = rbFem.Checked ? Sexo.sFem : Sexo.sMasc;
				perfil.AtvFisica = rbLeve.Checked ? IndiceAtividadeFisica.iaSedentario : rbModerado.Checked ? IndiceAtividadeFisica.iaPoucoAtivo : rbElevado.Checked ? IndiceAtividadeFisica.iaAtivo : IndiceAtividadeFisica.iaMuitoAtivo;

				con.GravaPerfil(perfil);
				StartActivity(typeof(MainActivity));
				Toast.MakeText(this, "Perfil salvo com sucesso!", ToastLength.Short).Show();
			};
		}
	}
}