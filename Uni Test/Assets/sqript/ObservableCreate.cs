using System.Collections;
using UnityEngine;
using UniRx;
using System;

public class ObservableCreate : MonoBehaviour
{
    void Start()
    {
        // Observable.Create<string>( observer =>
        // {
        //     Debug.Log("イベント発行処理開始");
        //     //yield return new WaitForSeconds(5);
        //     observer.OnNext("イベント発行");
        //     Debug.Log("イベント発行処理終了");
        //     observer.OnCompleted();
        //     return Disposable.Create(() =>
        //     {
        //         Debug.Log("破棄処理開始");
        //         //yield return new WaitForSeconds(3);
        //         Debug.Log("破棄処理開始");
        //     });
        // }).Subscribe(msg => Debug.Log(msg));
    }
}
