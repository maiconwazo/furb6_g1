using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Servidor.DAO;
using Servidor.Library;

namespace Servidor.Models
{
	[Table("User")]
	public class User : Record
	{
		public string UserName { get; set; }
		public string Name { get; set; }
		public string Hash { get; set; }
		public string Salt { get; set; }
		public string PublicKey { get; set; }
		public Level Hierarchy { get; set; }
		public string UserSignature { get; set; }
		public ICollection<Message> Sent { get; set; }
		public ICollection<Message> Received { get; set; }
		public ICollection<SymmetricKey> KeysFirst { get; set; }
		public ICollection<SymmetricKey> KeysSecond { get; set; }

		public User()
		{
		}

		public bool Generate(string password)
		{
			using (var db = new UserContext())
			{
				if (db.UserAlredyExists(this.UserName))
				{
					MessageError = "Nome de usuário já está sendo usado.";
					return false;
				}

				this.Salt += new Random().Next();
				this.PublicKey = "";
				this.Hash = Security.GenerateHashSHA256(password + this.Salt);
				this.UserSignature = Security.ServerSign(this.UserName + this.Salt + this.Hierarchy);

				db.DataSet.Add(this);
				db.SaveChanges();

				return true;
			}
		}

		public bool Authenticate(string password)
		{
			if (Security.GenerateHashSHA256(password + this.Salt) != this.Hash)
			{
				MessageError = "Senha incorreta.";
				return false;
			}

			if (!Security.ServerAuthenticate(this.UserName + this.Salt + this.Hierarchy, this.UserSignature))
			{
				MessageError = "Não foi possível realizar login. Informações do usuário foram corrompidas. Entrar em contato com um administrador.";
				return false;
			}

			return true;
		}
	}
}
