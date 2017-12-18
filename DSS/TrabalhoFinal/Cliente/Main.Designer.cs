namespace Cliente
{
	partial class frMain
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.dgRecebidas = new System.Windows.Forms.DataGridView();
			this.btEscrever = new System.Windows.Forms.Button();
			this.btConsultarEnviadas = new System.Windows.Forms.Button();
			this.btAtualizarMsgs = new System.Windows.Forms.Button();
			this.btCriarUsuario = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.dgRecebidas)).BeginInit();
			this.SuspendLayout();
			// 
			// dgRecebidas
			// 
			this.dgRecebidas.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.dgRecebidas.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgRecebidas.Location = new System.Drawing.Point(12, 41);
			this.dgRecebidas.MultiSelect = false;
			this.dgRecebidas.Name = "dgRecebidas";
			this.dgRecebidas.ReadOnly = true;
			this.dgRecebidas.RowHeadersVisible = false;
			this.dgRecebidas.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
			this.dgRecebidas.Size = new System.Drawing.Size(723, 404);
			this.dgRecebidas.TabIndex = 0;
			this.dgRecebidas.DataBindingComplete += new System.Windows.Forms.DataGridViewBindingCompleteEventHandler(this.dgRecebidas_DataBindingComplete);
			this.dgRecebidas.DoubleClick += new System.EventHandler(this.dgRecebidas_DoubleClick);
			// 
			// btEscrever
			// 
			this.btEscrever.Location = new System.Drawing.Point(12, 12);
			this.btEscrever.Name = "btEscrever";
			this.btEscrever.Size = new System.Drawing.Size(119, 23);
			this.btEscrever.TabIndex = 1;
			this.btEscrever.Text = "Nova mensagem";
			this.btEscrever.UseVisualStyleBackColor = true;
			this.btEscrever.Click += new System.EventHandler(this.btEscrever_Click);
			// 
			// btConsultarEnviadas
			// 
			this.btConsultarEnviadas.Location = new System.Drawing.Point(137, 12);
			this.btConsultarEnviadas.Name = "btConsultarEnviadas";
			this.btConsultarEnviadas.Size = new System.Drawing.Size(134, 23);
			this.btConsultarEnviadas.TabIndex = 2;
			this.btConsultarEnviadas.Text = "Consultar enviadas";
			this.btConsultarEnviadas.UseVisualStyleBackColor = true;
			this.btConsultarEnviadas.Click += new System.EventHandler(this.btConsultarEnviadas_Click);
			// 
			// btAtualizarMsgs
			// 
			this.btAtualizarMsgs.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.btAtualizarMsgs.Location = new System.Drawing.Point(599, 12);
			this.btAtualizarMsgs.Name = "btAtualizarMsgs";
			this.btAtualizarMsgs.Size = new System.Drawing.Size(136, 23);
			this.btAtualizarMsgs.TabIndex = 3;
			this.btAtualizarMsgs.Text = "Atualizar mensagens";
			this.btAtualizarMsgs.UseVisualStyleBackColor = true;
			this.btAtualizarMsgs.Click += new System.EventHandler(this.btAtualizarMsgs_Click);
			// 
			// btCriarUsuario
			// 
			this.btCriarUsuario.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.btCriarUsuario.Location = new System.Drawing.Point(468, 12);
			this.btCriarUsuario.Name = "btCriarUsuario";
			this.btCriarUsuario.Size = new System.Drawing.Size(125, 23);
			this.btCriarUsuario.TabIndex = 4;
			this.btCriarUsuario.Text = "Criar usuário";
			this.btCriarUsuario.UseVisualStyleBackColor = true;
			this.btCriarUsuario.Click += new System.EventHandler(this.btCriarUsuario_Click);
			// 
			// frMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(747, 457);
			this.Controls.Add(this.btCriarUsuario);
			this.Controls.Add(this.btAtualizarMsgs);
			this.Controls.Add(this.btConsultarEnviadas);
			this.Controls.Add(this.btEscrever);
			this.Controls.Add(this.dgRecebidas);
			this.Name = "frMain";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Consulta de mensagens";
			((System.ComponentModel.ISupportInitialize)(this.dgRecebidas)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.DataGridView dgRecebidas;
		private System.Windows.Forms.Button btEscrever;
		private System.Windows.Forms.Button btConsultarEnviadas;
		private System.Windows.Forms.Button btAtualizarMsgs;
		private System.Windows.Forms.Button btCriarUsuario;
	}
}

