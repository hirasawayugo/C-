using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class SkipWhile : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub
        .SkipWhile(x => x != "B")
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
        sub.OnNext("C");
    }
}
