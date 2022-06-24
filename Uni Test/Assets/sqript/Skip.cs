using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Skip : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    async void Start()
    {
        sub
        .Skip(2)
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        await Task.Delay(1000);
        sub.OnNext("B");
        sub.OnNext("C");
    }
}
