namespace Cliente
{
	partial class CadastroUsuario
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
			this.edLogin = new System.Windows.Forms.TextBox();
			this.edSenha = new System.Windows.Forms.TextBox();
			this.gbHierarquia = new System.Windows.Forms.GroupBox();
			this.rbAdmin = new System.Windows.Forms.RadioButton();
			this.rbModerador = new System.Windows.Forms.RadioButton();
			this.rbBasic = new System.Windows.Forms.RadioButton();
			this.lbSenha = new System.Windows.Forms.Label();
			this.lbUserName = new System.Windows.Forms.Label();
			this.lbRepeat = new System.Windows.Forms.Label();
			this.edRepeat = new System.Windows.Forms.TextBox();
			this.btCriar = new System.Windows.Forms.Button();
			this.btFechar = new System.Windows.Forms.Button();
			this.lbNome = new System.Windows.Forms.Label();
			this.edNome = new System.Windows.Forms.TextBox();
			this.gbHierarquia.SuspendLayout();
			this.SuspendLayout();
			// 
			// edLogin
			// 
			this.edLogin.Location = new System.Drawing.Point(108, 38);
			this.edLogin.Name = "edLogin";
			this.edLogin.Size = new System.Drawing.Size(357, 20);
			this.edLogin.TabIndex = 2;
			// 
			// edSenha
			// 
			this.edSenha.Location = new System.Drawing.Point(108, 64);
			this.edSenha.Name = "edSenha";
			this.edSenha.PasswordChar = '*';
			this.edSenha.Size = new System.Drawing.Size(357, 20);
			this.edSenha.TabIndex = 3;
			// 
			// gbHierarquia
			// 
			this.gbHierarquia.Controls.Add(this.rbAdmin);
			this.gbHierarquia.Controls.Add(this.rbModerador);
			this.gbHierarquia.Controls.Add(this.rbBasic);
			this.gbHierarquia.Location = new System.Drawing.Point(12, 116);
			this.gbHierarquia.Name = "gbHierarquia";
			this.gbHierarquia.Size = new System.Drawing.Size(453, 56);
			this.gbHierarquia.TabIndex = 5;
			this.gbHierarquia.TabStop = false;
			this.gbHierarquia.Text = "Hierarquia";
			// 
			// rbAdmin
			// 
			this.rbAdmin.AutoSize = true;
			this.rbAdmin.Location = new System.Drawing.Point(303, 24);
			this.rbAdmin.Name = "rbAdmin";
			this.rbAdmin.Size = new System.Drawing.Size(126, 17);
			this.rbAdmin.TabIndex = 7;
			this.rbAdmin.Text = "Usuário administrador";
			this.rbAdmin.UseVisualStyleBackColor = true;
			// 
			// rbModerador
			// 
			this.rbModerador.AutoSize = true;
			this.rbModerador.Location = new System.Drawing.Point(156, 24);
			this.rbModerador.Name = "rbModerador";
			this.rbModerador.Size = new System.Drawing.Size(114, 17);
			this.rbModerador.TabIndex = 6;
			this.rbModerador.Text = "Usuário moderador";
			this.rbModerador.UseVisualStyleBackColor = true;
			// 
			// rbBasic
			// 
			this.rbBasic.AutoSize = true;
			this.rbBasic.Checked = true;
			this.rbBasic.Location = new System.Drawing.Point(19, 24);
			this.rbBasic.Name = "rbBasic";
			this.rbBasic.Size = new System.Drawing.Size(95, 17);
			this.rbBasic.TabIndex = 5;
			this.rbBasic.TabStop = true;
			this.rbBasic.Text = "Usuário básico";
			this.rbBasic.UseVisualStyleBackColor = true;
			// 
			// lbSenha
			// 
			this.lbSenha.AutoSize = true;
			this.lbSenha.Location = new System.Drawing.Point(61, 67);
			this.lbSenha.Name = "lbSenha";
			this.lbSenha.Size = new System.Drawing.Size(41, 13);
			this.lbSenha.TabIndex = 6;
			this.lbSenha.Text = "Senha:";
			// 
			// lbUserName
			// 
			this.lbUserName.AutoSize = true;
			this.lbUserName.Location = new System.Drawing.Point(12, 41);
			this.lbUserName.Name = "lbUserName";
			this.lbUserName.Size = new System.Drawing.Size(90, 13);
			this.lbUserName.TabIndex = 7;
			this.lbUserName.Text = "Nome de usuário:";
			// 
			// lbRepeat
			// 
			this.lbRepeat.AutoSize = true;
			this.lbRepeat.Location = new System.Drawing.Point(26, 93);
			this.lbRepeat.Name = "lbRepeat";
			this.lbRepeat.Size = new System.Drawing.Size(76, 13);
			this.lbRepeat.TabIndex = 9;
			this.lbRepeat.Text = "Repetir senha:";
			// 
			// edRepeat
			// 
			this.edRepeat.Location = new System.Drawing.Point(108, 90);
			this.edRepeat.Name = "edRepeat";
			this.edRepeat.PasswordChar = '*';
			this.edRepeat.Size = new System.Drawing.Size(357, 20);
			this.edRepeat.TabIndex = 4;
			// 
			// btCriar
			// 
			this.btCriar.Location = new System.Drawing.Point(309, 178);
			this.btCriar.Name = "btCriar";
			this.btCriar.Size = new System.Drawing.Size(75, 23);
			this.btCriar.TabIndex = 8;
			this.btCriar.Text = "Criar";
			this.btCriar.UseVisualStyleBackColor = true;
			this.btCriar.Click += new System.EventHandler(this.btCriar_Click);
			// 
			// btFechar
			// 
			this.btFechar.Location = new System.Drawing.Point(390, 178);
			this.btFechar.Name = "btFechar";
			this.btFechar.Size = new System.Drawing.Size(75, 23);
			this.btFechar.TabIndex = 9;
			this.btFechar.Text = "Fechar";
			this.btFechar.UseVisualStyleBackColor = true;
			this.btFechar.Click += new System.EventHandler(this.btFechar_Click);
			// 
			// lbNome
			// 
			this.lbNome.AutoSize = true;
			this.lbNome.Location = new System.Drawing.Point(64, 15);
			this.lbNome.Name = "lbNome";
			this.lbNome.Size = new System.Drawing.Size(38, 13);
			this.lbNome.TabIndex = 13;
			this.lbNome.Text = "Nome:";
			// 
			// edNome
			// 
			this.edNome.Location = new System.Drawing.Point(108, 12);
			this.edNome.Name = "edNome";
			this.edNome.Size = new System.Drawing.Size(357, 20);
			this.edNome.TabIndex = 1;
			// 
			// CadastroUsuario
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(477, 209);
			this.Controls.Add(this.lbNome);
			this.Controls.Add(this.edNome);
			this.Controls.Add(this.btFechar);
			this.Controls.Add(this.btCriar);
			this.Controls.Add(this.lbRepeat);
			this.Controls.Add(this.edRepeat);
			this.Controls.Add(this.lbUserName);
			this.Controls.Add(this.lbSenha);
			this.Controls.Add(this.gbHierarquia);
			this.Controls.Add(this.edSenha);
			this.Controls.Add(this.edLogin);
			this.MaximumSize = new System.Drawing.Size(493, 248);
			this.MinimumSize = new System.Drawing.Size(493, 248);
			this.Name = "CadastroUsuario";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "CadastroUsuario";
			this.gbHierarquia.ResumeLayout(false);
			this.gbHierarquia.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox edLogin;
		private System.Windows.Forms.TextBox edSenha;
		private System.Windows.Forms.GroupBox gbHierarquia;
		private System.Windows.Forms.RadioButton rbAdmin;
		private System.Windows.Forms.RadioButton rbModerador;
		private System.Windows.Forms.RadioButton rbBasic;
		private System.Windows.Forms.Label lbSenha;
		private System.Windows.Forms.Label lbUserName;
		private System.Windows.Forms.Label lbRepeat;
		private System.Windows.Forms.TextBox edRepeat;
		private System.Windows.Forms.Button btCriar;
		private System.Windows.Forms.Button btFechar;
		private System.Windows.Forms.Label lbNome;
		private System.Windows.Forms.TextBox edNome;
	}
}