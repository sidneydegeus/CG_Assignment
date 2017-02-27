using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graphics
{
    class Matrix
    {
        float[,] mat = new float[3, 3];

        public Matrix(
            float m11, float m12, float m13,
            float m21, float m22, float m23,
            float m31, float m32, float m33)
        {
            mat[0, 0] = m11; mat[0, 1] = m12; mat[0, 2] = m13;
            mat[1, 0] = m21; mat[1, 1] = m22; mat[1, 2] = m23;
            mat[2, 0] = m31; mat[2, 1] = m32; mat[2, 2] = m33;
        }

        public Matrix(float f = 1.0f) :
            this (f, 0, 0,
                0, f, 0,
                0, 0, f)
        { }

        public Matrix(Vector2D v) :
            this(v.x, 0, 0,
                v.y, 0, 0,
                v.w, 0, 0){
        }

        public static Vector2D ToVector2D(Matrix m1)
        {
            return new Vector2D(m1.mat[0, 0], m1.mat[1, 0], m1.mat[2, 0]);
        }

        public static Matrix operator + (Matrix m1, Matrix m2)
        {
            Matrix m = new Matrix();
            for (int r = 0; r < 3; r++)
                for (int c = 0; c < 3; c++)
                    m.mat[r, c] = m1.mat[r, c] + m2.mat[r, c];
            return m;
        }

        public static Vector2D operator * (Matrix m1, Vector2D v)
        {
            Matrix m2 = new Matrix(v);
            Matrix m = m1 * m2;
            return ToVector2D(m);
        }

        public static Matrix operator * (Matrix m1, Matrix m2)
        {
            Matrix m = new Graphics.Matrix();
            for(int r = 0; r < 3; r++)
                for(int c = 0; c < 3; c++)
                {
                    float sum = 0f;
                    for (int i = 0; i < 3; i++)
                        sum += m1.mat[r, i] * m2.mat[i,c];
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
            Matrix m = new Matrix();
            m.mat[2, 2] = 1;
            return m;
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
