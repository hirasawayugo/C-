using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;

public class DistinctUntilChanged : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();

    void Start()
    {
        sub
        .DistinctUntilChanged() 
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("イベント");
        sub.OnNext("イベント発生");
        sub.OnNext("イベント発生");
        sub.OnNext("イベント");
        sub.OnNext("イベント");
    }
}
