using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Amb : MonoBehaviour
{
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        UniRx.Observable
        .Amb(sub2,sub1)
        .Subscribe(x => Debug.Log(x));
        sub1.OnNext("A");
        sub2.OnNext("B");
        sub2.OnNext("C");
        sub1.OnNext("D");
    }
}
