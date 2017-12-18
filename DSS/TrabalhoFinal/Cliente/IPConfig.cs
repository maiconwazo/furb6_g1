using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using IniParser.Model;
using IniParser;
using System.IO;

namespace Cliente
{
	public partial class IPConfig : Form
	{
		public string IniPath;
		public string IniName;

		public IPConfig(string path, string name)
		{
			InitializeComponent();
			this.IniPath = path;
			this.IniName = name;
		}

		private void btGravar_Click(object sender, EventArgs e)
		{
			var file = File.Create(IniPath);
			file.Close();

			var iniFile = new FileIniDataParser();
			IniData data = iniFile.ReadFile(IniName);
			data["Connection"]["server"] = edServer.Text.Replace(",", ".").Replace(" ", "");
			data["Connection"]["port"] = edPort.Text;
			iniFile.WriteFile(Path.GetFileName(IniPath), data);

			DialogResult = DialogResult.OK;
			Close();
		}

		private void edPort_KeyPress(object sender, KeyPressEventArgs e)
		{
			e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
		}
	}
}
