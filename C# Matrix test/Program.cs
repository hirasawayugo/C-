using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
           Vector2D vec1 = new Vector2D(1,0);
           Vector2D vec2 = new Vector2D(1,1);

           double innerProduct = Vector2D.Dot( vec1, vec2 );

            Console.WriteLine("ベクトル({0},{1})とベクトル({2},{3}))",vec1.X,vec1.Y,vec2.X,vec2.Y );
            Console.WriteLine("内積:{0:F1}", innerProduct );
        }
    }
}
