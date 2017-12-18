using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Servidor.DAO;

namespace Servidor.Models
{
	[Table("Message")]
	public class Message : Record
	{
		public string Subject { get; set; }
		public string Content { get; set; }
		public string IniVector { get; set; }
		public DateTime TimeStamp { get; set; }
		public string SymmetricKeyName { get; set; }
		public string SymmetricKey { get; set; }

		[ForeignKey("Sender")]
		public int SenderId { get; set; }

		[InverseProperty("Sent")]
		public virtual User Sender { get; set; }

		[ForeignKey("Receiver")]
		public int ReceiverId { get; set; }

		[InverseProperty("Received")]
		public virtual User Receiver { get; set; }

		public Message()
		{
		}
	}
}
