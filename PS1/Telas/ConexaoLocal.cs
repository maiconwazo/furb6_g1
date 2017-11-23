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
using SQLite;

namespace DietFit
{
    class ConexaoLocal
    {
        string pasta = System.Environment.GetFolderPath(System.Environment.SpecialFolder.Personal);

        public List<Dieta> GetDietas()
        {
            try
            {
                using (var conexao = new SQLiteConnection(System.IO.Path.Combine(pasta, "Deita.db")))
                {
                    return conexao.Query<Dieta>("select * from Dieta");
                }
            }
            catch (SQLiteException ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
                return null;
            }
        }

        public bool CreateDatabase()
        {
            try
            {
                using (var conexao = new SQLiteConnection(System.IO.Path.Combine(pasta, "Perfil.db")))
                {
                    conexao.CreateTable<Perfil>();
                    return true;
                }
            }
            catch(SQLiteException ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
                return false;
            }
        }

        public bool InserirPerfil(Perfil perfil)
        {
            try
            {
                using (var conexao = new SQLiteConnection(System.IO.Path.Combine(pasta, "Perfil.db")))
                {
                    conexao.Insert(perfil);
                    return true;
                }
            }
            catch (SQLiteException ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
                return false;
            }
        }

        
        public bool AtualizarPerfil(Perfil perfil)
        {
            try
            {
                using (var conexao = new SQLiteConnection(System.IO.Path.Combine(pasta, "Perfil.db")))
                {
                    //conexao.Query<Perfil>("UPDATE Perfil set Nome = ? Where Valor = ?", perfil.Nome);
                    return true;
                }
            }
            catch (SQLiteException ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
                return false;
            }
        }

        public bool DeletarPerfil(Perfil perfil)
        {
            try
            {
                using (var conexao = new SQLiteConnection(System.IO.Path.Combine(pasta, "Perfil.db")))
                {
                    conexao.Delete(perfil);
                    return true;
                }
            }
            catch (SQLiteException ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
                return false;
            }
        }

        public string GetPerfil(Perfil perfil)
        {
            String result = "";
            try
            {
                using (var conexao = new SQLiteConnection(System.IO.Path.Combine(pasta, "Perfil.db")))
                {
                    List<Perfil> query = conexao.Query<Perfil>("SELECT Nome FROM Perfil");
                    foreach(var nome in query)
                    {
                        result = nome.Nome;
                    }             
                    
                    return result;
                }
            }
            catch (SQLiteException ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
                return null;
            }
        }
    }
}