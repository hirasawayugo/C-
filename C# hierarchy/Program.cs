using System;

namespace C__hierarchy
{
    class Program
    {
        static void Main()
        {
            Calculator calc = new Calculator();
            A a = new A();
            B b = new B();
            C c = new C();
            D d = new D();

            a.AddChild(b);
            b.AddChild(c);
            c.AddChild(d);

            a.Forward( new Vector2D(1,1));
            b.Forward( new Vector2D(1,0));
            b.Rotate(calc.Radians(180));
            c.Forward( new Vector2D(0,1));
            d.Forward( new Vector2D(1,1));

            Console.WriteLine("Aの状態");
            a.Log();
            Console.WriteLine("Bの状態");
            b.Log();
            Console.WriteLine("Cの状態");
            c.Log();
            Console.WriteLine("Dの状態");
            d.Log();
        }
    }
}
