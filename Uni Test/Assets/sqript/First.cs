using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class First : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    async void Start()
    {
        sub
        .First() 
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
        await Task.Delay(1000);
        sub.OnNext("C");
    }
}
