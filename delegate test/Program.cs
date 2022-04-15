using System;
delegate void Answer();

namespace C_
{
    class Program
    {
        static void Main(string[] args)
        {
            Answer answer = new Answer((new AnswerWords()).hello);
        // 関数をデリゲートに格納

        answer += (new AnswerWords()).bey;

        answer += (new AnswerWords()).morning;
        // 関数の呼び出し
        answer();
        }
    }
}
