using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class Empty : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub.Subscribe(msg => Debug.Log(msg));
        sub.OnNext("A");
        UniRx.Observable
                .Empty<Unit>()
                .Subscribe(
                    _ => {Debug.Log("B");},
                    ()=> {Debug.Log("C");}
                    );
        sub.OnNext("D");
    }
}
