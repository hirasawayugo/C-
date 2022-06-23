using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class Last : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    async void Start()
    {
        sub
        .Last()
        .Subscribe(text => Debug.Log(text));
        sub.OnNext("A");
        sub.OnNext("B");
        await Task.Delay(1000);
        sub.OnNext("C");
        sub.OnCompleted();
    }
}
