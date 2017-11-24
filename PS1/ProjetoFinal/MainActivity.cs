using Android.App;
using Android.Widget;
using Android.OS;
using Android.Views;

namespace ProjetoFinal
{
    [Activity(Label = "DietFit", MainLauncher = true)]
    public class MainActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
		{
			base.OnCreate(savedInstanceState);

			// Set our view from the "main" layout resource
			SetContentView(Resource.Layout.Main);

            Button btnDieta = FindViewById<Button>(Resource.Id.btnDieta);
            Button btnPerfil = FindViewById<Button>(Resource.Id.btnPerfl);
            Button btnConfig = FindViewById<Button>(Resource.Id.btnConfig);
            Button btnCredito = FindViewById<Button>(Resource.Id.btnCredito);

            btnDieta.Click += delegate
            {
                StartActivity(typeof(DietaActivity));
            };

            btnPerfil.Click += delegate
            {
                StartActivity(typeof(PerfilActivity));
            };

            btnCredito.Click += delegate
            {
                StartActivity(typeof(CreditosActivity));
            };
        }
    }
}

