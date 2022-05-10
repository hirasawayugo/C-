using System;

namespace C__hierarchy
{
    class Program
    {
        static void Main()
        {
            A a = new A();
            B b = new B();
            C c = new C();
            D d = new D();

            a.AddChild(b);
            b.AddChild(c);
            c.AddChild(d);
            
            Console.WriteLine("Aの子供は");
            a.ShowChildren();
            Console.WriteLine("Bの子供は");
            b.ShowChildren();
            Console.WriteLine("Cの子供は");
            c.ShowChildren();
            Console.WriteLine("Dの子供は");
            d.ShowChildren();
        }
    }
}
