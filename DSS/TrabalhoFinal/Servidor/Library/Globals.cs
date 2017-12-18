using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Servidor.Models;
using Servidor.DAO;
using System.Threading;

namespace Servidor.Library
{
	public class Globals
	{
		public class LoginInfo
		{
			public bool Authenticated { get; set; }
			public int ContextID { get; set; }
			public int Id { get; set; }
			public string Name { get; set; }
			public string MessageError { get; set; }
		}

		private static int LAST_ID = 0;
		private static Dictionary<int, User> Session;

		public static LoginInfo Login(string userName, string password)
		{
			if (Session == null)
				Session = new Dictionary<int, User>();

			var user = new UserContext().GetUserByName(userName);
			if (user == null)
			{
				return new LoginInfo() { Authenticated = false, ContextID = 0, MessageError = "Usuário não existe!" };
			}

			if (user.Authenticate(password))
			{
				var id = LAST_ID++;
				Session.Add(id, user);
				return new LoginInfo() { Authenticated = true, ContextID = id, MessageError = "", Id = user.Id, Name = user.Name };
			}
			else
			{
				return new LoginInfo() { Authenticated = false, ContextID = 0, MessageError = user.MessageError };
			}
		}
		
		public static void Logout(int threadId)
		{
			if ((Session != null) && (Session.ContainsKey(threadId)))
			{
				Session.Remove(threadId);
			}
		}

		public static User GetUserBySessionId(int threadId)
		{
			if ((Session != null) && (Session.ContainsKey(threadId)))
			{
				return Session[threadId];
			}

			return null;
		}
	}
}
