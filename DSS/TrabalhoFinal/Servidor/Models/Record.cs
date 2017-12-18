using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Servidor.Models
{
	public class Record
	{
		[Key]
		public int Id { get; set; }

		[NotMapped]
		public string MessageError { get; set; }
	}
}
