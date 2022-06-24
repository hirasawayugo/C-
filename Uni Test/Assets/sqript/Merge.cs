using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Merge : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        sub
            .Merge(sub1,sub2)
            .Subscribe(x=>Debug.Log(x));
        sub1.OnNext("A");
        sub2.OnNext("B");
    }
}
