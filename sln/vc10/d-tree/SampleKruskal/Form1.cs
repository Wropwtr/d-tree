using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Microsoft.Glee.Drawing;
using System.IO;
using System.Diagnostics;

namespace SampleKruskal
{

    
    public partial class Form1 : Form
    {
        const int ZERO = 0;
        Graph gArms;
        Edge[] edgeArr;

        bool NextIsClicked;

        public Form1()
        {
            if (File.Exists(@"graph_input.txt"))
            {
                File.Delete(@"graph_input.txt");
            }
            if (File.Exists(@"graph_output.txt"))
            {
                File.Delete(@"graph_output.txt");
            }
            InitializeComponent();
            textWMin.Text = "0";
            textWMax.Text = "20";  
            Graph gArms = new Graph("graph");
            gViewer.Graph = gArms;
            button1.Enabled = false;
            disable_kruskals();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            Graph gArms = new Graph("graph");
            gViewer.Graph = gArms;
            gArms.GraphAttr.EdgeAttr.ArrowHeadAtTarget = ArrowStyle.None;
            FileInfo f = new FileInfo("graph_input.txt");
            FileStream s = f.Open(FileMode.Create, FileAccess.ReadWrite);
            s.Close();
            numericUpDown1.Value = 0;
            disable_kruskals();
        }

        private void btnGenerate_Click(object sender, EventArgs e)
        {
            if (nPeaks.Value <= 0)
            {
                MessageBox.Show("Number of peaks must be more than zero.");
                return;
            }
            if (nEdges.Value < 0)
            {
                MessageBox.Show("Number of edges can not be less than zero.");
                return;
            }
            float wMin, wMax;
            try
            {
                wMax = float.Parse(textWMax.Text.ToString());
                wMin = float.Parse(textWMin.Text.ToString());
            }
            catch
            {
                MessageBox.Show("Not correct max value.");
                return;
            }
            if (wMin > wMax)
            {
                MessageBox.Show("Minimum weight must less than maximum.");
                return;
            }
            FileInfo f = new FileInfo(@"graph_input.txt");
            FileStream s = f.Open(FileMode.Create, FileAccess.ReadWrite);
            s.Close();
            // создание

            StreamWriter w = new StreamWriter(@"graph_input.txt",false);
            w.WriteLine("1 ");
            w.WriteLine("" + nPeaks.Value + " " + nEdges.Value);
            w.WriteLine("" + wMin + " " + wMax);
            w.Close();

            var process = Process.Start("kruskal.exe");
            process.WaitForExit();
            if (!File.Exists(@"graph_input.txt"))
            {
                MessageBox.Show("Something goes wrong.");
                return;
            }

            gArms = new Graph("graph");
            gArms.GraphAttr.EdgeAttr.ArrowHeadAtTarget = ArrowStyle.None;
            for (int i = 0; i < nPeaks.Value; i++)
                gArms.AddNode(i.ToString());
            
            // запись данных
            
            //float[] d = File.ReadAllLines("graph_input.txt").Select(float.Parse).ToArray();
            // 5 значений пропускаем
            int n, m;
            string path = Directory.GetCurrentDirectory();
            String[] lines = File.ReadAllLines(@"graph_input.txt");
            int[] arr = lines[0].Split(' ').Select(str => int.Parse(str)).ToArray();
            n = arr[0];
            m = arr[1];

            int st, en;
            float we;
            for (int i = 1; i <= m; i++)
            {
                lines[i] = lines[i].Replace('.', ',');
                float[] data = lines[i].Split(' ').Select(str => float.Parse(str)).ToArray();

                st = (int)data[0];
                en = (int)data[1];
                we = data[2];
                gArms.AddEdge(st.ToString(), we.ToString(), en.ToString());
                gArms.GraphAttr.EdgeAttr.ArrowHeadAtTarget = ArrowStyle.None;
            }
            gViewer.Graph = gArms;
            enable_kruskals();
        }

