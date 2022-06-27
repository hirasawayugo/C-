using UnityEngine;
using UniRx;
using UniRx.Triggers;
using System;

public class FromEvent3 : MonoBehaviour
{
    void Start()
    {
        Action<int,string> eventAction = (num,msg) => 
        {
            Debug.Log(string.Format("Event No.{0} : {1}", num, msg));
        };
        UniRx.Observable
                .FromEvent<Action<int,string>, FEArgsClass>(
                    //イベントの値を一つのメッセージにまとめる必要があるためEventArgsを使用
                    handler => (x,y) => handler(new FEArgsClass(){num = x, str = y}),
                    handler => eventAction += handler,//登録
                    handler => eventAction -= handler //解除
                )
                .Subscribe(msg => Debug.Log(string.Format("Observable No.{0} : {1}", msg.num, msg.str)));
        eventAction(1,"A");
        eventAction(2,"B");
    }
}

public class FEArgsClass:EventArgs
{
    public int num;
    public string str;
}
