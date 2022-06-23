using UnityEngine;
using Cysharp.Threading.Tasks;
using UniRx.Triggers;
using System.Threading;

public class Cancel_inside : MonoBehaviour
{
    void Start()
    {
        A().Forget();
    }
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.C)){
            //自身を削除
            Destroy(gameObject);
            Debug.Log("オブジェクトが削除されました");
        }
    }
    private async UniTask A()
    {
        Debug.Log("A処理開始");
        await UniTask.Delay(10000,cancellationToken: this.GetCancellationTokenOnDestroy());
        Debug.Log("A処理終了");
    } 
}