using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Security.Cryptography;
using System.Threading.Tasks;
using System.IO;
using Servidor.DAO;

namespace Servidor
{
	public class Security
	{
		static string SERVER_KEY_NAME = "ServidorDSSCertificate";
		static int RSA = 24;

		public static void GenerateServerKey()
		{
			CspParameters container = new CspParameters(RSA);
			container.KeyContainerName = SERVER_KEY_NAME;
			container.Flags = CspProviderFlags.UseMachineKeyStore;
			container.ProviderName = "Microsoft Enhanced RSA and AES Cryptographic Provider";

			var rsa = new RSACryptoServiceProvider(container);
			rsa.PersistKeyInCsp = true;
		}

		public static string EncryptToUser(string content, int userId)
		{
			RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
			var u = new UserContext().GetUserById(userId);
			rsa.ImportCspBlob(StringToHex(u.PublicKey));
					
			return HexToString(rsa.Encrypt(Encoding.UTF8.GetBytes(content), true));
		}

		public static string ServerSign(string content)
		{
			CspParameters container = new CspParameters(RSA);
			container.KeyContainerName = SERVER_KEY_NAME;

			return HexToString(new RSACryptoServiceProvider(container).SignData(Encoding.UTF8.GetBytes(content), CryptoConfig.MapNameToOID("SHA256")));
		}

		public static bool ServerAuthenticate(string original, string signed)
		{
			CspParameters container = new CspParameters(RSA);
			container.KeyContainerName = SERVER_KEY_NAME;

			return new RSACryptoServiceProvider(2048, container).VerifyData(Encoding.UTF8.GetBytes(original), CryptoConfig.MapNameToOID("SHA256"), StringToHex(signed));
		}

		public static string GenerateHashSHA256(string content)
		{
			byte[] input = Encoding.ASCII.GetBytes(content);
			SHA256 sha = SHA256Managed.Create();
			byte[] output = sha.ComputeHash(input);

			return HexToString(output);
		}

		public static byte[] StringToHex(string content)
		{
			content = content.Replace(" ", "");
			byte[] arr = new byte[content.Length >> 1];

			for (int i = 0; i < content.Length >> 1; ++i)
			{
				arr[i] = (byte)((GetHexVal(content[i << 1]) << 4) + (GetHexVal(content[(i << 1) + 1])));
			}

			return arr;
		}

		public static int GetHexVal(char hex)
		{
			int val = (int)hex;
			return val - (val < 58 ? 48 : 55);
		}

		public static string HexToString(byte[] buffer)
		{
			var finalStr = "";
			for (int i = 0; i < buffer.Length; i++)
			{
				finalStr += String.Format("{0:X2}", buffer[i]);
				if ((i % 4) == 3) finalStr += " ";
			}

			return finalStr;
		}
	}
}
