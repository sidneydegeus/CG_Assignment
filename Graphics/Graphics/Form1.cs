﻿using System;
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
        bool rotating = false;

        Square sq1 = new Square(Color.Red);
        Pentagon pg1 = new Pentagon(Color.Black);
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
            sq1.Draw(e.Graphics, vb);
            pg1.Draw(e.Graphics, pg1.vb);

            Matrix S = Matrix.Scale(2.5f);
            vb = new List<Vector2D>();
            foreach (Vector2D v in sq2.vb)
            {
                Vector2D vp = S * v;
                
                vb.Add(vp);
            }

            vb = ViewportTransformation(800, 600, vb);
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
            }

            return res;
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e) {
            if (e.KeyChar.ToString() == "r") {
                if (rotating)
                    rotating = false;
                else
                    rotating = true;

                foreach (Vector2D v in sq2.vb) {
                    var ca = Math.Cos(Math.PI / 180);
                    var sa = Math.Sin(Math.PI / 180);

                    v.x = v.x - (float) sa * v.y;
                    v.y = (float)sa * v.x + (float)ca * v.y;

                }
                Invalidate();
            }

            if (e.KeyChar.ToString() == "s") {
                // scale shit
                foreach (Vector2D v in sq2.vb)
                {
                    v.x *= 0.99f;
                    v.y *= 0.99f;
                }
                Invalidate();
            }

            if (e.KeyChar.ToString() == "d")
            {
                // scale shit
                foreach (Vector2D v in sq2.vb)
                {
                    v.x *= 1.01f;
                    v.y *= 1.01f;
                }
                Invalidate();
            }
        }
    }
}
