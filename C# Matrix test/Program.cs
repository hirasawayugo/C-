using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
            Matrix33 mat33_1 = new Matrix33(1,2,3,4,5,6,7,8,9 );
            Matrix33 mat33_2 = new Matrix33(10,20,30,40,50,60,70,80,90 );

            int [,]mn44 = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} };
            int [,]np44 = { {10,20,30,40},{50,60,70,80},{90,100,110,120}, {130,140,150,160} };

            Matrix33 mult33_1 = mat33_1 * mat33_2;
            Matrix33 mult33_2 = new Matrix33(0,0,0,0,0,0,0,0,0);
            Matrix33.Multiply(ref mat33_1, ref mat33_2, ref mult33_2);
            
            Console.WriteLine("3*3");
            Console.WriteLine("オペレーター値渡し");
            for (int i = 0; i < 3; i++ ) 
            {
                Console.WriteLine("{0} {1} {2}",mult33_1[i * 3], mult33_1[i * 3 + 1], mult33_1[i * 3 + 2]);
            }
            Console.WriteLine("外部の器を参照渡し");
            for (int i = 0; i < 3; i++ ) 
            {
                Console.WriteLine("{0} {1} {2}",mult33_2[i * 3], mult33_2[i * 3 + 1], mult33_2[i * 3 + 2]);
            }
        }
    }
}
