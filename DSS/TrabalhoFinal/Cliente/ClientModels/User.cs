using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cliente.ClientModels
{
	public class User
	{
		public int Id { get; set; }
		public string Name { get; set; }
		public string UserName { get; set; }
		public string DisplayName
		{
			get { if (Id == 0) return ""; else return Name + " (" + UserName + ")"; }
		}
	}
}

