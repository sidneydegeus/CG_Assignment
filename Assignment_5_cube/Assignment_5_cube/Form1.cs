using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_5_cube {
    public partial class Form1 : Form {

        Cube cube = new Cube(Color.Black);
        AxesX ax = new AxesX();
        AxesY ay = new AxesY();
        AxesZ az = new AxesZ();
        float scale = 1.0f;
        float tx = 0.0f;
        float ty = 0.0f;
        float tz = 0.0f;
        float rx = 0.0f;
        float ry = 0.0f;
        float rz = 0.0f;
        float r = 10f;
       
        float d = 800;
        float theta = -90f;
        float phi = -90f;

        Timer myTimer = new Timer();
        IIntellisenseBuilder fase = 0;

        private void TimerEventProcessor(Object myObject, EventArgs myEventArgs) {

        }

        public Form1() {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e) {

        }
    }
}
