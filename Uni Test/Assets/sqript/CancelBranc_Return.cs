using UnityEngine;
using Cysharp.Threading.Tasks;
using UniRx.Triggers;
using System.Threading;
using System;

public class CancelBranc_Return : MonoBehaviour
{
    private  CancellationTokenSource cts;
    private async void Start()
    {
        cts = new CancellationTokenSource();
        var canceled = await A(cts.Token).SuppressCancellationThrow();
        if(canceled){
            await B();
        }
    }
    void Update(){
        Cancel();
    }
    private async UniTask A(CancellationToken token)
    {
        Debug.Log("A処理開始");
        await UniTask.Delay(5000,cancellationToken: token);
        Debug.Log("A処理終了");
    } 
    private async UniTask B()
    {
        Debug.Log("B処理開始");
        await UniTask.Delay(10000);
        Debug.Log("B処理終了");
    } 
    void Cancel(){
        if (Input.GetKeyDown (KeyCode.C)) {
            cts.Cancel();
            Debug.Log("キャンセルしました");
        }
    }
}
