using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Cliente.ClientModels;

namespace Cliente
{
	public partial class MensagemDetalhe : Form
	{
		public Mensagem MensagemObj;
		public MensagemDetalhe(Mensagem msg)
		{
			InitializeComponent();
			this.MensagemObj = msg;

			edRemetente.Text = MensagemObj.SenderName;
			edAssunto.Text = MensagemObj.Subject;
			edMessage.Text = MensagemObj.Content;
		}

		private void btFechar_Click(object sender, EventArgs e)
		{
			Close();
		}
	}
}
