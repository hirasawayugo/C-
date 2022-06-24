using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class IgnoreElements : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub
        .IgnoreElements()
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
        sub.OnNext("C");
    }
}
