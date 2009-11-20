using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace MapnikWrapperTester
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
        }

        private void test(double a, double b, double c, double d)
        {
            Console.WriteLine(a.ToString() + " " + c.ToString());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //try
            //{
            //    //  Environment.SetEnvironmentVariable("PROJ_LIB", "c:\\data\\dev\\capwinclient2\\org.capwin.client\\bin\\debug\\nad");
            //    org.capwin.gis.mapnik.MapnikWrapper wrapper;
            //    wrapper = new org.capwin.gis.mapnik.MapnikWrapper();
            //    wrapper.InitializeIncidentLayer("c:\\data\\dev\\capwinclient2\\org.capwin.client\\bin\\debuge");
                
            //    wrapper.RenderToFile("c:\\temp\\demo.png","png", 700, 700,  39.000, -77.100,  39.200, -76.900 );
            //    FileStream file = new FileStream("c:\\temp\\demo.png", FileMode.Open);
            //    pictureBox1.Image = System.Drawing.Image.FromStream(file);
            //    file.Close();
            //}
            //catch (Exception eE)
            //{
            //    Console.WriteLine(eE.Message);
            //    Console.WriteLine(eE.StackTrace);
            //}

        }

        private void button3_Click(object sender, EventArgs e)
        {
      




            
            
            GC.Collect();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                //   for (int i = 0; i < 1000; i++)
                //  {
                //  Environment.SetEnvironmentVariable("PROJ_LIB", "c:\\data\\dev\\capwinclient2\\org.capwin.client\\bin\\debug\\nad");
                Console.Write("test start");
                org.capwin.gis.mapnik.MapnikWrapper wrapper;
                wrapper = new org.capwin.gis.mapnik.MapnikWrapper();
                FixupMapXML();

                //wrapper.InitializeBaseLayer("c:\\data\\dev\\capwinclient2\\org.capwin.client\\bin\\debug");
                wrapper.InitializeXMLLayer("c:\\program files\\capwin\\clienttest\\app", "C:\\temp\\map.xml");

                //wrapper.RenderToFile("c:\\temp\\demo.png", 700, 700, 38.9782777899615, -76.8870414693469, 38.9982777899615, -76.8670414693469);


                for (int i = 0; i < 10; i++)
                {
                    wrapper.RenderToFile("c:\\temp\\demo.png", "png", 700 + 128 * 2, 700 + 128 * 2, 38.84765625, -77.6953125, 38.759765625, -77.607421875);
                    LoadImage();
                    wrapper.RenderToFile("c:\\temp\\demo.png", "png", 700 + 128 * 2, 700 + 128 * 2, 39.0234375, -77.607421875, 38.935546875, -77.51953125);
                    LoadImage();
                    wrapper.RenderToFile("c:\\temp\\demo.png", "png", 700 + 128 * 2, 700 + 128 * 2, 38.935546875, -77.080078125, 38.84765625, -76.9921875);
                    LoadImage();



                }
                wrapper.Dispose();
                wrapper = null;
                    
                // }
            }
            catch (Exception eE)
            {
                Console.WriteLine(eE.Message);
                Console.WriteLine(eE.StackTrace);
            }
        }

        private void LoadImage()
        {
            FileStream file = new FileStream("c:\\temp\\demo.png", FileMode.Open);
            pictureBox1.Image = System.Drawing.Image.FromStream(file);
            file.Close();

            Application.DoEvents();
            Thread.Sleep(500);

        }

        private void FixupMapXML()
        {
            try
            {
                string path = "c:\\data\\dev\\capwinclient2\\org.capwin.client\\bin\\debug";
                string unixPath = path.Substring(2);
                unixPath = unixPath.Replace("\\", "/");

                FileStream templateFile = new FileStream("c:\\temp\\map.xml", FileMode.Open);
                StreamReader sr = new StreamReader(templateFile);

                FileStream xmlFile = new FileStream(path + "\\temp\\map.xml", FileMode.Create);
                StreamWriter sw = new StreamWriter(xmlFile);

                string s;
                s = sr.ReadLine();
                do
                {
                    s = s.Replace("[UAPPDIR]", unixPath);
                    s = s.Replace("[APPDIR]", path);
                    sw.WriteLine(s);
                    s = sr.ReadLine();
                } while (s != null);
                sw.Close();
                sr.Close();
            }
            catch (Exception eE)
            {
                
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
         
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}