        private void nPeaks_ValueChanged(object sender, EventArgs e)
        {
            btnClear_Click(sender, e);
            if (nPeaks.Value.Equals(ZERO))
            {
                edgeStart.Value= 0;
                edgeEnd.Value = 0;
                edgeStart.Visible = false;
                edgeEnd.Visible = false;
                return;
            }
            edgeStart.Visible = true;
            edgeEnd.Visible = true;
            edgeStart.Maximum = nPeaks.Value-1;
            edgeEnd.Maximum = nPeaks.Value-1;
        }

        private void nEdges_ValueChanged(object sender, EventArgs e)
        {
            btnClear_Click(sender, e);
            numericUpDown1.Maximum = nEdges.Value;
        }

        private void btnAddEdge_Click(object sender, EventArgs e)
        {
            disable_kruskals();
            float weight;
            if (edgeEnd.Value.Equals(edgeStart.Value))
            {
                MessageBox.Show("No loops!");
                return;
            }
            if (numericUpDown1.Value >= nEdges.Value)
            {
                MessageBox.Show("Please increase total peaks number");
                return;
            }
            if (nEdges.Value.Equals(ZERO))
            {
                btnGenerate_Click(sender, e);
                return;
            }
            if (numericUpDown1.Value.Equals(ZERO))
            {
                if (nPeaks.Value <= 0)
                {
                    MessageBox.Show("Number of peaks must be more than zero.");
                    return;
                }
                if (nEdges.Value < 0)
                {
                    MessageBox.Show("Number of edges can not be less than zero.");
                    return;
                }
                try{
                    weight = float.Parse(edgeWeight.Text.ToString().Replace('.',','));
                }catch{
                    MessageBox.Show("Not corerect weight.");
                    return;
                }
                FileInfo f = new FileInfo(@"graph_input.txt");
                FileStream s = f.Open(FileMode.Create, FileAccess.ReadWrite);
                s.Close();

                StreamWriter w = f.CreateText();
                w.Write(0 + "\n");
                w.Write("" + nPeaks.Value + " " + nEdges.Value + "\n");
                w.Close();
                gArms = new Graph("graph");
                gArms.GraphAttr.EdgeAttr.ArrowHeadAtTarget = ArrowStyle.None;
                for (int i = 0; i < nPeaks.Value; i++)
                    gArms.AddNode(i.ToString());
                edgeArr = new Edge[(int)(nEdges.Value)];
                for (int i = 0; i < nEdges.Value; i++)
                {
                    edgeArr[i] = new Edge();
                }
            }// создать новый файл
            for (int i = 0; i < numericUpDown1.Value; i++)
            {
                if ( (edgeArr[i].s.Equals((int)edgeStart.Value) && edgeArr[i].e.Equals((int)edgeEnd.Value)) 
                  || (edgeArr[i].e.Equals((int)edgeStart.Value) && edgeArr[i].s.Equals((int)edgeEnd.Value)))
                {
                    MessageBox.Show("This edge has already added.");
                    return;
                }
            }
            FileInfo f2 = new FileInfo(@"graph_input.txt");
            FileStream s2 = f2.Open(FileMode.Append, FileAccess.Write);
            s2.Close();
            StreamWriter w2 = new StreamWriter(@"graph_input.txt", true);
            w2.Write(edgeStart.Value+" "+edgeEnd.Value + " " + float.Parse(edgeWeight.Text.ToString().Replace('.',','))+"\n");
            w2.Close();
            edgeArr[(int)numericUpDown1.Value].s = (int)edgeStart.Value;
            edgeArr[(int)numericUpDown1.Value].e = (int)edgeEnd.Value;
            gArms.AddEdge(edgeStart.Value.ToString(), edgeWeight.Text.ToString(), edgeEnd.Value.ToString());

            numericUpDown1.Value++;
        }

