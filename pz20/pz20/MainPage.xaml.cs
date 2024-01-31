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
using System.Text.RegularExpressions;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

namespace pz20
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {
       
        public MainPage()
        {

            this.InitializeComponent();
        }
        private void btnnum1_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "1"; 
        }

        private void btnnum2_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "2";
        }

        private void btnnum3_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "3";
        }

        private void btnnum4_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "4";
        }

        private void btnnum5_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "5";
        }

        private void btnnum6_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "6";
        }

        private void btnnum7_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "7";
        }

        private void btnnum8_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "8";
        }

        private void btnnum9_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "9";
        }

        private void btnnum0_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "0";
        }

        private void btnplus_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "+";
        }

        private void btnmulti_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "*";
        }

        private void btnminus_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "-";
        }

        private void btndivide_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "/";
        }

        private void btnpow_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text += "^";
        }

        //private void btnsqrt_Click(object sender, RoutedEventArgs e)
        //{
        //    txtresult.Text += "√";
        //}

        private void btnnum_Click(object sender, RoutedEventArgs e)
        {
            Button btn = (Button)sender;
            txtresult.Text += btn.Content.ToString();
        }

        private void btnop_Click(object sender, RoutedEventArgs e)
        {
            Button btn = (Button)sender;
            txtresult.Text += btn.Content.ToString();
        }

        private void btnequal_Click(object sender, RoutedEventArgs e)
        {
            string input = txtresult.Text;
            string pattern = @"([0-9]+)([-+*/^√])([0-9]+)";
            Regex regex = new Regex(pattern);
            Match match = regex.Match(input);

            if (match.Success)
            {
                double num1 = double.Parse(match.Groups[1].Value);
                string operation = match.Groups[2].Value;
                double num2 = double.Parse(match.Groups[3].Value);
                double result = 0;

                switch (operation)
                {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                    case "/":
                        if (num2 != 0)
                            result = num1 / num2;
                        else
                            txtresult.Text = "Ошибка!";
                        break;
                    case "^":
                        result = Math.Pow(num1, num2);
                        break;
                    
                }
                    

                txtresult.Text = result.ToString();
            }
            else
            {
                txtresult.Text = "Ошибка! Нераспознанные значения!";
            }
        }

        private void btncc_Click(object sender, RoutedEventArgs e)
        {
            txtresult.Text = "";
        }
    }
}
