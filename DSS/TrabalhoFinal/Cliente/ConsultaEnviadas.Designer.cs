namespace Cliente
{
	partial class ConsultaEnviadas
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
			this.dbEnviadas = new System.Windows.Forms.DataGridView();
			this.btFechar = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.dbEnviadas)).BeginInit();
			this.SuspendLayout();
			// 
			// dbEnviadas
			// 
			this.dbEnviadas.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.dbEnviadas.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dbEnviadas.Location = new System.Drawing.Point(12, 12);
			this.dbEnviadas.MultiSelect = false;
			this.dbEnviadas.Name = "dbEnviadas";
			this.dbEnviadas.ReadOnly = true;
			this.dbEnviadas.RowHeadersVisible = false;
			this.dbEnviadas.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
			this.dbEnviadas.Size = new System.Drawing.Size(560, 308);
			this.dbEnviadas.TabIndex = 4;
			this.dbEnviadas.DataBindingComplete += new System.Windows.Forms.DataGridViewBindingCompleteEventHandler(this.dbEnviadas_DataBindingComplete);
			this.dbEnviadas.DoubleClick += new System.EventHandler(this.dbEnviadas_DoubleClick);
			// 
			// btFechar
			// 
			this.btFechar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.btFechar.Location = new System.Drawing.Point(461, 326);
			this.btFechar.Name = "btFechar";
			this.btFechar.Size = new System.Drawing.Size(111, 23);
			this.btFechar.TabIndex = 6;
			this.btFechar.Text = "Fechar";
			this.btFechar.UseVisualStyleBackColor = true;
			this.btFechar.Click += new System.EventHandler(this.btFechar_Click);
			// 
			// ConsultaEnviadas
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(584, 361);
			this.Controls.Add(this.btFechar);
			this.Controls.Add(this.dbEnviadas);
			this.MinimumSize = new System.Drawing.Size(600, 400);
			this.Name = "ConsultaEnviadas";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "ConsultaEnviadas";
			((System.ComponentModel.ISupportInitialize)(this.dbEnviadas)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion
		private System.Windows.Forms.DataGridView dbEnviadas;
		private System.Windows.Forms.Button btFechar;
	}
}