using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.IO;
using Servidor.Library;

namespace Servidor
{
	public class Server
	{
		TcpListener ServerListener;
		bool IsThreadRunning;

		public Server()
		{
			Security.GenerateServerKey();
			ServerListener = new TcpListener(IPAddress.Any, 3128);
			ServerListener.Start();
			IsThreadRunning = true;

			new Thread(new ThreadStart(ListenMethod))
			{
				IsBackground = true
			}.Start();
		}

		public void ListenMethod()
		{
			while (IsThreadRunning)
			{
				if (ServerListener.Pending())
				{
					TcpClient newClient = ServerListener.AcceptTcpClient();
					Thread resolveClient = new Thread(new ParameterizedThreadStart(HandleClient));
					resolveClient.Start(newClient);
				}
			}
		}

		public void HandleClient(object obj)
		{
			TcpClient client = (TcpClient)obj;

			StreamReader clientMessages = new StreamReader(client.GetStream(), Encoding.UTF8);
			StreamWriter serverMessages = new StreamWriter(client.GetStream(), Encoding.UTF8);
			MethodsClass methods = new MethodsClass(clientMessages, serverMessages);

			Actions action = Actions.aNone;
			while (action != Actions.aEnd)
			{
				if (client.Available > 0)
				{
					try
					{
						action = (Actions)Enum.Parse(typeof(Actions), clientMessages.ReadLine());
					}
					catch (Exception e)
					{
						action = Actions.aNone;
					}

					if (action != Actions.aEnd)
						methods.Execute(action);
				}
			}

			client.Close();
		}
	}
}
