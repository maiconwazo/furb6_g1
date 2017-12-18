using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Servidor.Library
{
	public enum Level { lvBasic, lvMod, lvAdmin };
	public enum Actions { aNone, aCreateUser, aDeleteUser, aLogin, aLogout, aUserList, aSendMessage, aSymmetricName, aMessageCount, aAllMessages, aVerifyPermission, aPublicKey, aEnd };
}
