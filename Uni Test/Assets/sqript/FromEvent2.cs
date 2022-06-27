using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class FromEvent2 : MonoBehaviour
{
    void Start()
    {
        Action<int,string> eventAction = (value,msg) => 
        {
            Debug.Log(string.Format("Event No.{0} : {1}", value, msg));
        };
        UniRx.Observable
                .FromEvent<Action<int,string>, Tuple<int, string>>(
                    //イベントの値を一つのメッセージにまとめる必要があるためタプルを使用
                    handler => (x,y) => handler(Tuple.Create(x,y)),
                    handler => eventAction += handler,//登録
                    handler => eventAction -= handler //解除
                )
                .Subscribe(msg => Debug.Log(string.Format("Observable No.{0} : {1}", msg.Item1, msg.Item2)));
        eventAction(1,"A");
        eventAction(2,"B");
    }
}
