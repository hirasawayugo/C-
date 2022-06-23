using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Cysharp.Threading.Tasks;

public class ATask : MonoBehaviour
{
    private async void Start()
    {
        //5秒待機後に処理の名前を表示
        await UniTaskWait(5);
    }
    private async UniTask<string> UniTaskWait(float waitTime)
    {
        Debug.Log("A処理開始");
        await UniTask.Delay((int)(waitTime * 1000));
        Debug.Log("A処理終了");
        return "A処理";
    }
}
