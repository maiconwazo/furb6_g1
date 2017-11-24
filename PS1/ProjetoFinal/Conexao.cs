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
using MySql.Data.MySqlClient;

namespace ProjetoFinal
{
	public class Conexao
	{
		MySqlConnection conexao;

		public string GetStringConexao()
		{
			return "Server=us-cdbr-iron-east-05.cleardb.net; Database=heroku_0e2db751905386c; Uid=bfae5379f6ace0; Pwd=2ca67453;";
		}

		public List<Alimento> BuscarAlimentos(TipoRefeicao tipo)
		{
			List<Alimento> listaAlimentos = null;

			string stringConexao = GetStringConexao();
			string consulta = "SELECT * FROM alimento ali left outer join TIPO_REFEICAO_ALIMENTO tipo on (tipo.bdcodali = ali.bdcodali) where tipo.bdcodtip = " + (int)tipo;
			try
			{
				conexao = new MySqlConnection(stringConexao);
				conexao.Open();

				MySqlDataReader leitor = null;
				MySqlCommand cmd = new MySqlCommand(consulta, conexao);
				leitor = cmd.ExecuteReader();

				listaAlimentos = new List<Alimento>();
				while (leitor.Read())
				{
					listaAlimentos.Add(new Alimento(leitor["bddesc"].ToString(), Decimal.Parse(leitor["bdprot"].ToString()), Decimal.Parse(leitor["bdcarbo"].ToString()), Decimal.Parse(leitor["bdgord"].ToString()), 1, "porções"));
				}
			}
			catch(Exception e)
			{
				var erro = e.Message;
			}

			return listaAlimentos;
		}
	}
}