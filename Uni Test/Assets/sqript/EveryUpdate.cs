using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class EveryUpdate : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        sub.Subscribe(msg => Debug.Log(msg));
        sub.OnNext("A");
         UniRx.Observable
                .EveryUpdate()
                .Subscribe(_ => Debug.Log("C"));
    }
    void Update()
    {
        sub.OnNext("B");
    }
}
