using UnityEngine;
using Cysharp.Threading.Tasks;
using UniRx;
using UniRx.Triggers;
using System.Threading;

public class Cancel_outside2 : MonoBehaviour
{
    void Start()
    {
        B(this.GetCancellationTokenOnDestroy()).Forget();
    }
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.C)){
            Destroy(gameObject);
            Debug.Log("ホストオブジェクトを削除しました");
        }
    }
    private async UniTask B( CancellationToken token)
    {
        Debug.Log("B処理開始");
        await UniTask.Delay(5000,cancellationToken: token);
        Debug.Log("B処理終了");
    }
}
