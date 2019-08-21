using Quobject.SocketIoClientDotNet.Client;
using System;


namespace Transformer
{
    class SendData
    {

        public void SendToTray(String msg)
        {
            Socket socket;
            socket = Init.GetSocket();
            Console.WriteLine("SENDING TO  TRAY ..");
            // socket.Emit("TRAY", msg);
            Console.WriteLine(msg);
        }




    }
}
