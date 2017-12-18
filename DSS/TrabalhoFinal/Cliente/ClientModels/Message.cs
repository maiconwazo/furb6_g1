using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Cliente.ClientModels
{
	public class Mensagem
	{
		[Browsable(false)]
		public int Id { get; set; }

		[DisplayName("Data/Hora")]
		public DateTime TimeStamp { get; set; }

		[DisplayName("Assunto")]
		public string Subject { get; set; }

		[Browsable(false)]
		public string Content { get; set; }
		
		[Browsable(false)]
		public string SymmetricKeyName { get; set; }

		[Browsable(false)]
		public string SymmetricKey { get; set; }

		[Browsable(false)]
		public int SenderId { get; set; }

		[DisplayName("Remetente")]
		public string SenderName { get; set; }

		[Browsable(false)]
		public int ReceiverId { get; set; }

		[DisplayName("Destinatário")]
		public string ReceiverName { get; set; }

		[Browsable(false)]
		public string VetorIni { get; set; }

		[Browsable(false)]
		public bool Sent { get; set; }

		public void Traduzir()
		{
			string keyStr;
			string IV;
			var AESKey = ClientSecurity.LoadSimmetricKey(ServerMethods.GetServerMethods().GetAESKeyName(Sent ? ReceiverId : SenderId), out keyStr, out IV);
			this.Subject = ClientSecurity.DecryptAes(ClientSecurity.FromBase64(Subject), AESKey, ClientSecurity.StringToHex(VetorIni));
			this.Content = ClientSecurity.DecryptAes(ClientSecurity.FromBase64(Content), AESKey, ClientSecurity.StringToHex(VetorIni));
		}
	}
}
