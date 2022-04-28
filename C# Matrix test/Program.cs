using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
           Vector2D vec1 = new Vector2D(3,4);
           Vector2D vec2 = new Vector2D(2,6);

            Vector2D addVec = vec1 + vec2;

            Console.WriteLine("X:{0} Y:{1}",addVec.X, addVec.Y);
        }
    }
}
