using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;


namespace Wpf
{
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            this.DataContext = this;
        }

        private void Output_Click(object sender, RoutedEventArgs e)
        {
            string Filename = CreatePath.Text + "\\" + ClassName.Text + ".cpp";
            string Str = File.ReadAllText("Class.txt");

            Str = Str.Replace("INCLUDE_GUARD", ClassName.Text.ToUpper());
            Str = Str.Replace("CLASS_NAME", ClassName.Text.ToString());

            File.WriteAllText(Filename, Str, Encoding.UTF8);
        }

        private void FilePathButton_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new FolderBrowserDialog();
            dialog.Description = "出力先を指定してください。";

            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                // 選択されたフォルダーパスをメッセージボックスに表示
                CreatePath.Text = dialog.SelectedPath;
            }
        }
    }
}
