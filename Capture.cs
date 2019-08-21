using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Windows;
using System.Windows.Automation;
using TestStack.White;

namespace Transformer
{
    class Capture
    {


        public void Capture_Item_Win(Rect bounds, String path)
        {
            try
            {


                //getting values from Rect
                double h = bounds.Height;
                double w = bounds.Width;
                double x = bounds.X;
                double y = bounds.Y;

                //logic for creating
                //creating equalent in System.Drawing
                //Source point
                System.Drawing.Point p = new System.Drawing.Point(Convert.ToInt32(x), Convert.ToInt32(y));
                //Destination point
                System.Drawing.Point p2 = new System.Drawing.Point(0, 0);

                //Creating Rectangle from Rect
                System.Drawing.Rectangle rect = new Rectangle(p.X, p.Y, Convert.ToInt32(w), Convert.ToInt32(h));

                //Creating bitmap with desired height and width
                Bitmap bitmap = new Bitmap(rect.Width, rect.Height);

                {
                    Graphics g = Graphics.FromImage(bitmap);
                    {
                        //Coping screen where automation element is present (p) to destnation point on the image (0,0)
                        g.CopyFromScreen(p, p2, rect.Size);
                    }
                    //Saving image
                    bitmap.Save(@path, ImageFormat.Jpeg);
                }
            }
            catch (Exception e)

            {
                Console.WriteLine("Capture_Item_Win: " + e.Message);
            }

        }

        public void ScreenShot(String path)
        {
            try
            {
                var sc = new ScreenCapture();
                var bitmap = sc.CaptureScreenShot();
                bitmap.Save(@path, ImageFormat.Png);
            }
            catch (Exception e)

            {
                Console.WriteLine("ScreenShot:" + e.Message);
            }


        }

        public static void Intitiate_Capture()
        {
            Rect boundingRect1;
            AutomationElement mainWindow;
            mainWindow = Init.GetmainWindow();

            object boundingRectNoDefault = mainWindow.GetCurrentPropertyValue(AutomationElement.BoundingRectangleProperty, true);
            if (boundingRectNoDefault == AutomationElement.NotSupported)
            {
                // TODO Handle the case where you do not wish to proceed using the default value.

            }
            else
            {
                boundingRect1 = (System.Windows.Rect)boundingRectNoDefault;

            }
        }


    }
}

