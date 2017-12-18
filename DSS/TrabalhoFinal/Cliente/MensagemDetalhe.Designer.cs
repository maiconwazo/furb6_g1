namespace Cliente
{
	partial class MensagemDetalhe
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
			this.btFechar = new System.Windows.Forms.Button();
			this.lbAssunto = new System.Windows.Forms.Label();
			this.lbRemetente = new System.Windows.Forms.Label();
			this.edAssunto = new System.Windows.Forms.TextBox();
			this.edMessage = new System.Windows.Forms.TextBox();
			this.edRemetente = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// btFechar
			// 
			this.btFechar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.btFechar.Location = new System.Drawing.Point(497, 331);
			this.btFechar.Name = "btFechar";
			this.btFechar.Size = new System.Drawing.Size(75, 23);
			this.btFechar.TabIndex = 4;
			this.btFechar.Text = "Fechar";
			this.btFechar.UseVisualStyleBackColor = true;
			this.btFechar.Click += new System.EventHandler(this.btFechar_Click);
			// 
			// lbAssunto
			// 
			this.lbAssunto.AutoSize = true;
			this.lbAssunto.Location = new System.Drawing.Point(30, 41);
			this.lbAssunto.Name = "lbAssunto";
			this.lbAssunto.Size = new System.Drawing.Size(48, 13);
			this.lbAssunto.TabIndex = 10;
			this.lbAssunto.Text = "Assunto:";
			// 
			// lbRemetente
			// 
			this.lbRemetente.AutoSize = true;
			this.lbRemetente.Location = new System.Drawing.Point(16, 15);
			this.lbRemetente.Name = "lbRemetente";
			this.lbRemetente.Size = new System.Drawing.Size(62, 13);
			this.lbRemetente.TabIndex = 8;
			this.lbRemetente.Text = "Remetente:";
			// 
			// edAssunto
			// 
			this.edAssunto.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.edAssunto.Location = new System.Drawing.Point(84, 38);
			this.edAssunto.Name = "edAssunto";
			this.edAssunto.ReadOnly = true;
			this.edAssunto.Size = new System.Drawing.Size(488, 20);
			this.edAssunto.TabIndex = 2;
			// 
			// edMessage
			// 
			this.edMessage.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.edMessage.Location = new System.Drawing.Point(12, 64);
			this.edMessage.Multiline = true;
			this.edMessage.Name = "edMessage";
			this.edMessage.ReadOnly = true;
			this.edMessage.Size = new System.Drawing.Size(560, 261);
			this.edMessage.TabIndex = 3;
			// 
			// edRemetente
			// 
			this.edRemetente.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.edRemetente.Location = new System.Drawing.Point(84, 12);
			this.edRemetente.Name = "edRemetente";
			this.edRemetente.ReadOnly = true;
			this.edRemetente.Size = new System.Drawing.Size(488, 20);
			this.edRemetente.TabIndex = 1;
			// 
			// MensagemDetalhe
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(584, 361);
			this.Controls.Add(this.edRemetente);
			this.Controls.Add(this.btFechar);
			this.Controls.Add(this.lbAssunto);
			this.Controls.Add(this.lbRemetente);
			this.Controls.Add(this.edAssunto);
			this.Controls.Add(this.edMessage);
			this.MaximumSize = new System.Drawing.Size(1600, 900);
			this.MinimumSize = new System.Drawing.Size(600, 400);
			this.Name = "MensagemDetalhe";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.Windows.Forms.Button btFechar;
		private System.Windows.Forms.Label lbAssunto;
		private System.Windows.Forms.Label lbRemetente;
		private System.Windows.Forms.TextBox edAssunto;
		private System.Windows.Forms.TextBox edMessage;
		private System.Windows.Forms.TextBox edRemetente;
	}
}