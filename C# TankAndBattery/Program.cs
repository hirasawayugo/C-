using System;

namespace C__TankAndBattery
{
    class Program
    {
        static void Main()
        {
            var sw = new System.Diagnostics.Stopwatch();
            Tank tank = new Tank();
            long tankTime, batTime, logTime;
            tankTime = batTime = logTime = sw.ElapsedTicks;
            tank.Debuglog();
            sw.Start();
            while(true){
                sw.Stop();
                long now = sw.ElapsedTicks /1000000;
                if ( 5 <= (now - tankTime)) {
                    double radian = 1 * 3.14 / 180;
                    tank.Rotate(radian);
                    tankTime = now;
                }
                //砲台の角度を1秒後に45度ずらす
                if (1 <= (now - batTime)) {
                    double radian = -45 * 3.14 / 180;
                    tank.BatRotate(radian);
                    batTime = now;
                }
                if (30 <= (now - logTime)) {
                    tank.Debuglog();
                    logTime = now;
                }
                sw.Start();
            }
        }
    }
}
