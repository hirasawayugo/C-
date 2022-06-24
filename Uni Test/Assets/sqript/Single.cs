using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Single : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub
        .Single()
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
    }
}
