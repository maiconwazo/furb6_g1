using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Servidor.Models;

namespace Servidor.DAO
{
	public class SymmetricKeyContext : DefaultContext<SymmetricKey>
	{
		public string GetKeyName(User u1, User u2)
		{
			int[] userIds = { u1.Id, u2.Id };
			var s = DataSet.Where(x => (userIds.Contains(x.SenderId)) || (userIds.Contains(x.ReceiverId))).OrderByDescending(x => x.Date).FirstOrDefault();
			if (s != null)
				return s.KeyName;
			else
				return "";
		}
	}
}
