using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;

namespace Assignment_5_cube {
    public partial class Form1 : Form {

        Cube cube = new Cube(Color.Black);
        AxesX ax = new AxesX();
        AxesY ay = new AxesY();
        AxesZ az = new AxesZ();
        float scale = 1.01f;
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
        int fase = 2;
        bool scaleUp = true;
        bool rotatingX = false;

        //   IIntellisenseBuilder fase = 0;

        void timer_Tick(object sender, EventArgs e)
        {
            switch(fase)
            {
                case 1:
                    theta--;
                    break;
                case 2:
                    theta--;
                    if (rx < 45.0f && !rotatingX) {
                        rx++;
                    } else if (rx > 0.0f && rotatingX) {
                        rx--;
                    }

                    if (rx >= 45.0f)
                        rotatingX = true;
                    else if (rx <= 0.0f) 
                        rotatingX = false;
                    
                    break;
                    
                case 3:
                    phi++;
                    break;
                case 4:
                    break;


            }

            Invalidate();
        }
        public Form1() {
            InitializeComponent();
            this.Size = new Size(800, 600);

            //Matrix m1 = new Matrix();
            //Console.WriteLine(m1);
            //Matrix m2 = new Matrix(3, 0, 4, 0, 5, 0, 1, 3, 0, 4, 0, 5, 0, 0, 0, 1);
            //Console.WriteLine(m1 + m2);

            System.Windows.Forms.Timer t = new System.Windows.Forms.Timer();


            t.Interval = 50; // specify interval time as you want
            t.Tick += new EventHandler(timer_Tick);
           // t.Start();
        }

        private void Form1_Load(object sender, EventArgs e) {
            
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            List<Vector> vb;
            Matrix S = Matrix.Scale(scale);
            Matrix T = Matrix.Translate(new Vector());
            Matrix R = Matrix.rotateX(rx * (float)(Math.PI / 180)) * Matrix.rotateY(ry * (float)(Math.PI / 180)) * Matrix.rotateZ(rz * (float)(Math.PI / 180));
            Matrix model = S * T * R;

            // Create our inverse m_view matrix (converting degrees to radians)
            Matrix matrixView = Matrix.inverseView(r, (float) (phi * Math.PI / 180), (float) (theta * Math.PI / 180));
            // Create our model_view matrix
            Matrix modelView = matrixView * model;

            // Matrix T = Matrix.Transition(vb);
            vb = new List<Vector>();
            foreach (Vector v in cube.vertexbuffer)
            {
                Vector vp = S * v;
                vb.Add(vp);
            }

            
            //vb = ViewportTransformation(800, 600, vb);
            cube.Draw(e.Graphics, viewingPipeLine(vb, modelView));

            //ax.Draw(e.Graphics, ax.vertextbuffer);
            //ay.Draw(e.Graphics, ay.vertextbuffer);
            //az.Draw(e.Graphics, az.vertextbuffer);
        }

        private List<Vector> viewingPipeLine(List<Vector> vb, Matrix modelView) {

            List<Vector> result = new List<Vector>();

            foreach (Vector v in vb) {
                Vector temp = modelView * v;
                float fov = (float)(Math.Tan(d / temp.z));
                Matrix projection = Matrix.projectionView(fov);
                result.Add(projection * temp);
           


                //vec tmp = model_vec[i] * model_view;
                //float fov = std::tan(d / tmp.z);
                //mat m_projection = projection(fov);
                //cube_buffer[i] = (tmp * m_projection);
            }

            return ViewportTransformation(800, 600, result);
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar.ToString() == "a")
            {
                System.Windows.Forms.Timer t = new System.Windows.Forms.Timer();


                t.Interval = 150; // specify interval time as you want
                t.Tick += new EventHandler(timer_Tick);
                //t.Start();
            }
        }

        public static List<Vector> ViewportTransformation(float width, float height, List<Vector> vb)
        {
            List<Vector> res = new List<Vector>();

            float delta_x = width / 2;
            float delta_y = height / 2;

            foreach (Vector v in vb)
            {
                res.Add(new Vector(v.x + delta_x, v.y + delta_y, 100));
            }

            return res;
        }



    }
}
