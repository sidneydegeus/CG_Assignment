using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Graphics
{
    public partial class Form1 : Form
    {
        Square sq1 = new Square(Color.Red);
        Square sq2 = new Square(Color.Blue);
        public Form1()
        {
            InitializeComponent();
            this.Size = new Size(800, 600);

            Matrix m1 = new Matrix();
            Console.WriteLine(m1);
            Matrix m2 = new Matrix(3, 0, 4, 0, 5, 0, 0, 0, 1);
            Console.WriteLine(m1 + m2);
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            List<Vector2D> vb;
            vb = ViewportTransformation(800, 600, sq1.vb);
            sq1.Draw(e.Graphics, sq1.vb);

            Matrix S = Matrix.Scale(2.5f);
            vb = new List<Vector2D>();
            foreach (Vector2D v in sq2.vb)
            {
                Vector2D vp = S * v;
                vb.Add(vp);
            }

            vb = new ViewportTransformation(800, 600, vb);
            sq2.Draw(e.Graphics, vb);
        }
        
        public static List<Vector2D> ViewportTransformation(float width, float height, List<Vector2D> vb)
        {
            List<Vector2D> res = new List<Vector2D>();

            float delta_x = width / 2;
            float delta_y = height / 2;

            foreach(Vector2D v in vb)
            {
                res.Add(new Vector2D(v.x + delta_x, v.y + delta_y));
                return res;
            }

            return res;
        }
    }
}
