using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class SkipUntil : MonoBehaviour
{
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        sub1
        .SkipUntil(sub2)
        .Subscribe(text => Debug.Log(text));
        sub2
        .Subscribe(text => Debug.Log(text));
        sub1.OnNext("A");
        sub1.OnNext("B");
        sub2.OnNext("初回SUB2イベント");
        sub1.OnNext("C");
        
    }
}
