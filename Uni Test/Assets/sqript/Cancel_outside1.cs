using UnityEngine;
using Cysharp.Threading.Tasks;
using UniRx;
using UniRx.Triggers;
using System.Threading;

public class Cancel_outside1 : MonoBehaviour
{
    [SerializeField]
    public GameObject host;
    void Start()
    {
        A(host.GetCancellationTokenOnDestroy()).Forget();
    }
    private async UniTask A(CancellationToken token)
    {
        Debug.Log("A処理開始");
        await UniTask.Delay(5000,cancellationToken: token);
        Debug.Log("A処理終了");
    } 
}
