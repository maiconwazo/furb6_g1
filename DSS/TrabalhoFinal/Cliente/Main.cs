using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;
using System.IO;
using Servidor.Library;
using Cliente.ClientModels;

namespace Cliente
{
	public partial class frMain : Form
	{
		ServerMethods methods = ServerMethods.GetServerMethods();

		public frMain()
		{
			InitializeComponent();
			Text += " - " + ServerMethods.UsuarioAtual.DisplayName;
			btEscrever.Enabled = methods.TemPermissao(Actions.aSendMessage);
			btConsultarEnviadas.Enabled = methods.TemPermissao(Actions.aSendMessage);
			btCriarUsuario.Enabled = methods.TemPermissao(Actions.aCreateUser);

			AtualizarMensagens();
		}

		private void btEscrever_Click(object sender, EventArgs e)
		{
			new NewMessage().ShowDialog();
		}

		public void AtualizarMensagens()
		{
			var lista = methods.GetAllMensagens(false);
			dgRecebidas.DataSource = lista;
		}

		private void dgRecebidas_DataBindingComplete(object sender, DataGridViewBindingCompleteEventArgs e)
		{
			dgRecebidas.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			dgRecebidas.Columns["TimeStamp"].Width = 100;
			dgRecebidas.Columns["SenderName"].Width = 130;
			dgRecebidas.Columns["ReceiverName"].Width = 130;
		}

		private void dgRecebidas_DoubleClick(object sender, EventArgs e)
		{
			new MensagemDetalhe((Mensagem)dgRecebidas.SelectedRows[0].DataBoundItem).ShowDialog();
		}

		private void btCriarUsuario_Click(object sender, EventArgs e)
		{
			new CadastroUsuario().ShowDialog();
		}

		private void btConsultarEnviadas_Click(object sender, EventArgs e)
		{
			new ConsultaEnviadas().ShowDialog();
		}

		private void btAtualizarMsgs_Click(object sender, EventArgs e)
		{
			AtualizarMensagens();
		}
	}
}
