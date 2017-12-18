using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cliente
{
	static class Program
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			if ((ServerMethods.GetServerMethods() == null) || (!ServerMethods.GetServerMethods().ConexaoOK))
				MessageBox.Show(null, "Não foi possível se conectar no servidor!", "Erro");
			else
				Application.Run(new frLogin());
		}
	}
}
