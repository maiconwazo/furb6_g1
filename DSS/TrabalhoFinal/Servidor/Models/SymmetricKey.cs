using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Servidor.Models
{
	[Table("SymmetricKey")]
	public class SymmetricKey: Record
	{
		public string KeyName { get; set; }
		public DateTime Date { get; set; }

		[ForeignKey("Sender")]
		public int SenderId { get; set; }

		[InverseProperty("KeysFirst")]
		public virtual User Sender { get; set; }

		[ForeignKey("Receiver")]
		public int ReceiverId { get; set; }

		[InverseProperty("KeysSecond")]
		public virtual User Receiver { get; set; }

		public SymmetricKey()
		{
		}
	}
}
