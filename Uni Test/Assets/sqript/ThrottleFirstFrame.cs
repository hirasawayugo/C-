using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class ThrottleFirstFrame : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    async void Start()
    {
        sub
        .ThrottleFirstFrame(1) 
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
        sub.OnNext("C");
        await Task.Delay(500);
        sub.OnNext("D");
        await Task.Delay(1000);
        sub.OnNext("E");
        sub.OnNext("F");
        sub.OnNext("G");
        await Task.Delay(2000);
        sub.OnNext("H");
        sub.OnNext("I");
    }
}
