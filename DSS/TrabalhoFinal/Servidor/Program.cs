using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Servidor.Models;
using Servidor.DAO;

namespace Servidor
{
	class Program
	{
		static void Main(string[] args)
		{
			var admin = new User();
			admin.UserName = "gchurros";
			admin.Name = "Maicon Santos da Silva";
			admin.Hierarchy = Library.Level.lvAdmin;
			admin.Generate("maicon123");

			Server s = new Server();
			Console.ReadLine();
		}
	}
}
