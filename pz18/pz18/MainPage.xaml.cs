using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using pz18;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

namespace pz18
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {

        public class Student
        {
            public string Name { get; set; }
            public string Group { get; set; }

            public override string ToString()
            {
                return $"студент {this.Name} из группы {this.Group}";
            }
        }

        public MainPage()
        {
            this.InitializeComponent();

            Button buttno1 = new Button();
            buttno1.Content = "Новая кнопка";
            buttno1.Width = 200;
            buttno1.Height = 100;

            layoutGrid.Children.Add(buttno1);
        }
    }
}
