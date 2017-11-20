using Android.App;
using Android.Widget;
using Android.OS;

namespace DietFit
{
	[Activity(Label = "DietFit", MainLauncher = true)]
	public class MainActivity : Activity
	{
		protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			Perfil perfil = new Perfil();
			perfil.Altura = 170;
			perfil.Peso = 80;
			perfil.AtvFisica = IndiceAtividadeFisica.iaPoucoAtivo;
			perfil.Sexo = Sexo.sMasc;
			perfil.Idade = 21;
			perfil.GerarDieta(Objetivo.oBulking);

			SetContentView(Resource.Layout.Main);
			new AlertDialog.Builder(this).SetPositiveButton("Ok", (sender, args) => { }).SetMessage(perfil.Mensagem).SetTitle("Resultado").Show();
		}
	}
}

