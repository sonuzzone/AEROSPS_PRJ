using Quobject.SocketIoClientDotNet.Client;
using System;

namespace Transformer
{
    class ReadData
    {

        private String mainWinTitle;
        private String subWinTitle;
        private String path;
        private String TxtBox1autoid;
        private String TxtBox2autoid;
        private String BtnAutoid;


        public void SocketData()
        {
            Socket socket = IO.Socket("http://localhost:3000");

            socket.On("EA", (data) =>
            {
                ReceiveFromTray(socket, data.ToString());
            });

        }
        public void ReceiveFromTray(Socket socket, String msg)
        {
            Console.WriteLine("RECEIVED FROM TRAY ..");
            Console.WriteLine(msg);
            // sendToTray(socket, "I AM EA");
            Init.SetSocket(socket);
        }

        public void Read_File()
        {
            string[] lines = System.IO.File.ReadAllLines(@"D:\Personal\ConfigFile.txt");

            mainWinTitle = lines[0];
            subWinTitle = lines[1];
            TxtBox1autoid = lines[2];
            TxtBox2autoid = lines[3];
            BtnAutoid = lines[4];
            path = lines[5];
            SetPrimaryData();

        }

        public void SetPrimaryData()
        {
            Init.SetPath(path);
            Init.SetMainWinTitle(mainWinTitle);
            Init.SetSubWinTitle(subWinTitle);
            Init.SetAutoIDTextBox1(TxtBox1autoid);
            Init.SetAutoIDTextBox2(TxtBox2autoid);
            Init.SetAutoIDButton(BtnAutoid);

        }

    }
}
