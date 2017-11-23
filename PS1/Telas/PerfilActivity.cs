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

namespace DietFit
{
    [Activity(Label = "Perfil")]
    public class PerfilActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.Perfil);

            Button btnPerfil = FindViewById<Button>(Resource.Id.btnAddPerfil);
            EditText edNome = FindViewById<EditText>(Resource.Id.edNome);
            ConexaoLocal con = new ConexaoLocal();
            con.CreateDatabase();
            Perfil perfil = new Perfil();            

            btnPerfil.Click += delegate
            {
                perfil.Nome = edNome.Text;
                con.InserirPerfil(perfil);
                StartActivity(typeof(TelaUserActivity));
            };
        }
    }
}