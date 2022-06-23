using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;

public class Distinct : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub
        .Distinct()
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("イベント発生");
        sub.OnNext("イベント発生");
        sub.OnNext("イベント発生");
    }
}
