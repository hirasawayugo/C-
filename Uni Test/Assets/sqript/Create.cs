using UnityEngine;
using UniRx;
using UniRx.Triggers;

public class Create : MonoBehaviour
{
    void Start()
    {
       UniRx.Observable.Create<string>(observer =>{
        Debug.Log("発行処理開始");
        observer.OnNext("A");
        observer.OnNext("B");
        observer.OnNext("C");
        Debug.Log("発行処理終了");
        observer.OnCompleted();
        return Disposable.Create(() =>
        {
            Debug.Log("破棄処理");
        });
        }).Subscribe(msg => Debug.Log(msg));
    }
}
