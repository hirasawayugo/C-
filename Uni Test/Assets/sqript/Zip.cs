using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Zip : MonoBehaviour
{
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        UniRx.Observable
            .Zip(sub1,sub2)
            .Subscribe(_=>Debug.Log(_[0] + ", " + _[1]));
        sub1.OnNext("A");
        sub1.OnNext("B");
        sub2.OnNext("C");
        sub1.OnNext("D");
        sub2.OnNext("E");
        sub2.OnNext("F");
    }
}
