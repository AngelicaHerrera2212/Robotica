using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Runtime.Remoting.Services;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HMIBingoGO
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            CloseButton.Enabled = false;
            string[] B = { "1", "2","3","4","5","6","7","8","9","10","11","12","13","14","15" };
            comboBox1.DataSource = B;
            string[] I = { "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30" };
            comboBox2.DataSource = I;
            string[] N = { "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45" };
            comboBox3.DataSource = N;
            string[] G = { "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60" };
            comboBox4.DataSource = G;
            string[] O = { "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75" };
            comboBox5.DataSource = O;

            string[] PortList = SerialPort.GetPortNames(); //mejorar aqui
            Port_ComboBox.Items.AddRange(PortList);

            string[] BaudRatesList = { "9600", "38400", "57600", "115200" };
            BaudRate_ComboBox.DataSource = BaudRatesList;
        }

        private void OpenButton_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortConnection.PortName = Port_ComboBox.Text;
                SerialPortConnection.BaudRate = Convert.ToInt32(BaudRate_ComboBox.Text);
                SerialPortConnection.Open();
                ProgressBar.Value = 100;
                CloseButton.Enabled = true;
                OpenButton.Enabled = false;
                RefreshButton.Enabled = false;
            }

            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }  
        }

        private void RefreshButton_Click(object sender, EventArgs e)
        {
            string[] PortList = SerialPort.GetPortNames();
            Port_ComboBox.Items.AddRange(PortList); 
        }

        private void EnableButtons(bool Enabled_Disabled)
        {
            enterbuttonB.Enabled = Enabled_Disabled;
            enterbuttonI.Enabled = Enabled_Disabled;
            enterbuttonN.Enabled = Enabled_Disabled;
            enterbuttonG.Enabled = Enabled_Disabled;
            enterbuttonO.Enabled = Enabled_Disabled;
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            if (SerialPortConnection.IsOpen)
            {
                try
                {
                    SerialPortConnection.Close();
                    ProgressBar.Value = 0;
                    CloseButton.Enabled = false;
                    OpenButton.Enabled = true;
                    RefreshButton.Enabled = true;
                }
                catch (Exception error)
                {
                    MessageBox.Show(error.Message);
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (SerialPortConnection.IsOpen)
            {
                try
                {
                    SerialPortConnection.Close();
                }
                catch (Exception error)
                {
                    MessageBox.Show(error.Message);
                }
            }
        }

        private void enterbuttonB_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortConnection.WriteLine("<"+comboBox1.Text+">");
                //MessageBox.Show("<" + comboBox1.Text + ">");
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
             }
        }

        private void enterbuttonI_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortConnection.WriteLine("<" + comboBox2.Text + ">");
                //MessageBox.Show("<" + comboBox2.Text + ">");
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void enterbuttonN_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortConnection.WriteLine("<" + comboBox3.Text + ">");
                //MessageBox.Show("<" + comboBox3.Text + ">");
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void enterbuttonG_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortConnection.WriteLine("<" + comboBox4.Text + ">");
                //MessageBox.Show("<" + comboBox4.Text + ">");
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void enterbuttonO_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortConnection.WriteLine("<" + comboBox5.Text + ">");
                //MessageBox.Show("<" + comboBox5.Text + ">");
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }
    }
}
