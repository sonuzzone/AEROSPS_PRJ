using System;
using System.Text.RegularExpressions;
using System.Windows.Automation;

namespace Transformer
{
    class EventActions
    {

        public void RegisterMainWinOpenEvent()
        {

            AutomationEventHandler UIAeventHandler;

            Automation.AddAutomationEventHandler

                (WindowPattern.WindowOpenedEvent, AutomationElement.RootElement, TreeScope.Children, UIAeventHandler = new AutomationEventHandler(DoMainWindowOpenAction));
        }

        public void RegisterSubWinOpenEvent(AutomationElement parent)
        {
            AutomationEventHandler UIAeventHandler;

            Automation.AddAutomationEventHandler
                (WindowPattern.WindowOpenedEvent, parent, TreeScope.Descendants, UIAeventHandler = new AutomationEventHandler(DoSubWindowOpenAction));
        }

        public void RegisterMainWinCloseEvent()
        {
            AutomationEventHandler UIAeventHandler;

            Automation.AddAutomationEventHandler
                (WindowPattern.WindowClosedEvent, AutomationElement.RootElement, TreeScope.Descendants, UIAeventHandler = new AutomationEventHandler(DoMainWindowCloseAction));

        }

        public void RegisterButtonClickEvent(AutomationElement elementButton)
        {
            //AutomationElement ElementSubscribeButton = null;
            AutomationEventHandler UIAeventHandler;

            if (elementButton != null)
            {
                Automation.AddAutomationEventHandler(InvokePattern.InvokedEvent, elementButton, TreeScope.Element, UIAeventHandler = new AutomationEventHandler(DoButtonClickAction));
                //ElementSubscribeButton = elementButton;

            }
        }


        public void DoMainWindowOpenAction(object src, AutomationEventArgs e)
        {
            String mainWinTitle;
            AutomationElement mainWindow = null;
            AutomationElement element;

            try
            {
               
                mainWinTitle = Init.GetMainWinTitle();

                element = src as AutomationElement;

  

                if (!Regex.IsMatch(element.Current.Name, mainWinTitle, RegexOptions.IgnoreCase))
                    return;
            }
            catch (ElementNotAvailableException)
            {
                return;
            }

            if (e.EventId == WindowPattern.WindowOpenedEvent)
            {
                Init.SetMainWinTitle(element.Current.Name);
                mainWindow = element;
                Init.SetmainWindow(mainWindow);
                mainWindow = Init.GetmainWindow();
                RegisterSubWinOpenEvent(mainWindow);
            }
        }

        public void DoSubWindowOpenAction(object src, AutomationEventArgs e)
        {
            AutomationElement subWindow = null;
            String subWinTitle;
            AutomationElement button = null;
            AutomationElement element;

            try
            {
                subWinTitle = Init.GetSubWinTitle();

                element = src as AutomationElement;

                if (!Regex.IsMatch(element.Current.Name,subWinTitle))
                    return;
            }
            catch (ElementNotAvailableException)
            {
                return;
            }

            if (e.EventId == WindowPattern.WindowOpenedEvent)
            {
                Init.SetSubWinTitle(subWinTitle);
                subWindow = element;
                Init.SetSubWindow(subWindow);
                subWindow = Init.GetSubWindow();
                Init.SetButton();
                button = Init.GetButton();
                RegisterButtonClickEvent(button);
            }
        }

        public void DoMainWindowCloseAction(object src, AutomationEventArgs e)
        {
            String mainWinTitle;
            try
            {
                mainWinTitle = Init.GetMainWinTitle();

                var element = src as AutomationElement;

                if (!(element.Current.Name == mainWinTitle))
                    return;
            }
            catch (ElementNotAvailableException)
            {
                return;
            }

            if (e.EventId == WindowPattern.WindowClosedEvent)
            {
                // TODO: event handling
            }
        }

        public void DoButtonClickAction(object src, AutomationEventArgs e)
        {
            ScrapData scrapdata = new ScrapData();
            SendData sendata = new SendData();

            String data1, data2, autoid1, autoid2;


            AutomationElement sourceElement = null;
            try
            {
                sourceElement = src as AutomationElement;
            }
            catch (ElementNotAvailableException)
            {
                return;
            }
            if (e.EventId == InvokePattern.InvokedEvent)
            {
                autoid1 = Init.GetAutoIDTextBox1();

                data1 = scrapdata.GetTextboxData(autoid1);

                if (data1 != "INVALID_DATA")
                {
                    sendata.SendToTray(data1);
                }
                autoid2 = Init.GetAutoIDTextBox2();
                data2 = scrapdata.GetTextboxData(autoid2);

                if (data2 != "INVALID_DATA")
                {
                    sendata.SendToTray(data2);
                }
            }
            else
            {
                Console.WriteLine("There was no click\n");
            }
        }


        public void RemoveHandler()
        {
            Automation.RemoveAllEventHandlers();
        }
    }
}
