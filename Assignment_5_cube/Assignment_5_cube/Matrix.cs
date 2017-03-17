using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_5_cube
{
    class Matrix
    {
        float[,] mat = new float[4, 4];

        public Matrix(
            float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44)
        {
            mat[0, 0] = m11; mat[0, 1] = m12; mat[0, 2] = m13; mat[0, 3] = m14;
            mat[1, 0] = m21; mat[1, 1] = m22; mat[1, 2] = m23; mat[1, 3] = m24;
            mat[2, 0] = m31; mat[2, 1] = m32; mat[2, 2] = m33; mat[2, 3] = m34;
            mat[3, 0] = m41; mat[3, 1] = m42; mat[3, 2] = m43; mat[3, 3] = m44;
        }

        public Matrix(float f = 1.0f) :
            this(f, 0, 0, 0,
                  0, f, 0, 0,
                  0, 0, f, 0,
                  0, 0, 0, 1)
        { }

        public Matrix(Vector v) :
            this(v.x, 0, 0, 0,
                 v.y, 0, 0, 0,
                 v.z, 0, 0, 0,
                 v.w, 0, 0, 0)
        {
        }

        public static Vector ToVector2D(Matrix m1)
        {
            return new Vector(m1.mat[0, 0], m1.mat[1, 0], m1.mat[2, 0], m1.mat[3, 0]);
        }

        public static Matrix operator +(Matrix m1, Matrix m2)
        {
            Matrix m = new Matrix();
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++)
                    m.mat[r, c] = m1.mat[r, c] + m2.mat[r, c];
            return m;
        }

        public static Vector operator *(Matrix m1, Vector v)
        {
            Matrix m2 = new Matrix(v);
            Matrix m = m1 * m2;
            return ToVector2D(m);
        }

        public static Matrix operator *(Matrix m1, Matrix m2)
        {
            Matrix m = new Matrix();
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++)
                {
                    float sum = 0f;
                    for (int i = 0; i < 4; i++)
                        sum += m1.mat[r, i] * m2.mat[i, c];
                    m.mat[r, c] = sum;
                }
            return m;
        }

        public static Matrix Identity()
        {
            return new Matrix();
        }

        public static Matrix Scale(float s)
        {
            Matrix m = new Matrix(s);
            
            return m;
        }

        public static Matrix Translate(Vector v)
        {
            Matrix m = new Matrix
            (1, 0, 0, v.x,
                0, 1, 0, v.y,
                0, 0, 1, v.z,
                0, 0, 0, 1);

            return m;
        }

        public static Matrix rotateX(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float sin = (float) Math.Sin(radians);
            float cos = (float) Math.Cos(radians);

            Matrix m = new Matrix
            (1, 0, 0, 0,
            0, cos, -sin, 0,
            0, sin, cos, 0,
            0, 0, 0, 1);

            return m;
        }

        public static Matrix rotateY(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float sin = (float)Math.Sin(radians);
            float cos = (float)Math.Cos(radians);

            Matrix m = new Matrix
            (cos, 0, sin, 0,
            0, 1, 0, 0,
            -sin, 0, cos, 0,
            0, 0, 0, 1);

            return m;
        }

        public static Matrix rotateZ(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float sin = (float)Math.Sin(radians);
            float cos = (float)Math.Cos(radians);

            Matrix m = new Matrix
            (cos, -sin, 0, 0,
            sin, cos, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);

            return m;
        }

        public static Vector Transpose(Matrix m)
        {
            int w = m.mat.GetLength(0);
            int h = m.mat.GetLength(1);

            float[,] result = new float[h, w];

            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    result[j, i] = m.mat[i, j];
                }
            }

            m.mat = result;

            return ToVector2D(m);
        }

        public static Matrix viewMatrix()
        {
            
        }

        public static inverseMatrix(float r, float phi, float theta)
        {

        }

        public override string ToString()
        {
            string s = "";
            for (int r = 0; r < 3; r++)
            {
                s += "|";
                for (int c = 0; c < 3; c++)
                    s += mat[r, c] + " ";
                s += "|\n";
            }
            return s;
        }

    }
}
