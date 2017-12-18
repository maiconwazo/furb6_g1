using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.IO;
using System.Reflection;
using IniParser;
using IniParser.Model;
using System.Windows.Forms;
using Servidor.Library;
using Cliente.ClientModels;
using System.Security.Cryptography;

namespace Cliente
{
	public class ServerMethods
	{
		public static User UsuarioAtual;
		public static ServerMethods _SERVERMETHODS;
		public static int _SESSION;
		private TcpClient connection;

		private string server;
		private int port;
		private StreamWriter Writer;
		private StreamReader Reader;
		public bool ConexaoOK;
		public string LastMessage;

		public class EncryptInfo
		{
			public string Content { get; set; }
			public string Subject { get; set; }
			public string SymmetricKeyName { get; set; }
			public string SymmetricKey { get; set; }
			public string IniVector { get; set; }
		}

		public ServerMethods(string server, int port)
		{
			this.ConexaoOK = false;
			this.server = server;
			this.port = port;

			this.connection = new TcpClient();
			StartConnection();
			if (ConexaoOK)
				ConexaoOK = TestConnection();

			StopConnection();
		}

		public void StartConnection()
		{
			try
			{
				this.connection = new TcpClient(server, port);
				this.Reader = new StreamReader(connection.GetStream(), Encoding.UTF8);
				this.Writer = new StreamWriter(connection.GetStream(), Encoding.UTF8);
				PostInt(_SESSION);
				Finish();

				GetBool();
				this.ConexaoOK = true;
			}
			catch (Exception e)
			{
				ConexaoOK = false;
			}
		}

		public void StopConnection()
		{
			if (ConexaoOK)
			{
				PostAction(Actions.aEnd);
				this.connection.Close();
			}
		}


		public bool CreateUser(string name, string userName, string password, Level hierarquia)
		{
			StartConnection();
			if (PostAction(Actions.aCreateUser))
			{
				PostString(name);
				PostString(userName);
				PostString(password);
				PostLevel(hierarquia);
				Finish();
			}

			StopConnection();
			return true;
		}

		public bool TestConnection()
		{
			PostAction(Actions.aNone);
			return GetBool();
		}

		public static ServerMethods GetServerMethods()
		{
			if (_SERVERMETHODS == null)
			{
				_SESSION = 0;
				DialogResult configurado = DialogResult.OK;
				var iniName = "Configuration.ini";
				var iniPath = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location) + "\\" + iniName;
				if (!File.Exists(iniPath))
				{
					IPConfig ipConfig = new IPConfig(iniPath, iniName);
					configurado = ipConfig.ShowDialog();
				}

				if (configurado == DialogResult.OK)
				{
					var iniFile = new FileIniDataParser();
					IniData data = iniFile.ReadFile(iniName);
					if (data["Connection"]["server"] != null && data["Connection"]["server"] != null)
						_SERVERMETHODS = new ServerMethods(data["Connection"]["server"], int.Parse(data["Connection"]["port"]));
				}
			}

			return _SERVERMETHODS;
		}

		public bool Authenticate(string userName, string password)
		{
			StartConnection();
			PostAction(Actions.aLogin);
			PostString(userName);
			PostString(password);
			Finish();

			bool autenticado = GetBool();
			if (autenticado)
			{
				_SESSION = GetInt();
				UsuarioAtual = new User() { Id = GetInt(), Name = GetString(), UserName = userName };
				StopConnection();

				StartConnection();
				PostAction(Actions.aPublicKey);
				if (!GetBool())
				{
					PostString(ClientSecurity.GenerateRSAKey(userName));
					Finish();
				}
				StopConnection();

				return true;
			}
			else
			{
				this.LastMessage = GetString();
				StopConnection();
				return false;
			}
		}

		public bool TemPermissao(Actions action)
		{
			StartConnection();

			PostAction(Actions.aVerifyPermission);
			PostAction(action);
			var temPermissao = GetBool();
			StopConnection();

			return temPermissao;
		}

