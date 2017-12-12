using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using Servidor.DAO;

namespace Servidor.Modelo
{
    class Usuario
    {
        public string userName { get; }
        public int level { get; }

        private int salt;
        private string hash;

        public Usuario(string userName, string password)
        {
            this.userName = userName;
            this.salt = new Random().Next();

            byte[] input = Encoding.ASCII.GetBytes(password + this.salt);
            byte[] output;
            SHA256 msgDigest = SHA256Managed.Create();
            output = msgDigest.ComputeHash(input);

            int i;
            for (i = 0; i < output.Length; i++)
            {
                this.hash += String.Format("{0:X2}", output[i]);
                if ((i % 4) == 3)
                    this.hash += (" ");
            }
        }

        public void gravar()
        {
            new UsuarioDAO().salvar(this);
        }
    }
}
