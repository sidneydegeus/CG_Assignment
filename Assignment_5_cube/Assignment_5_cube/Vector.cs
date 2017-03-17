using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_5_cube {
    public class Vector {
        public float x, y, z, w;

        public Vector() : this(0, 0, 0) { }

        public Vector(float x, float y, float z, float w = 1) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        public static Vector operator +(Vector v1, Vector v2) {
            return new Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        }

        public static Vector operator -(Vector v1, Vector v2) {
            return new Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
        }

        public static float operator *(Vector v1, Vector v2) {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }

        public void Transpose() {
            Matrix matrix = new Matrix(this);
            Vector vector = Matrix.Transpose(matrix);
            this.x = vector.x;
            this.y = vector.y;
            this.z = vector.z;
            this.w = vector.w;
        }
    }
}
