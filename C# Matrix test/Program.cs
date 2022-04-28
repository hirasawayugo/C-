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

            double radian = calc.angle(vec1,vec2);

            Console.WriteLine("角度:{0}",radian * 180 / 3.14);
        }
    }
}
