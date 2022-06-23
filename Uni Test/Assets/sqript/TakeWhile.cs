using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class TakeWhile : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    async void Start()
    {
        sub
        .TakeWhile(x => x != "C")
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
        await Task.Delay(1000);
        sub.OnNext("C");
        sub.OnNext("D");
    }
}
