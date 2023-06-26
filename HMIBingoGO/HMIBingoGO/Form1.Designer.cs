namespace HMIBingoGO
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.enterbuttonB = new System.Windows.Forms.Button();
            this.enterbuttonI = new System.Windows.Forms.Button();
            this.enterbuttonN = new System.Windows.Forms.Button();
            this.enterbuttonG = new System.Windows.Forms.Button();
            this.enterbuttonO = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.comboBox5 = new System.Windows.Forms.ComboBox();
            this.comboBox4 = new System.Windows.Forms.ComboBox();
            this.comboBox3 = new System.Windows.Forms.ComboBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.SerialPortConnection = new System.IO.Ports.SerialPort(this.components);
            this.Port_ComboBox = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.ProgressBar = new System.Windows.Forms.ProgressBar();
            this.CloseButton = new System.Windows.Forms.Button();
            this.RefreshButton = new System.Windows.Forms.Button();
            this.OpenButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.BaudRate_ComboBox = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // enterbuttonB
            // 
            this.enterbuttonB.Location = new System.Drawing.Point(435, 131);
            this.enterbuttonB.Name = "enterbuttonB";
            this.enterbuttonB.Size = new System.Drawing.Size(75, 23);
            this.enterbuttonB.TabIndex = 2;
            this.enterbuttonB.Text = "Enter";
            this.enterbuttonB.UseVisualStyleBackColor = true;
            this.enterbuttonB.Click += new System.EventHandler(this.enterbuttonB_Click);
            // 
            // enterbuttonI
            // 
            this.enterbuttonI.Location = new System.Drawing.Point(435, 239);
            this.enterbuttonI.Name = "enterbuttonI";
            this.enterbuttonI.Size = new System.Drawing.Size(75, 23);
            this.enterbuttonI.TabIndex = 10;
            this.enterbuttonI.Text = "Enter";
            this.enterbuttonI.UseVisualStyleBackColor = true;
            this.enterbuttonI.Click += new System.EventHandler(this.enterbuttonI_Click);
            // 
            // enterbuttonN
            // 
            this.enterbuttonN.Location = new System.Drawing.Point(435, 351);
            this.enterbuttonN.Name = "enterbuttonN";
            this.enterbuttonN.Size = new System.Drawing.Size(75, 23);
            this.enterbuttonN.TabIndex = 13;
            this.enterbuttonN.Text = "Enter";
            this.enterbuttonN.UseVisualStyleBackColor = true;
            this.enterbuttonN.Click += new System.EventHandler(this.enterbuttonN_Click);
            // 
            // enterbuttonG
            // 
            this.enterbuttonG.Location = new System.Drawing.Point(435, 465);
            this.enterbuttonG.Name = "enterbuttonG";
            this.enterbuttonG.Size = new System.Drawing.Size(75, 23);
            this.enterbuttonG.TabIndex = 16;
            this.enterbuttonG.Text = "Enter";
            this.enterbuttonG.UseVisualStyleBackColor = true;
            this.enterbuttonG.Click += new System.EventHandler(this.enterbuttonG_Click);
            // 
            // enterbuttonO
            // 
            this.enterbuttonO.Location = new System.Drawing.Point(435, 581);
            this.enterbuttonO.Name = "enterbuttonO";
            this.enterbuttonO.Size = new System.Drawing.Size(75, 23);
            this.enterbuttonO.TabIndex = 19;
            this.enterbuttonO.Text = "Enter";
            this.enterbuttonO.UseVisualStyleBackColor = true;
            this.enterbuttonO.Click += new System.EventHandler(this.enterbuttonO_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Cambria", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(155, 92);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(181, 20);
            this.label6.TabIndex = 20;
            this.label6.Text = "Type a number (1-15)";
            // 
            // label7
            // 
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("Headline R", 28.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(108, 20);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(519, 57);
            this.label7.TabIndex = 21;
            this.label7.Text = "START PLAYING!";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.Font = new System.Drawing.Font("Cambria", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(155, 192);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(191, 20);
            this.label8.TabIndex = 22;
            this.label8.Text = "Type a number (16-30)";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.Color.Transparent;
            this.label9.Font = new System.Drawing.Font("Cambria", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.Color.White;
            this.label9.Location = new System.Drawing.Point(155, 309);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(191, 20);
            this.label9.TabIndex = 23;
            this.label9.Text = "Type a number (31-45)";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.BackColor = System.Drawing.Color.Transparent;
            this.label10.Font = new System.Drawing.Font("Cambria", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.ForeColor = System.Drawing.Color.White;
            this.label10.Location = new System.Drawing.Point(155, 417);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(191, 20);
            this.label10.TabIndex = 24;
            this.label10.Text = "Type a number (46-60)";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.BackColor = System.Drawing.Color.Transparent;
            this.label11.Font = new System.Drawing.Font("Cambria", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.ForeColor = System.Drawing.Color.White;
            this.label11.Location = new System.Drawing.Point(155, 534);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(191, 20);
            this.label11.TabIndex = 25;
            this.label11.Text = "Type a number (61-75)";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Headline R", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label12.ForeColor = System.Drawing.Color.PaleGreen;
            this.label12.Location = new System.Drawing.Point(56, 119);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(59, 49);
            this.label12.TabIndex = 26;
            this.label12.Text = "B";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Headline R", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label13.ForeColor = System.Drawing.Color.Salmon;
            this.label13.Location = new System.Drawing.Point(56, 225);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(40, 49);
            this.label13.TabIndex = 3;
            this.label13.Text = "I";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("Headline R", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label14.ForeColor = System.Drawing.Color.DeepSkyBlue;
            this.label14.Location = new System.Drawing.Point(56, 338);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(61, 49);
            this.label14.TabIndex = 27;
            this.label14.Text = "N";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Font = new System.Drawing.Font("Headline R", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label15.ForeColor = System.Drawing.Color.Gold;
            this.label15.Location = new System.Drawing.Point(56, 453);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(66, 49);
            this.label15.TabIndex = 28;
            this.label15.Text = "G";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Font = new System.Drawing.Font("Headline R", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label16.ForeColor = System.Drawing.Color.Plum;
            this.label16.Location = new System.Drawing.Point(56, 566);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(63, 49);
            this.label16.TabIndex = 29;
            this.label16.Text = "O";
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Transparent;
            this.groupBox1.Controls.Add(this.comboBox5);
            this.groupBox1.Controls.Add(this.comboBox4);
            this.groupBox1.Controls.Add(this.comboBox3);
            this.groupBox1.Controls.Add(this.comboBox2);
            this.groupBox1.Controls.Add(this.comboBox1);
            this.groupBox1.Controls.Add(this.label16);
            this.groupBox1.Controls.Add(this.label15);
            this.groupBox1.Controls.Add(this.label14);
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.label10);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.enterbuttonO);
            this.groupBox1.Controls.Add(this.enterbuttonG);
            this.groupBox1.Controls.Add(this.enterbuttonN);
            this.groupBox1.Controls.Add(this.enterbuttonI);
            this.groupBox1.Controls.Add(this.enterbuttonB);
            this.groupBox1.Font = new System.Drawing.Font("Cambria", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(42, 35);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(719, 646);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Number";
            // 
            // comboBox5
            // 
            this.comboBox5.FormattingEnabled = true;
            this.comboBox5.Location = new System.Drawing.Point(150, 582);
            this.comboBox5.Name = "comboBox5";
            this.comboBox5.Size = new System.Drawing.Size(232, 23);
            this.comboBox5.TabIndex = 33;
            // 
            // comboBox4
            // 
            this.comboBox4.FormattingEnabled = true;
            this.comboBox4.Location = new System.Drawing.Point(150, 466);
            this.comboBox4.Name = "comboBox4";
            this.comboBox4.Size = new System.Drawing.Size(232, 23);
            this.comboBox4.TabIndex = 32;
            // 
            // comboBox3
            // 
            this.comboBox3.FormattingEnabled = true;
            this.comboBox3.Location = new System.Drawing.Point(150, 352);
            this.comboBox3.Name = "comboBox3";
            this.comboBox3.Size = new System.Drawing.Size(232, 23);
            this.comboBox3.TabIndex = 31;
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Location = new System.Drawing.Point(150, 239);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(232, 23);
            this.comboBox2.TabIndex = 30;
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(150, 131);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(232, 23);
            this.comboBox1.TabIndex = 3;
            // 
            // Port_ComboBox
            // 
            this.Port_ComboBox.FormattingEnabled = true;
            this.Port_ComboBox.Location = new System.Drawing.Point(173, 54);
            this.Port_ComboBox.Name = "Port_ComboBox";
            this.Port_ComboBox.Size = new System.Drawing.Size(121, 23);
            this.Port_ComboBox.TabIndex = 3;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.ProgressBar);
            this.groupBox2.Controls.Add(this.CloseButton);
            this.groupBox2.Controls.Add(this.RefreshButton);
            this.groupBox2.Controls.Add(this.OpenButton);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.BaudRate_ComboBox);
            this.groupBox2.Controls.Add(this.Port_ComboBox);
            this.groupBox2.Font = new System.Drawing.Font("Cambria", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(814, 35);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(330, 329);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Serial Comunication";
            // 
            // ProgressBar
            // 
            this.ProgressBar.Location = new System.Drawing.Point(33, 251);
            this.ProgressBar.Name = "ProgressBar";
            this.ProgressBar.Size = new System.Drawing.Size(275, 23);
            this.ProgressBar.TabIndex = 9;
            // 
            // CloseButton
            // 
            this.CloseButton.Location = new System.Drawing.Point(233, 192);
            this.CloseButton.Name = "CloseButton";
            this.CloseButton.Size = new System.Drawing.Size(75, 23);
            this.CloseButton.TabIndex = 5;
            this.CloseButton.Text = "Close";
            this.CloseButton.UseVisualStyleBackColor = true;
            this.CloseButton.Click += new System.EventHandler(this.CloseButton_Click);
            // 
            // RefreshButton
            // 
            this.RefreshButton.Location = new System.Drawing.Point(136, 192);
            this.RefreshButton.Name = "RefreshButton";
            this.RefreshButton.Size = new System.Drawing.Size(75, 23);
            this.RefreshButton.TabIndex = 8;
            this.RefreshButton.Text = "Refresh";
            this.RefreshButton.UseVisualStyleBackColor = true;
            // 
            // OpenButton
            // 
            this.OpenButton.Location = new System.Drawing.Point(38, 192);
            this.OpenButton.Name = "OpenButton";
            this.OpenButton.Size = new System.Drawing.Size(75, 23);
            this.OpenButton.TabIndex = 7;
            this.OpenButton.Text = "Open";
            this.OpenButton.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Cambria", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(33, 119);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 23);
            this.label2.TabIndex = 6;
            this.label2.Text = "BaudRate";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Cambria", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(33, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 23);
            this.label1.TabIndex = 5;
            this.label1.Text = "Port";
            // 
            // BaudRate_ComboBox
            // 
            this.BaudRate_ComboBox.FormattingEnabled = true;
            this.BaudRate_ComboBox.Location = new System.Drawing.Point(173, 119);
            this.BaudRate_ComboBox.Name = "BaudRate_ComboBox";
            this.BaudRate_ComboBox.Size = new System.Drawing.Size(121, 23);
            this.BaudRate_ComboBox.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(1182, 718);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "HMIbrazo";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button enterbuttonB;
        private System.Windows.Forms.Button enterbuttonI;
        private System.Windows.Forms.Button enterbuttonN;
        private System.Windows.Forms.Button enterbuttonG;
        private System.Windows.Forms.Button enterbuttonO;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox comboBox4;
        private System.Windows.Forms.ComboBox comboBox3;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.ComboBox comboBox5;
        private System.Windows.Forms.ComboBox Port_ComboBox;
        private System.IO.Ports.SerialPort SerialPortConnection;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox BaudRate_ComboBox;
        private System.Windows.Forms.Button RefreshButton;
        private System.Windows.Forms.Button OpenButton;
        private System.Windows.Forms.ProgressBar ProgressBar;
        private System.Windows.Forms.Button CloseButton;
    }
}

