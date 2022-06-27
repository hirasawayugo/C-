using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class WithLatestFrom : MonoBehaviour
{
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        UniRx.Observable
            .WithLatestFrom(sub1,sub2, (a, b) => a + b)
            .Subscribe(_=>Debug.Log(_));
        sub1.OnNext("A");
        sub2.OnNext("B");
        sub1.OnNext("C");
        sub2.OnNext("D");
        sub2.OnNext("E");
        sub2.OnNext("F");
        sub1.OnNext("G");
    }
}
