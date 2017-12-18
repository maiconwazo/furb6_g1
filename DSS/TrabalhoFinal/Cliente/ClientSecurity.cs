using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using Cliente.ClientModels;
using System.IO;
using System.Reflection;

namespace Cliente
{
	public class ClientSecurity
	{
		public static string PATH_AES = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location) + "\\";
		static int RSA = 24;

		public static void GenerateAESKey(out string key, out string name)
		{
			Aes myAes = Aes.Create();
			var keyBuffer = myAes.Key;
			key = HexToString(keyBuffer);
			name = "AES_" + Guid.NewGuid().ToString();

			var lista = new List<string>();
			if (File.Exists(PATH_AES + name))
			{
				File.Delete(PATH_AES + name);
			}

			lista.Add(key.Trim() + "; " + name);
			File.WriteAllLines(PATH_AES + name, lista);
		}

		public static bool ExistsRSAKey(string keyName)
		{
			var cspParams = new CspParameters
			{
				Flags = CspProviderFlags.UseExistingKey,
				KeyContainerName = keyName
			};

			try
			{
				new RSACryptoServiceProvider(cspParams);
			}
			catch (Exception)
			{
				return false;
			}

			return true;
		}

		internal static RSACryptoServiceProvider GetRSAKey(string keyName)
		{
			CspParameters container = new CspParameters(RSA);
			container.KeyContainerName = keyName;

			return new RSACryptoServiceProvider(2048, container);
		}

		public static string GenerateRSAKey(string keyName)
		{
			byte[] publicKey;
			if (!ExistsRSAKey(keyName))
			{
				CspParameters container = new CspParameters(RSA);
				container.KeyContainerName = keyName;
				container.Flags = CspProviderFlags.UseMachineKeyStore;
				container.ProviderName = "Microsoft Enhanced RSA and AES Cryptographic Provider";

				var rsa = new RSACryptoServiceProvider(container);
				rsa.PersistKeyInCsp = true;

				publicKey = rsa.ExportCspBlob(false);
				return HexToString(publicKey);
			}

			var cspParams = new CspParameters
			{
				Flags = CspProviderFlags.UseExistingKey,
				KeyContainerName = keyName
			};

			publicKey = new RSACryptoServiceProvider(cspParams).ExportCspBlob(false);
			return HexToString(publicKey);
		}

		public static byte[] LoadSimmetricKey(string name, out string keyStr, out string newName)
		{
			if (!File.Exists(PATH_AES + name))
			{
				string key;
				GenerateAESKey(out key, out newName);

				keyStr = key;
				return StringToHex(key);
			}

			newName = name;
			var linhas = File.ReadAllLines(PATH_AES + name);
			var tokens = linhas[0].Split(';');
			keyStr = "";

			return StringToHex(tokens[0]);
		}

		public static string EncryptAes(string plainText, byte[] Key, byte[] IV)
		{
			if (plainText == null || plainText.Length <= 0)
				throw new ArgumentNullException("plainText");

			if (Key == null || Key.Length <= 0)
				throw new ArgumentNullException("Key");
			
			byte[] encrypted;
			using (Aes aesAlg = Aes.Create())
			{
				aesAlg.Key = Key;
				aesAlg.IV = IV;

				ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);

				using (MemoryStream msEncrypt = new MemoryStream())
				{
					using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
					{
						using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
						{
							swEncrypt.Write(plainText);
						}

						encrypted = msEncrypt.ToArray();
					}
				}
			}

			return ToBase64(encrypted);
		}

		public static string DecryptAes(byte[] cipherText, byte[] Key, byte[] IV)
		{
			if (cipherText == null || cipherText.Length <= 0)
				throw new ArgumentNullException("cipherText");
			if (Key == null || Key.Length <= 0)
				throw new ArgumentNullException("Key");
			if (IV == null || IV.Length <= 0)
				throw new ArgumentNullException("IV");

			string plaintext = null;
			using (Aes aesAlg = Aes.Create())
			{
				aesAlg.Key = Key;
				aesAlg.IV = IV;

				ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);

				using (MemoryStream msDecrypt = new MemoryStream(cipherText))
				{
					using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
					{
						using (StreamReader srDecrypt = new StreamReader(csDecrypt))
						{
							plaintext = srDecrypt.ReadToEnd();
						}
					}
				}

			}

			return plaintext;
		}

		public static string ToBase64(byte[] content)
		{
			return Convert.ToBase64String(content);
		}

		public static byte[] FromBase64(string base64EncodedData)
		{
			return Convert.FromBase64String(base64EncodedData);
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
	}
}
