using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Servidor.Library;

namespace Cliente
{
	public partial class CadastroUsuario : Form
	{
		public CadastroUsuario()
		{
			InitializeComponent();
		}

		private void btFechar_Click(object sender, EventArgs e)
		{
			Close();
		}

		private void btCriar_Click(object sender, EventArgs e)
		{
			if (edSenha.Text == edRepeat.Text)
			{
				Level level = Level.lvBasic;
				if (rbBasic.Checked)
					level = Level.lvBasic;
				else
				if (rbModerador.Checked)
					level = Level.lvMod;
				else
				if (rbAdmin.Checked)
					level = Level.lvAdmin;

				if (ServerMethods.GetServerMethods().CreateUser(edNome.Text.Trim(), edLogin.Text.Trim(), edSenha.Text, level))
				{
					MessageBox.Show(null, "Usuário criado com sucesso!", "Sucesso");
				}
			}
			else
			{
				MessageBox.Show(null, "As senhas não conferem!", "Atenção");
			}
		}
	}
}