        private void btnDownload_Click(object sender, EventArgs e)
        {
            disable_kruskals();
            if (!numericUpDown1.Value.Equals(nEdges.Value))
            {
                MessageBox.Show("Add more edges.");
                gArms = new Graph("g");
                gViewer.Graph = gArms;

                return;
            }     
            numericUpDown1.Value = 0;
            var process = Process.Start("kruskal.exe");
            process.WaitForExit();
            if (!File.Exists("graph_output.txt") || !File.Exists("graph_input.txt"))
            {
                MessageBox.Show("Something goes wrong.");
                gArms = new Graph("g");
                gViewer.Graph = gArms;
                return;
            }
            gViewer.Graph = gArms;
            enable_kruskals();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            disable_kruskals();
            if (!File.Exists("graph_output.txt"))
            {
                MessageBox.Show("Can not apply kruskal on this graph.");
                return;
            }

            int n, m;            
            String []lines = File.ReadAllLines(@"graph_output.txt");
            int[] arr = lines[0].Split(' ').Select(str => int.Parse(str)).ToArray();
            n = arr[0];
            m = arr[1];            

            int st, en;
            float we;
            for (int i = 1; i <= m; i++)
            {
                lines[i] = lines[i].Replace('.', ',');
                float[] data = lines[i].Split(' ').Select(str => float.Parse(str)).ToArray();

                st = (int)data[0]; 
                en = (int)data[1];
                we = data[2];
                for (int j = 0; j < gArms.Edges.Count(); j++)
                {
                    if (gArms.Edges.ElementAt(j).SourceNode.Id.Equals(st.ToString())
                      && gArms.Edges.ElementAt(j).TargetNode.Id.Equals(en.ToString()))
                    {
                        gArms.Edges.ElementAt(j).EdgeAttr.Color = Microsoft.Glee.Drawing.Color.Red;
                        gArms.Edges.ElementAt(j).EdgeAttr.LineWidth = gArms.GraphAttr.LineWidth + 4;
                        break;
                    }
                }
                //int st - начало ребра в каркасе; int en - конец;float we - вес(как метка)
            }
            gViewer.Refresh();       
        }

        private async void button3_Click(object sender, EventArgs e)
        {
            disable_kruskals();
            if (!File.Exists("graph_output.txt"))
            {
                MessageBox.Show("Can not apply kruskal on this graph.");
                return;
            }

            int n, m;
            String[] lines = File.ReadAllLines(@"graph_output.txt");
            int[] arr = lines[0].Split(' ').Select(str => int.Parse(str)).ToArray();
            n = arr[0];
            m = arr[1];

            int st, en;
            float we;
            button1.Enabled = true;
            for (int i = 1; i <= m; i++)
            {
                NextIsClicked = false;
                while (!NextIsClicked)
                    await System.Threading.Tasks.Task.Delay(20);
                lines[i] = lines[i].Replace('.', ',');
                float[] data = lines[i].Split(' ').Select(str => float.Parse(str)).ToArray();
                st = (int)data[0];
                en = (int)data[1];
                we = data[2];

                for (int j = 0; j < gArms.Edges.Count(); j++)
                {
                    if ( gArms.Edges.ElementAt(j).SourceNode.Id.Equals(st.ToString())
                      && gArms.Edges.ElementAt(j).TargetNode.Id.Equals(en.ToString()) )
                    {
                        gArms.Edges.ElementAt(j).EdgeAttr.Color = Microsoft.Glee.Drawing.Color.Red;
                        gArms.Edges.ElementAt(j).EdgeAttr.LineWidth = gArms.GraphAttr.LineWidth + 4;
                        gViewer.Refresh();
                        break;
                    }
                }                
            }
            gViewer.Refresh();
            button1.Enabled = false;      
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NextIsClicked = true;
        }

        public void disable_kruskals()
        {
            button2.Enabled = false;
            button3.Enabled = false;
        }

        public void enable_kruskals()
        {
            button2.Enabled = true;
            button3.Enabled = true;
        }
    }
}