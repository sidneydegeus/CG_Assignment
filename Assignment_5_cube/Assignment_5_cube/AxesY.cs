using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_5_cube {
    class AxesY {

        public List<Vector> vertextbuffer = new List<Vector> {
            new Vector(0, 0, 0),
           new Vector(0, 0, 0)
        };

        public void Draw(Graphics g, List<Vector> vb) {
            Pen pen = new Pen(Color.Red, 2f);
            g.DrawLine(pen, vb[0].x, vb[0].y, vb[1].x, vb[1].y);
            Font font = new Font("Arial", 10);
            PointF p = new PointF(vb[1].x, vb[1].y);
            g.DrawString("y", font, Brushes.Green, p);
        }
    }
}
