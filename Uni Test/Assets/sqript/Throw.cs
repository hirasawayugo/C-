using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class Throw : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        string message = "error";
        sub.Subscribe(msg => Debug.Log(msg));
        sub.OnNext("A");
        UniRx.Observable
                .Throw<Unit>(new Exception(message))
                .Subscribe(_ => Debug.Log("B"));
        sub.OnNext("C");
    }
}
