using System.Windows.Forms;

namespace Transformer
{
    class Manager
    {


        public static void Main(string[] args)
        {
            ReadData obj_ReadData = new ReadData();
            EventActions obj_eventaction = new EventActions();

            obj_ReadData.Read_File();
            //obj_ReadData.SocketData();

            obj_eventaction.RegisterMainWinOpenEvent();
            obj_eventaction.RegisterMainWinCloseEvent();
            Application.Run(new ApplicationContext());

        }
    }
}
