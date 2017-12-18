using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Servidor.Models;
using Servidor.Library;
using Servidor.DAO;
using System.Data.Entity;

namespace Servidor
{
	public class MethodsClass
	{
		StreamReader Reader;
		StreamWriter Writer;
		Actions Action;
		User ActualUser;

		public MethodsClass(StreamReader sr, StreamWriter sw)
		{
			this.Reader = sr;
			this.Writer = sw;
			this.ActualUser = Globals.GetUserBySessionId(GetInt());
			PostBool(true);
			Finish();
		}

		public void Execute(Actions action)
		{
			this.Action = action;
			if (HavePermission(this.Action))
			{
				PostBool(true);
				Finish();

				switch (Action)
				{
					case Actions.aNone:
						PostBool(true);
						Finish();
						break;
					case Actions.aCreateUser:
						CreateUser();
						break;
					case Actions.aDeleteUser:
						DeleteUser();
						break;
					case Actions.aLogin:
						Login();
						break;
					case Actions.aLogout:
						Logout();
						break;
					case Actions.aUserList:
						GetUserList();
						break;
					case Actions.aSendMessage:
						SendMessage();
						break;
					case Actions.aSymmetricName:
						PostString(GetSymmetricKeyName(GetInt()));
						Finish();
						break;
					case Actions.aMessageCount:
						GetMessageCount();
						break;
					case Actions.aAllMessages:
						GetAllMessages();
						break;
					case Actions.aVerifyPermission:
						PostBool(HavePermission(GetAction()));
						Finish();
						break;
					case Actions.aPublicKey:
						VerifyPublicKey();
						break;
				}
			}
			else
			{
				PostBool(false);
				PostString("Você não tem permissão pra realizar essa ação.");
				Finish();
			}
		}

		public string GetString()
		{
			return Reader.ReadLine();
		}

		public Actions GetAction()
		{
			var a = (Actions)Enum.Parse(typeof(Actions), GetString());
			PostBool(true);
			Finish();
			return a;
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

		public bool HavePermission(Actions action)
		{
			switch (action)
			{
				case Actions.aCreateUser:
				case Actions.aDeleteUser:
					return ActualUser.Hierarchy == Level.lvAdmin;
				case Actions.aSendMessage:
				case Actions.aUserList:
					return ActualUser.Hierarchy > Level.lvBasic;
				case Actions.aLogin:
				case Actions.aLogout:
				case Actions.aVerifyPermission:
				case Actions.aNone:
				case Actions.aAllMessages:
				case Actions.aSymmetricName:
				case Actions.aPublicKey:
					return true;
				default:
					return false;
			}
		}

		public void CreateUser()
		{
			string name = GetString();
			string userName = GetString();
			string passWord = GetString();
			Level hierarchy = (Level)Enum.Parse(typeof(Level), GetString());

			var u = new User();
			u.Name = name;
			u.UserName = userName;
			u.Hierarchy = hierarchy;

			if (u.Generate(passWord))
			{
				PostBool(true);
				Finish();
			}
			else
			{
				PostBool(false);
				Finish();

				PostString(u.MessageError);
				Finish();
			}
		}

		public void DeleteUser()
		{
			string userName = GetString();

			new UserContext().DeleteUser(userName);
			PostBool(true);
			Finish();
		}

		public void Login()
		{
			string userName = GetString();
			string passWord = GetString();
			var loginInfo = Globals.Login(userName, passWord);

			if (loginInfo.Authenticated)
			{
				PostBool(true);
				PostInt(loginInfo.ContextID);
				PostInt(loginInfo.Id);
				PostString(loginInfo.Name);
				Finish();
			}
			else
			{
				PostBool(false);
				PostString(loginInfo.MessageError);
				Finish();
			}
		}

		public void Logout()
		{
			int contextId = GetInt();
			Globals.Logout(contextId);
			PostBool(true);
		}

		public void VerifyPublicKey()
		{
			using (var db = new UserContext())
			{
				if (ActualUser.PublicKey == null || ActualUser.PublicKey == "")
				{
					PostBool(false);
					Finish();

					ActualUser.PublicKey = GetString();
					db.Entry(ActualUser).State = EntityState.Modified;
					db.SaveChanges();
				}
				else
				{
					PostBool(true);
					Finish();
				}
			}
		}

		public void GetUserList()
		{
			var list = new UserContext().GetUserList(ActualUser.Id);
			foreach (var u in list)
			{
				PostBool(true);
				PostInt(u.Id);
				PostString(u.Name);
				PostString(u.UserName);
			}

			PostBool(false);
			Finish();
		}

		public void SendMessage()
		{
			var destinataryId = GetInt();
			var subject = GetString();
			var message = GetString();
			var symmetricKeyName = GetString();
			var symmetricKey = GetString();
			var iniVector = GetString();

			if (destinataryId > 0)
			{
				User destinatary = new UserContext().GetUserById(destinataryId);
				if (destinatary != null)
				{
					var db = new MessageContext();
					Message msg = new Message();

					if (symmetricKey != "")
					{
						msg.SymmetricKey = Security.EncryptToUser(symmetricKey, destinataryId);

						var syContext = new SymmetricKeyContext();
						syContext.DataSet.Add(new SymmetricKey() { KeyName = symmetricKeyName, SenderId = ActualUser.Id, ReceiverId = destinataryId, Date = DateTime.Now });
						syContext.SaveChanges();
					}

					msg.Subject = subject;
					msg.Content = message;
					msg.IniVector = iniVector;
					msg.ReceiverId = destinatary.Id;
					msg.SenderId = ActualUser.Id;
					msg.TimeStamp = DateTime.Now;
					db.DataSet.Add(msg);
					db.SaveChanges();
				}
			}
		}

		public string GetSymmetricKeyName(int destinataryId)
		{
			var symmetricKeyName = new SymmetricKeyContext().GetKeyName(ActualUser, new UserContext().GetUserById(destinataryId));
			return symmetricKeyName;
		}

		public void GetMessageCount()
		{
			var db = new MessageContext();
			PostInt(db.DataSet.Count());
		}

		public void GetAllMessages()
		{
			var db = new MessageContext();
			var enviadas = GetBool();

			List<Message> lista = null;
			if (enviadas)
				lista = db.DataSet.Where(x => x.SenderId == ActualUser.Id).ToList();
			else
				lista = db.DataSet.Where(x => x.ReceiverId == ActualUser.Id).ToList();

			foreach (var m in lista)
			{
				PostBool(true);
				PostInt(m.Id);
				PostInt(m.Sender.Id);
				PostString(m.Sender.Name);
				PostInt(m.Receiver.Id);
				PostString(m.Receiver.Name);
				PostString(m.Subject);
				PostString(m.Content);
				PostTimestamp(m.TimeStamp);
				PostString(m.SymmetricKeyName);
				PostString(m.SymmetricKey);
				PostString(m.IniVector);
			}

			PostBool(false);
			Finish();

			GetBool();
		}
	}
}
