using System;

class Matrix
{
    // 適当な関数（メソッド）
     public int [,]mult( int[,] mn, int[,] np)
    {
        if(mn.GetLength(1) != np.GetLength(0)){
            Console.WriteLine("nの値が一致しないため計算できません");
            return new int [0,0];
        }
        int[,] value = new int [mn.GetLength(0),np.GetLength(1)];
        for (int i = 0; i < mn.GetLength(0); i++) {
            for (int j = 0; j < np.GetLength(1); j++) {
                int sum = 0;
                for (int k = 0; k < 2; k++) {
                    sum += mn[i,k] * np[k,j];
                }
                value[i,j] = sum;
            }
        }
        return value;
    }
}