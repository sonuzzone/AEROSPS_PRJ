using AutoIt;
using System;
using System.Windows.Automation;

namespace Transformer
{
    public class ScrapData
    {

        public String GetHiddenText(String Win_Title)
        {
            String text;
            text = AutoItX.WinGetText(Win_Title);
            return text;
        }

        public String GetTextboxData(String autoid)
        {
            AutomationElement element = null;
            AutomationElement subWindow = null;

            subWindow = Init.GetSubWindow();

            element = FindElementbyID(subWindow, autoid);

            object patternObj;
            if (element.TryGetCurrentPattern(ValuePattern.Pattern, out patternObj))
            {
                var valuePattern = (ValuePattern)patternObj;
                return valuePattern.Current.Value;
            }
            else
                return "INVALID_DATA";
        }

        public AutomationElement FindElementbyID(AutomationElement window, String autoid)
        {
            AutomationElement element = null;
            element = window.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.AutomationIdProperty, autoid));

            if (element == null)
            {

                throw new InvalidOperationException("Element not Found");

            }
            return element;
        }
    }
}
