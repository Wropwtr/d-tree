namespace SampleKruskal
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.gViewer = new Microsoft.Glee.GraphViewerGdi.GViewer();
            this.label2 = new System.Windows.Forms.Label();
            this.nEdges = new System.Windows.Forms.NumericUpDown();
            this.nPeaks = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textWMin = new System.Windows.Forms.TextBox();
            this.textWMax = new System.Windows.Forms.TextBox();
            this.btnGenerate = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.edgeWeight = new System.Windows.Forms.TextBox();
            this.edgeStart = new System.Windows.Forms.NumericUpDown();
            this.edgeEnd = new System.Windows.Forms.NumericUpDown();
            this.btnAddEdge = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.btnDownload = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.nEdges)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nPeaks)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.edgeStart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.edgeEnd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // gViewer
            // 
            this.gViewer.AsyncLayout = false;
            this.gViewer.AutoScroll = true;
            this.gViewer.BackwardEnabled = false;
            this.gViewer.ForwardEnabled = false;
            this.gViewer.Graph = null;
            this.gViewer.Location = new System.Drawing.Point(12, 12);
            this.gViewer.MouseHitDistance = 0.05D;
            this.gViewer.Name = "gViewer";
            this.gViewer.NavigationVisible = true;
            this.gViewer.PanButtonPressed = false;
            this.gViewer.SaveButtonVisible = true;
            this.gViewer.Size = new System.Drawing.Size(684, 719);
            this.gViewer.TabIndex = 0;
            this.gViewer.ZoomF = 1D;
            this.gViewer.ZoomFraction = 0.5D;
            this.gViewer.ZoomWindowThreshold = 0.05D;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(732, 12);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(90, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Создание графа";
            // 
            // nEdges
            // 
            this.nEdges.Location = new System.Drawing.Point(780, 51);
            this.nEdges.Name = "nEdges";
            this.nEdges.Size = new System.Drawing.Size(62, 20);
            this.nEdges.TabIndex = 4;
            this.nEdges.Value = new decimal(new int[] {
            12,
            0,
            0,
            0});
            this.nEdges.ValueChanged += new System.EventHandler(this.nEdges_ValueChanged);
            // 
            // nPeaks
            // 
            this.nPeaks.Location = new System.Drawing.Point(702, 51);
            this.nPeaks.Name = "nPeaks";
            this.nPeaks.Size = new System.Drawing.Size(61, 20);
            this.nPeaks.TabIndex = 5;
            this.nPeaks.Value = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.nPeaks.ValueChanged += new System.EventHandler(this.nPeaks_ValueChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(699, 35);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Вершин";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(785, 35);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(38, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Ребер";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(732, 106);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(85, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Диапазон веса";
            // 
            // textWMin
            // 
            this.textWMin.Location = new System.Drawing.Point(700, 131);
            this.textWMin.MaxLength = 100;
            this.textWMin.Name = "textWMin";
            this.textWMin.Size = new System.Drawing.Size(61, 20);
            this.textWMin.TabIndex = 9;
            this.textWMin.Text = "0";
            // 
            // textWMax
            // 
            this.textWMax.Location = new System.Drawing.Point(778, 131);
            this.textWMax.Name = "textWMax";
            this.textWMax.Size = new System.Drawing.Size(62, 20);
            this.textWMax.TabIndex = 10;
            this.textWMax.Text = "20";
            // 
            // btnGenerate
            // 
            this.btnGenerate.Location = new System.Drawing.Point(725, 157);
            this.btnGenerate.Name = "btnGenerate";
            this.btnGenerate.Size = new System.Drawing.Size(92, 25);
            this.btnGenerate.TabIndex = 11;
            this.btnGenerate.Text = "Генерировать граф";
            this.btnGenerate.UseVisualStyleBackColor = true;
            this.btnGenerate.Click += new System.EventHandler(this.btnGenerate_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(722, 211);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(93, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "Создать вручную";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(697, 233);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(44, 13);
            this.label6.TabIndex = 13;
            this.label6.Text = "Начало";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(782, 233);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(38, 13);
            this.label7.TabIndex = 14;
            this.label7.Text = "Конец";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(699, 272);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(26, 13);
            this.label8.TabIndex = 15;
            this.label8.Text = "Вес";
            // 
            // edgeWeight
            // 
            this.edgeWeight.Location = new System.Drawing.Point(698, 288);
            this.edgeWeight.Name = "edgeWeight";
            this.edgeWeight.Size = new System.Drawing.Size(63, 20);
            this.edgeWeight.TabIndex = 16;
            this.edgeWeight.Text = "0";
            // 
            // edgeStart
            // 
            this.edgeStart.Location = new System.Drawing.Point(698, 249);
            this.edgeStart.Name = "edgeStart";
            this.edgeStart.Size = new System.Drawing.Size(61, 20);
            this.edgeStart.TabIndex = 17;
            // 
            // edgeEnd
            // 
            this.edgeEnd.Location = new System.Drawing.Point(777, 249);
            this.edgeEnd.Name = "edgeEnd";
            this.edgeEnd.Size = new System.Drawing.Size(61, 20);
            this.edgeEnd.TabIndex = 18;
            // 
            // btnAddEdge
            // 
            this.btnAddEdge.Location = new System.Drawing.Point(702, 314);
            this.btnAddEdge.Name = "btnAddEdge";
            this.btnAddEdge.Size = new System.Drawing.Size(138, 26);
            this.btnAddEdge.TabIndex = 19;
            this.btnAddEdge.Text = "Добавить ребро";
            this.btnAddEdge.UseVisualStyleBackColor = true;
            this.btnAddEdge.Click += new System.EventHandler(this.btnAddEdge_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(700, 432);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(140, 32);
            this.button2.TabIndex = 20;
            this.button2.Text = "Применить Крускала";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(700, 470);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(138, 45);
            this.button3.TabIndex = 21;
            this.button3.Text = "Применить Крускала по шагам";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(698, 564);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(140, 32);
            this.btnClear.TabIndex = 22;
            this.btnClear.Text = "Очистить";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(775, 272);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(64, 13);
            this.label9.TabIndex = 23;
            this.label9.Text = "Добавлено";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(778, 288);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.ReadOnly = true;
            this.numericUpDown1.Size = new System.Drawing.Size(61, 20);
            this.numericUpDown1.TabIndex = 24;
            // 
            // btnDownload
            // 
            this.btnDownload.Location = new System.Drawing.Point(704, 346);
            this.btnDownload.Name = "btnDownload";
            this.btnDownload.Size = new System.Drawing.Size(136, 26);
            this.btnDownload.TabIndex = 25;
            this.btnDownload.Text = "Загрузить граф";
            this.btnDownload.UseVisualStyleBackColor = true;
            this.btnDownload.Click += new System.EventHandler(this.btnDownload_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(702, 521);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 26;
            this.button1.Text = "Далее";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(852, 743);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnDownload);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.btnAddEdge);
            this.Controls.Add(this.edgeEnd);
            this.Controls.Add(this.edgeStart);
            this.Controls.Add(this.edgeWeight);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnGenerate);
            this.Controls.Add(this.textWMax);
            this.Controls.Add(this.textWMin);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.nPeaks);
            this.Controls.Add(this.nEdges);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.gViewer);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.nEdges)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nPeaks)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.edgeStart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.edgeEnd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Microsoft.Glee.GraphViewerGdi.GViewer gViewer;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown nEdges;
        private System.Windows.Forms.NumericUpDown nPeaks;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textWMin;
        private System.Windows.Forms.TextBox textWMax;
        private System.Windows.Forms.Button btnGenerate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox edgeWeight;
        private System.Windows.Forms.NumericUpDown edgeStart;
        private System.Windows.Forms.NumericUpDown edgeEnd;
        private System.Windows.Forms.Button btnAddEdge;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Button btnDownload;
        private System.Windows.Forms.Button button1;
    }
}

