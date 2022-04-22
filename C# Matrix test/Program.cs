using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
            Matrix mat = new Matrix();
            int [,]mn = new int [,]{ {1,2},{3,4} };
            int [,]np = new int [,]{ {10,20},{30,40} };
            int [,]value = mat.mult(mn, np);

            for (int i = 0; i < 2; i++ ) 
            {
                for (int j = 0; j < 2; j++ ) 
                {
                    Console.WriteLine(value[i,j]);
                }
            }
        }
    }
}
