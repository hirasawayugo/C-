using UnityEngine;
using UniRx;

public class Where : MonoBehaviour
{
    //イベント発行側
    private Subject<string> sub = new Subject<string>();

    void Start()
    {
        //購読側の処理
        sub
        //オペレーター
        .Where(text => text == "イベント発生") 
        .Subscribe(text => Debug.Log(text));
        //イベント発行(メッセージ)
        sub.OnNext("イベント");
        sub.OnNext("イベント発生");
    }
}
