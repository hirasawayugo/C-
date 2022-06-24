using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class Timer : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        int span = 5;
        sub.Subscribe(msg => Debug.Log(msg));
        sub.OnNext("A");
        UniRx.Observable
                .Timer(TimeSpan.FromSeconds(span))
                .Subscribe(msg => Debug.Log("B"));
        sub.OnNext("C");
    }
}
