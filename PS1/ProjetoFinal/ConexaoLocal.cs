using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using SQLite;

namespace ProjetoFinal
{
	class ConexaoLocal
	{
		string path = System.Environment.GetFolderPath(System.Environment.SpecialFolder.Personal);
		SQLiteConnection conexao;

		public ConexaoLocal()
		{
			try
			{
				conexao = new SQLiteConnection(System.IO.Path.Combine(path, "banco.db"));
				conexao.CreateTable<Perfil>();
				conexao.CreateTable<Dieta>();
				conexao.CreateTable<Refeicao>();
				conexao.CreateTable<AlimentoRefeicao>();
				conexao.CreateTable<Alimento>();
			}
			catch (Exception e)
			{
				throw e;
			}
		}

		public Perfil GetPerfil()
		{
			List<Perfil> p = conexao.Query<Perfil>("select * from Perfil");
			if (p.Count > 0)
			{
				return p.First();
			}
			else
			{
				return null;
			}
		}

		public List<Dieta> GetDietas()
		{
			return conexao.Query<Dieta>("select * from Dieta");
		}

		public Dieta GetDieta(int codigoDieta)
		{
			var r = conexao.Query<Dieta>("select * from Dieta where ID = " + codigoDieta);
			if ((r.Count == 0) || (codigoDieta == 0))
				return null;
			else
				return r.First();
		}

		public bool DeletarDieta(int codigoDieta)
		{
			var dieta = GetDieta(codigoDieta);
			if (dieta != null)
			{
				conexao.Delete(dieta);
				return true;
			} else {
				return false;
			}
		} 

		public List<Refeicao> GetRefeicoes(int codigoDieta)
		{
			return conexao.Query<Refeicao>("select * from Refeicao where IdDieta = " + codigoDieta);
		}

		public Refeicao GetRefeicao(int codigoRefeicao)
		{
			var r = conexao.Query<Refeicao>("select * from Refeicao where ID = " + codigoRefeicao);
			if ((r.Count == 0) || (codigoRefeicao == 0))
				return null;
			else
				return r.First();
		}

		public AlimentoRefeicao GetAlimentoRefeicao(int codigoAlimento)
		{
			var a = conexao.Query<AlimentoRefeicao>("select * from AlimentoRefeicao where ID = " + codigoAlimento);
			if ((a.Count == 0) || (codigoAlimento == 0))
				return null;
			else
				return a.First();
		}

		public List<AlimentoRefeicao> GetAlimentosRefeicao(int codigoRefeicao)
		{
			return conexao.Query<AlimentoRefeicao>("select * from AlimentoRefeicao where IdRefeicao = " + codigoRefeicao);
		}

		public Alimento GetAlimento(int codigoAlimento)
		{
			var a = conexao.Query<Alimento>("select * from Alimento where ID = " + codigoAlimento);
			if ((a.Count == 0) || (codigoAlimento == 0))
				return null;
			else
				return a.First();
		}

		public int GravaPerfil(Perfil perfil)
		{
			return conexao.InsertOrReplace(perfil);
		}

		public int GravaDieta(Dieta dieta)
		{
			if (GetDieta(dieta.ID) == null)
			{
				var code = 0;
				var lista = conexao.Query<Dieta>("SELECT * FROM Dieta ORDER BY id DESC LIMIT 1");
				if (lista.Count == 0) code = 1;
				else code = lista.First().ID + 1;
				dieta.ID = code;
				conexao.Insert(dieta);
				return code;
			}
			else
			{
				return conexao.Update(dieta);
			}
		}

		public int GravaRefeicao(Refeicao refeicao)
		{
			if (GetRefeicao(refeicao.ID) == null)
			{
				var code = 0;
				var lista = conexao.Query<Refeicao>("SELECT * FROM Refeicao ORDER BY id DESC LIMIT 1");
				if (lista.Count == 0) code = 1;
				else code = lista.First().ID + 1;
				refeicao.ID = code;
				conexao.Insert(refeicao);
				return code;
			}
			else
			{
				return conexao.Update(refeicao);
			}
		}

		public int GravaAlimentoRefeicao(AlimentoRefeicao alimentoRefeicao)
		{
			if (GetAlimentoRefeicao(alimentoRefeicao.ID) == null)
			{
				var code = 0;
				var lista = conexao.Query<AlimentoRefeicao>("SELECT * FROM AlimentoRefeicao ORDER BY id DESC LIMIT 1");
				if (lista.Count == 0) code = 1;
				else code = lista.First().ID + 1;
				alimentoRefeicao.ID = code;
				conexao.Insert(alimentoRefeicao);
				return code;
			}
			else
			{
				return conexao.Update(alimentoRefeicao);
			}
		}

		public int GravaAlimento(Alimento alimento)
		{
			var a = conexao.Query<Alimento>("select * from Alimento where Nome = \"" + alimento.Nome + "\"");
			if ((a == null) || (a.Count == 0))
			{
				var code = 0;
				var lista = conexao.Query<Refeicao>("SELECT * FROM Alimento ORDER BY id DESC LIMIT 1");
				if (lista.Count == 0) code = 1;
				else code = lista.First().ID + 1;
				alimento.ID = code;
				conexao.Insert(alimento);
				return code;
			}
			else
			{
				return a.First().ID;
			}
		}
	}
}