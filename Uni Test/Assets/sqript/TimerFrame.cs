using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class TimerFrame : MonoBehaviour
{
    private Subject<string> sub = new Subject<string>();
    void Start()
    {
        //１秒60フレーム
        int frameSpan = 60;
        sub.Subscribe(msg => Debug.Log(msg));
        sub.OnNext("A");
        UniRx.Observable
                .TimerFrame(frameSpan)
                .Subscribe(msg => Debug.Log("B"));
        sub.OnNext("C");
    }
}
