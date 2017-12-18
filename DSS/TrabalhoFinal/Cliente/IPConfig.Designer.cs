namespace Cliente
{
	partial class IPConfig
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
			this.edPort = new System.Windows.Forms.TextBox();
			this.lbServer = new System.Windows.Forms.Label();
			this.lbPort = new System.Windows.Forms.Label();
			this.btGravar = new System.Windows.Forms.Button();
			this.edServer = new System.Windows.Forms.MaskedTextBox();
			this.SuspendLayout();
			// 
			// edPort
			// 
			this.edPort.Location = new System.Drawing.Point(67, 38);
			this.edPort.MaxLength = 5;
			this.edPort.Name = "edPort";
			this.edPort.Size = new System.Drawing.Size(58, 20);
			this.edPort.TabIndex = 2;
			this.edPort.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.edPort_KeyPress);
			// 
			// lbServer
			// 
			this.lbServer.AutoSize = true;
			this.lbServer.Location = new System.Drawing.Point(12, 15);
			this.lbServer.Name = "lbServer";
			this.lbServer.Size = new System.Drawing.Size(49, 13);
			this.lbServer.TabIndex = 2;
			this.lbServer.Text = "Servidor:";
			// 
			// lbPort
			// 
			this.lbPort.AutoSize = true;
			this.lbPort.Location = new System.Drawing.Point(26, 41);
			this.lbPort.Name = "lbPort";
			this.lbPort.Size = new System.Drawing.Size(35, 13);
			this.lbPort.TabIndex = 3;
			this.lbPort.Text = "Porta:";
			// 
			// btGravar
			// 
			this.btGravar.Location = new System.Drawing.Point(148, 62);
			this.btGravar.Name = "btGravar";
			this.btGravar.Size = new System.Drawing.Size(75, 23);
			this.btGravar.TabIndex = 4;
			this.btGravar.Text = "Gravar";
			this.btGravar.UseVisualStyleBackColor = true;
			this.btGravar.Click += new System.EventHandler(this.btGravar_Click);
			// 
			// edServer
			// 
			this.edServer.Location = new System.Drawing.Point(67, 12);
			this.edServer.Mask = "000.000.000.000";
			this.edServer.Name = "edServer";
			this.edServer.Size = new System.Drawing.Size(100, 20);
			this.edServer.TabIndex = 1;
			// 
			// IPConfig
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(235, 97);
			this.Controls.Add(this.edServer);
			this.Controls.Add(this.btGravar);
			this.Controls.Add(this.lbPort);
			this.Controls.Add(this.lbServer);
			this.Controls.Add(this.edPort);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
			this.Name = "IPConfig";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Configuração";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.Windows.Forms.TextBox edPort;
		private System.Windows.Forms.Label lbServer;
		private System.Windows.Forms.Label lbPort;
		private System.Windows.Forms.Button btGravar;
		private System.Windows.Forms.MaskedTextBox edServer;
	}
}