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

namespace DietFit
{
    [Activity(Label = "Dieta")]
    public class DietaActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.Dieta);

            Button btnGerar = FindViewById<Button>(Resource.Id.btnGerar);
            Button btnBulking = FindViewById<Button>(Resource.Id.btnBulking);
            Button btnCutting = FindViewById<Button>(Resource.Id.btnCutting);
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
                StartActivity(typeof(ConsultaDietasActivity));
            };
        }
    }
}