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
	public partial class NewMessage : Form
	{
		public NewMessage()
		{
			InitializeComponent();
			cbUsuarios.DataSource = ServerMethods.GetServerMethods().GetUserList();
			cbUsuarios.DisplayMember = "DisplayName";
			cbUsuarios.ValueMember = "Id";
		}

		private void btFechar_Click(object sender, EventArgs e)
		{
			if (MessageBox.Show("Suas alterações serão descartadas. Deseja continuar?", "Confirmação", MessageBoxButtons.YesNo, MessageBoxIcon.Question,MessageBoxDefaultButton.Button1) == DialogResult.Yes)
			{
				Close();
			}
		}

		private void btEnviar_Click(object sender, EventArgs e)
		{
			int userId = ((User)cbUsuarios.SelectedItem).Id;
			string assunto = edAssunto.Text.Trim();
			string conteudo = edMessage.Text.Trim();

			if (userId != 0)
			{
				ServerMethods.GetServerMethods().SendMessage(userId, assunto, conteudo);
				MessageBox.Show(this, "Mensagem enviada com sucesso!", "Sucesso");
				Close();
			}
			else
			{
				MessageBox.Show(this, "Selecione um usuário!", "Atenção");
			}
		}
	}
}
