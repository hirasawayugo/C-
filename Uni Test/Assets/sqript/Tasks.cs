using UnityEngine;
using Cysharp.Threading.Tasks;

public class Tasks : MonoBehaviour
{
    private async void Start()
    {
        var task =  Wait(5, "A").Preserve();
        await task;
        await task;
    }
    private async UniTask Wait(float waitTime, string name)
    {
        Debug.Log(name + "処理開始");
        await UniTask.Delay((int)(waitTime * 1000));
        Debug.Log(name + "処理終了");
    }
}
