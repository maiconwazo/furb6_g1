namespace Cliente
{
	partial class NewMessage
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
			this.edMessage = new System.Windows.Forms.TextBox();
			this.edAssunto = new System.Windows.Forms.TextBox();
			this.lbDestino = new System.Windows.Forms.Label();
			this.lbAssunto = new System.Windows.Forms.Label();
			this.btEnviar = new System.Windows.Forms.Button();
			this.btFechar = new System.Windows.Forms.Button();
			this.cbUsuarios = new System.Windows.Forms.ComboBox();
			this.SuspendLayout();
			// 
			// edMessage
			// 
			this.edMessage.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.edMessage.Location = new System.Drawing.Point(12, 64);
			this.edMessage.Multiline = true;
			this.edMessage.Name = "edMessage";
			this.edMessage.Size = new System.Drawing.Size(560, 256);
			this.edMessage.TabIndex = 3;
			// 
			// edAssunto
			// 
			this.edAssunto.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.edAssunto.Location = new System.Drawing.Point(84, 38);
			this.edAssunto.Name = "edAssunto";
			this.edAssunto.Size = new System.Drawing.Size(488, 20);
			this.edAssunto.TabIndex = 2;
			// 
			// lbDestino
			// 
			this.lbDestino.AutoSize = true;
			this.lbDestino.Location = new System.Drawing.Point(12, 15);
			this.lbDestino.Name = "lbDestino";
			this.lbDestino.Size = new System.Drawing.Size(66, 13);
			this.lbDestino.TabIndex = 3;
			this.lbDestino.Text = "Destinatário:";
			// 
			// lbAssunto
			// 
			this.lbAssunto.AutoSize = true;
			this.lbAssunto.Location = new System.Drawing.Point(30, 41);
			this.lbAssunto.Name = "lbAssunto";
			this.lbAssunto.Size = new System.Drawing.Size(48, 13);
			this.lbAssunto.TabIndex = 4;
			this.lbAssunto.Text = "Assunto:";
			// 
			// btEnviar
			// 
			this.btEnviar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.btEnviar.Location = new System.Drawing.Point(416, 326);
			this.btEnviar.Name = "btEnviar";
			this.btEnviar.Size = new System.Drawing.Size(75, 23);
			this.btEnviar.TabIndex = 4;
			this.btEnviar.Text = "Enviar";
			this.btEnviar.UseVisualStyleBackColor = true;
			this.btEnviar.Click += new System.EventHandler(this.btEnviar_Click);
			// 
			// btFechar
			// 
			this.btFechar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.btFechar.Location = new System.Drawing.Point(497, 326);
			this.btFechar.Name = "btFechar";
			this.btFechar.Size = new System.Drawing.Size(75, 23);
			this.btFechar.TabIndex = 5;
			this.btFechar.Text = "Fechar";
			this.btFechar.UseVisualStyleBackColor = true;
			this.btFechar.Click += new System.EventHandler(this.btFechar_Click);
			// 
			// cbUsuarios
			// 
			this.cbUsuarios.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.cbUsuarios.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbUsuarios.FormattingEnabled = true;
			this.cbUsuarios.Location = new System.Drawing.Point(84, 12);
			this.cbUsuarios.Name = "cbUsuarios";
			this.cbUsuarios.Size = new System.Drawing.Size(488, 21);
			this.cbUsuarios.TabIndex = 1;
			// 
			// NewMessage
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(584, 361);
			this.Controls.Add(this.cbUsuarios);
			this.Controls.Add(this.btFechar);
			this.Controls.Add(this.btEnviar);
			this.Controls.Add(this.lbAssunto);
			this.Controls.Add(this.lbDestino);
			this.Controls.Add(this.edAssunto);
			this.Controls.Add(this.edMessage);
			this.MaximumSize = new System.Drawing.Size(1600, 900);
			this.MinimumSize = new System.Drawing.Size(600, 400);
			this.Name = "NewMessage";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "NewMessage";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox edMessage;
		private System.Windows.Forms.TextBox edAssunto;
		private System.Windows.Forms.Label lbDestino;
		private System.Windows.Forms.Label lbAssunto;
		private System.Windows.Forms.Button btEnviar;
		private System.Windows.Forms.Button btFechar;
		private System.Windows.Forms.ComboBox cbUsuarios;
	}
}