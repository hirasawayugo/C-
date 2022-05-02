using System;

namespace Matrix_test
{
    class Program
    {
        static void Main()
        {
           Vector2D vec1 = new Vector2D(1,0);
           Vector2D vec2 = new Vector2D(0,1);
           Matrix33 mat = Matrix33.Initialize;

            Console.WriteLine("初期座標 X:{0}, Y:{1}",vec1.X,vec1.Y );

           Matrix33.Move( mat, vec2 );
           Vector2D moveVec = mat * vec1;
            Console.WriteLine("移動座標 X:{0}, Y:{1}", moveVec.X, moveVec.Y );

            double radian = 90 * 3.14 / 180;
            Matrix33.Rotate( mat, (float)radian );
           Vector2D rotateVec = mat * vec1;
            Console.WriteLine("回転+移動座標 X:{0}, Y:{1}", rotateVec.X, rotateVec.Y );
        }
    }
}
