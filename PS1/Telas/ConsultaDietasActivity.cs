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
    [Activity(Label = "ConsultaDietas")]
    public class ConsultaDietasActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.ConsultaDietas);
            ListView listView = FindViewById<ListView>(Resource.Id.listaDietas);
            var ListAdapter = new Adapter(this, items);

        }
    }
}