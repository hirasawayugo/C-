using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
           Vector2D vec = new Vector2D(1,1);

            double radian = 90 * 3.14 / 180;

            Matrix33 mat = Matrix33.Initialize;
            mat = Matrix33.Rotate((float)radian);

            Vector2D rotateVec = mat * vec;

            Console.WriteLine("X:{0} Y:{1}",rotateVec.X, rotateVec.Y );
        }
    }
}
