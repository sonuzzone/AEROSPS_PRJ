using Quobject.SocketIoClientDotNet.Client;
using System;
using System.Windows.Automation;

namespace Transformer
{
    public static class Init
    {
        static String path;
        static String mainWinTitle;
        static String subWinTitle;
        static String TxtBox1autoid;
        static String TxtBox2autoid;
        static String BtnAutoid;
        static Socket socket;
        static AutomationElement mainWindow = null;
        static AutomationElement subWindow = null;
        static AutomationElement button = null;

        public static String GetPath()
        {
            return path;
        }

        public static void SetPath(String spath)
        {
            path = spath;
        }

        public static String GetMainWinTitle()
        {
            return mainWinTitle;
        }

        public static void SetMainWinTitle(String title)
        {
            mainWinTitle = title;
        }

        public static String GetSubWinTitle()
        {
            return subWinTitle;
        }

        public static void SetSubWinTitle(String title)
        {
            subWinTitle = title;
        }


        public static AutomationElement GetmainWindow()
        {
            return mainWindow;

        }

        public static AutomationElement GetSubWindow()
        {
            return subWindow;
        }

        public static void SetmainWindow(AutomationElement win)
        {
            mainWindow = win;
        }

        public static void SetSubWindow(AutomationElement subwin)
        {
            subWindow = subwin;

        }

        public static void SetButton()
        {

            ScrapData scrapdata = new ScrapData();
            button = scrapdata.FindElementbyID(subWindow, BtnAutoid);

        }

        public static AutomationElement GetButton()
        {
            return button;
        }

        public static void SetAutoIDTextBox1(String id)
        {
            TxtBox1autoid = id;
        }

        public static String GetAutoIDTextBox1()
        {
            return TxtBox1autoid;
        }

        public static void SetAutoIDTextBox2(String id)
        {
            TxtBox2autoid = id;
        }

        public static String GetAutoIDTextBox2()
        {
            return TxtBox2autoid;
        }

        public static void SetAutoIDButton(String id)
        {
            BtnAutoid = id;
        }

        public static String GetAutoIDButton()
        {
            return BtnAutoid;
        }

        public static void SetSocket(Socket num)
        {
            socket = num;
        }

        public static Socket GetSocket()
        {
            return socket;
        }





    }
}
