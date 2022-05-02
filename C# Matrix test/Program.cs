using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
           Vector2D vec1 = new Vector2D(0,0);
           Vector2D vec2 = new Vector2D(1,1);
           Calculator calc = new Calculator();

            double radian = 90 * 3.14 / 180;

            Matrix33 mat = new Matrix33( 0,0,0,0,0,0,0,0,0 );
            mat = Matrix33.Rotate((float)radian);

            Vector2D vec3 = mat * vec2;

            Console.WriteLine("X:{0} Y:{1}",vec3.X, vec3.Y );
        }
    }
}
