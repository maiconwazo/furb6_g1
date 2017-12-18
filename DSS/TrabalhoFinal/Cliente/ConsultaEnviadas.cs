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
	public partial class ConsultaEnviadas : Form
	{
		ServerMethods methods = ServerMethods.GetServerMethods();
		public ConsultaEnviadas()
		{
			InitializeComponent();

			AtualizarMensagens();
		}

		private void btFechar_Click(object sender, EventArgs e)
		{
			Close();
		}

		public void AtualizarMensagens()
		{
			var lista = methods.GetAllMensagens(true);
			dbEnviadas.DataSource = lista;
		}

		private void dbEnviadas_DataBindingComplete(object sender, DataGridViewBindingCompleteEventArgs e)
		{
			dbEnviadas.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			dbEnviadas.Columns["TimeStamp"].Width = 100;
			dbEnviadas.Columns["SenderName"].Width = 130;
			dbEnviadas.Columns["ReceiverName"].Width = 130;
		}

		private void btAtualizarMsgs_Click(object sender, EventArgs e)
		{
			AtualizarMensagens();
		}

		private void dbEnviadas_DoubleClick(object sender, EventArgs e)
		{			
			new MensagemDetalhe((Mensagem)dbEnviadas.SelectedRows[0].DataBoundItem).ShowDialog();
		}
	}
}
