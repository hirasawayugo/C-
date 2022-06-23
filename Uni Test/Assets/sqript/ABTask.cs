using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Cysharp.Threading.Tasks;

public class ABTask : MonoBehaviour
{
    // Start is called before the first frame update
    private async void Start()
    {
        //Aの5秒待機後に処理の名前を表示
        string name1 =  await Wait(5, "A");
        //Bの3秒待機後に処理の名前を表示
        string name2 = await Wait(3, "B");
    }
    private async UniTask<string> Wait(float waitTime, string name)
    {
        Debug.Log(name + "処理開始");
        await UniTask.Delay((int)(waitTime * 1000));
        Debug.Log(name + "処理終了");
        return name + "処理";
    }
}
