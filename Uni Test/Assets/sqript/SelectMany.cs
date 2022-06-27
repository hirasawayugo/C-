using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class SelectMany : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        UniRx.Observable
            .SelectMany(sub, x => x + "B")
            .Subscribe(_=>Debug.Log(_));
        sub.OnNext("A");
    }
}
