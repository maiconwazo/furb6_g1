namespace Cliente
{
	partial class frLogin
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
			this.btEntrar = new System.Windows.Forms.Button();
			this.edPassword = new System.Windows.Forms.TextBox();
			this.edUsername = new System.Windows.Forms.TextBox();
			this.lbUserName = new System.Windows.Forms.Label();
			this.lbPassword = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// btEntrar
			// 
			this.btEntrar.Location = new System.Drawing.Point(250, 64);
			this.btEntrar.Name = "btEntrar";
			this.btEntrar.Size = new System.Drawing.Size(75, 23);
			this.btEntrar.TabIndex = 3;
			this.btEntrar.Text = "Entrar";
			this.btEntrar.UseVisualStyleBackColor = true;
			this.btEntrar.Click += new System.EventHandler(this.btEntrar_Click);
			// 
			// edPassword
			// 
			this.edPassword.Location = new System.Drawing.Point(108, 38);
			this.edPassword.Name = "edPassword";
			this.edPassword.PasswordChar = '*';
			this.edPassword.Size = new System.Drawing.Size(217, 20);
			this.edPassword.TabIndex = 2;
			// 
			// edUsername
			// 
			this.edUsername.Location = new System.Drawing.Point(108, 12);
			this.edUsername.Name = "edUsername";
			this.edUsername.Size = new System.Drawing.Size(217, 20);
			this.edUsername.TabIndex = 1;
			// 
			// lbUserName
			// 
			this.lbUserName.AutoSize = true;
			this.lbUserName.Location = new System.Drawing.Point(12, 15);
			this.lbUserName.Name = "lbUserName";
			this.lbUserName.Size = new System.Drawing.Size(90, 13);
			this.lbUserName.TabIndex = 3;
			this.lbUserName.Text = "Nome de usuário:";
			// 
			// lbPassword
			// 
			this.lbPassword.AutoSize = true;
			this.lbPassword.Location = new System.Drawing.Point(61, 41);
			this.lbPassword.Name = "lbPassword";
			this.lbPassword.Size = new System.Drawing.Size(41, 13);
			this.lbPassword.TabIndex = 4;
			this.lbPassword.Text = "Senha:";
			// 
			// frLogin
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(337, 97);
			this.Controls.Add(this.lbPassword);
			this.Controls.Add(this.lbUserName);
			this.Controls.Add(this.edUsername);
			this.Controls.Add(this.edPassword);
			this.Controls.Add(this.btEntrar);
			this.Name = "frLogin";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Autenticação";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button btEntrar;
		private System.Windows.Forms.TextBox edPassword;
		private System.Windows.Forms.TextBox edUsername;
		private System.Windows.Forms.Label lbUserName;
		private System.Windows.Forms.Label lbPassword;
	}
}