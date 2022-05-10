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
            a.AddChild(c);
            d.AddChild(a);
            
            Console.WriteLine("Aの子供たちは");
            a.ShowChildren();
            Console.WriteLine("Dの子供たちは");
            d.ShowChildren();
        }
    }
}
