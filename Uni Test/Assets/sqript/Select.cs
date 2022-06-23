using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;

public class Select : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub
        .Select(text => text + text)
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("イベント発生");
    }
}
