using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Core;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.UI.Xaml.Shapes;
//using System.Drawing;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

namespace pz19
{
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private void TogglePaneButton_Click(object sender, RoutedEventArgs e)
        {
            splitView.IsPaneOpen = !splitView.IsPaneOpen;
            resultTextBox.Text = "Успешная активация pane!";
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            Window.Current.SizeChanged += CurrentWindow_SizeChanged;
        }

        protected override void OnNavigatedFrom(NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);
            Window.Current.SizeChanged -= CurrentWindow_SizeChanged;
        }

        private void CurrentWindow_SizeChanged(object sender, WindowSizeChangedEventArgs e)
        {
            // Изменение размеров элементов при изменении размеров окна
            double width = e.Size.Width;
            double height = e.Size.Height;

            //// Пример изменения размеров прямоугольников
            //foreach (var rectangle in splitView.Children.OfType<Rectangle>())
            //{
            //    rectangle.Width = width / 10;
            //    rectangle.Height = height / 14;
            //}
        }
    }
}