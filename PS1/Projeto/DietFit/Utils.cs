using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DietFit
{
	public enum IndiceAtividadeFisica { iaSedentario, iaPoucoAtivo, iaAtivo, iaMuitoAtivo };
	public enum Sexo { sMasc, sFem };
	public enum Objetivo { oBulking, oCutting };
	public enum TipoRefeicao { trNenhum, trCafe, trLancheManha, trAlmoco, trLancheTarde, trPre, trPos, trCeia };

	public class Utils
	{
		public const int C_CASAS = 18;

		public static void PrintArray(decimal[,] arr)
		{
			Console.Write(Environment.NewLine + Environment.NewLine);

			int rowLength = arr.GetLength(0);
			int colLength = arr.GetLength(1);

			for (int i = 0; i <= rowLength; i++)
			{
				for (int j = 0; j < colLength; j++)
				{
					if (i == 0)
					{
						if (j < colLength - 7)
						{
							Console.Write("Alimento " + (j + 1) + "       |      ");
						}
						else if (j == colLength - 7)
						{
							Console.Write("Sobra 1 " + "         |      ");
						}
						else if (j == colLength - 6)
						{
							Console.Write("Sobra 2 " + "         |      ");
						}
						else if (j == colLength - 5)
						{
							Console.Write("Sobra 3 " + "         |      ");
						}
						else if (j == colLength - 4)
						{
							Console.Write("Artif 1 " + "         |      ");
						}
						else if (j == colLength - 3)
						{
							Console.Write("Artif 2 " + "         |      ");
						}
						else if (j == colLength - 2)
						{
							Console.Write("Artif 3 " + "         |      ");
						}
						else if (j == colLength - 1)
						{
							Console.Write("   B    " + "         |      ");
						}
					}
					else
					{
						Console.Write((arr[i - 1, j] >= 0 ? arr[i - 1, j].ToString(" 00.0000000") : arr[i - 1, j].ToString("00.0000000")) + "      |      ");
					}
				}
				Console.Write(Environment.NewLine + Environment.NewLine);
			}
		}
	}
}
