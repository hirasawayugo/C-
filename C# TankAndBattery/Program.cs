using System;

namespace C__TankAndBattery
{
    class Program
    {
        static void Main()
        {
            var sw = new System.Diagnostics.Stopwatch();
            Tank tank = new Tank();
            Calculator calu = new Calculator();
            long tAngleTime, tAdvTime, bAngleTime, logTime;
            tAngleTime = tAdvTime = bAngleTime = logTime = sw.ElapsedTicks;
            tank.Debuglog();
            sw.Start();
            while(true){
                sw.Stop();
                long now = sw.ElapsedTicks /3000000;
                //戦車の角度を5秒後に1度時計回り
                if ( 5 <= (now - tAngleTime)) {
                    tank.Rotate(calu.Radians(1));
                    tAngleTime = now;
                }
                //砲台の角度を1秒後に45度反時計回り
                if (1 <= (now - bAngleTime)) {
                    tank.BatRotate(calu.Radians(-45));
                    bAngleTime = now;
                }
                //戦車を１０秒後に1単位前進
                if (10 <= (now - tAdvTime)) {
                    tank.Advance(1);
                    tAdvTime = now;
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
