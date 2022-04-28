using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
           Vector2D vec1 = new Vector2D(0,0);
           Vector2D vec2 = new Vector2D(1,1);
           double diff = Math.Sqrt(Math.Pow(vec1.X - vec2.X, 2) + Math.Pow(vec1.Y - vec2.Y, 2));
            Console.WriteLine(diff);
        }
    }
}
