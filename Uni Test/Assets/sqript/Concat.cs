using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Concat : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        sub
            .Concat(sub1,sub2)
            .Subscribe(x=>Debug.Log(x));
        sub1.OnNext("A");
        sub2.OnNext("B");
        sub1.OnCompleted();
        sub1.OnNext("D");
        sub2.OnNext("C");
        sub2.OnCompleted();
    }
}