		public List<Mensagem> GetAllMensagens(bool enviadas)
		{
			var lista = new List<Mensagem>();
			StartConnection();
			if (PostAction(Actions.aAllMessages))
			{
				PostBool(enviadas);
				Finish();

				while (GetBool())
				{
					var msg = new Mensagem()
					{
						Id = GetInt(),
						SenderId = GetInt(),
						SenderName = GetString(),
						ReceiverId = GetInt(),
						ReceiverName = GetString(),
						Subject = GetString(),
						Content = GetString(),
						TimeStamp = GetDateTime(),
						SymmetricKeyName = GetString(),
						SymmetricKey = GetString(),
						VetorIni = GetString(),
						Sent = enviadas
					};
					lista.Add(msg);
				}

				PostBool(true);
				Finish();

				StopConnection();

				foreach (var m in lista)
					m.Traduzir();

				return lista;
			}

			StartConnection();
			return null;
		}

		public List<User> GetUserList()
		{
			StartConnection();
			if (PostAction(Actions.aUserList))
			{
				var lista = new List<User>();
				lista.Add(new User());
				while (GetBool())
				{
					lista.Add(new User()
					{
						Id = GetInt(),
						Name = GetString(),
						UserName = GetString()
					});
				}

				StopConnection();
				return lista;
			}

			StopConnection();
			return null;
		}

		public void SendMessage(int userId, string subject, string content)
		{
			var encrytedContent = EncryptContent(subject, content, userId);
			StartConnection();
			if (PostAction(Actions.aSendMessage))
			{
				PostInt(userId);
				PostString(encrytedContent.Subject);
				PostString(encrytedContent.Content);
				PostString(encrytedContent.SymmetricKeyName);
				PostString(encrytedContent.SymmetricKey);
				PostString(encrytedContent.IniVector);
				Finish();
			}

			StopConnection();
		}

		public string GetAESKeyName(int otherUserId)
		{
			StartConnection();
			var result = "";
			if (PostAction(Actions.aSymmetricName))
			{
				PostInt(otherUserId);
				Finish();
				result = GetString();
			}
			StopConnection();

			return result;
		}

		public EncryptInfo EncryptContent(string subject, string content, int destinatary)
		{
			StartConnection();
			if (PostAction(Actions.aSymmetricName))
			{
				PostInt(destinatary);
				Finish();

				var keyName = GetString();

				string keyStr = "";
				var key = ClientSecurity.LoadSimmetricKey(keyName, out keyStr, out keyName);

				byte[] iv = Aes.Create().IV;
				var encryptedContent = ClientSecurity.EncryptAes(content, key, iv);
				var encryptedSubject = ClientSecurity.EncryptAes(subject, key, iv);

				StopConnection();
				return new EncryptInfo() { Content = encryptedContent, Subject = encryptedSubject, IniVector = ClientSecurity.HexToString(iv), SymmetricKey = keyStr, SymmetricKeyName = keyName };
			}

			StopConnection();
			return new EncryptInfo();
		}

		public string GetString()
		{
			return Reader.ReadLine();
		}

		public DateTime GetDateTime()
		{
			return DateTime.Parse(Reader.ReadLine());
		}

		public bool GetBool()
		{
			return bool.Parse(Reader.ReadLine());
		}

		public int GetInt()
		{
			return int.Parse(Reader.ReadLine());
		}

		public void PostString(string str)
		{
			Writer.WriteLine(str);
		}

		public void PostLevel(Level level)
		{
			Writer.WriteLine(level);
		}

		public bool PostAction(Actions action)
		{
			Writer.WriteLine(action);
			Writer.Flush();

			if (action != Actions.aEnd)
			{
				var Ok = GetBool();
				if (!Ok)
					MessageBox.Show(null, GetString(), "Servidor");

				return Ok;
			}

			return true;
		}

		public void PostTimestamp(DateTime time)
		{
			Writer.WriteLine(time);
		}

		public void PostBool(bool boolean)
		{
			Writer.WriteLine(boolean);
		}

		public void PostInt(int integer)
		{
			Writer.WriteLine(integer);
		}

		public void Finish()
		{
			Writer.Flush();
		}
	}
}
