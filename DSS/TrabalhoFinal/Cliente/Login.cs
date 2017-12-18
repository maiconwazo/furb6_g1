using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cliente
{
	public partial class frLogin : Form
	{
		public frLogin()
		{
			InitializeComponent();
		}

		private void btEntrar_Click(object sender, EventArgs e)
		{
			if (ServerMethods.GetServerMethods().Authenticate(edUsername.Text, edPassword.Text))
			{
				this.Hide();
				new frMain().ShowDialog();
				this.Close();
			}
			else
				MessageBox.Show(this, ServerMethods.GetServerMethods().LastMessage, "Erro");
		}
	}
}
