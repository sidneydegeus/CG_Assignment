namespace Graphics
{
    public class Vector2D
    {
        public float x, y, w;

        public Vector2D() : this(0, 0) { }

        public Vector2D(float x, float y, float w = 1)
        {
            this.x = x;
            this.y = y;
            this.w = w;
        }

        public static Vector2D operator + (Vector2D v1, Vector2D v2)
        {
            return new Vector2D(v1.x + v2.x, v1.y + v2.y);
        }

        public static Vector2D operator - (Vector2D v1, Vector2D v2)
        {
            return new Vector2D(v1.x - v2.x, v1.y - v2.y);
        }

        public static float operator * (Vector2D v1, Vector2D v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }
    }
}