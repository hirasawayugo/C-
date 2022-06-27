using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class FromEvent1 : MonoBehaviour
{
    void Start()
    {
        //イベント
        Action<string> eventAction = (msg) => Debug.Log("Event: " + msg);
        UniRx.Observable
                .FromEvent<string>(
                    handler => eventAction += handler,//登録
                    handler => eventAction -= handler //解除
                )
                .Subscribe(msg => Debug.Log("Observable: " + msg));
        eventAction("A");
        eventAction("B");
    }
}
