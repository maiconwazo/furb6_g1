using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Servidor.Models;

namespace Servidor.DAO
{
	public class UserContext : DefaultContext<User>
	{
		public bool UserAlredyExists(string userName)
		{
			if (DataSet.Where(x => x.UserName == userName).FirstOrDefault() != null)
				return true;
			else
				return false;
		}

		public User GetUserByName(string userName)
		{
			return DataSet.FirstOrDefault(x => x.UserName == userName);
		}

		public User GetUserById(int id)
		{
			return DataSet.FirstOrDefault(x => x.Id == id);
		}

		public void DeleteUser(string userName)
		{
			var user = DataSet.FirstOrDefault(x => x.UserName == userName);
			if (user != null)
			{
				DataSet.Remove(user);
				SaveChanges();
			}
		}

		public List<User> GetUserList(int actualId)
		{
			return DataSet.Where(x => x.PublicKey != "" && x.Id != actualId).ToList();
		}
	}
}
