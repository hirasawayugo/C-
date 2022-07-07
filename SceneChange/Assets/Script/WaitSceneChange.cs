using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using UniRx;
using Cysharp.Threading.Tasks; 

public class WaitSceneChange : MonoBehaviour
{
    [SerializeField]
    public Button bStart;
    [SerializeField]
    private float waitTime = 0;
    private AsyncOperation async;

    private async void Start()
    {
        //ボタンの非アクティブ
        bStart.interactable = false;
        //スタートボタンの購読と重複防止のスパン
        bStart
        .OnClickAsObservable()
        .ThrottleFirst(System.TimeSpan.FromSeconds(3.0f))
        .Subscribe(_ => ClickStart());

        string nextSceneName = "GameScene";
        await LoadNextScene(nextSceneName);
    }
    private async UniTask LoadNextScene(string nextScene)
    {
        //シーンを非同期で読み込み(AsyncOperationに渡して追跡、変更できるようにする)
        async = SceneManager.LoadSceneAsync(nextScene);
        //シーンを読み込み終わってもすぐにシーンの移動は行わない(ボタンが押されてないから)
        await StartCoroutine(SceneActivation(false));
        //シーン読み込みが終わったらボタンを押すのを待つ
        while (bStart.interactable == false)
        {
            if(async.progress >= 0.9f)
            {
                await UniTask.Delay((int)(waitTime * 1000));
                bStart.interactable = true;
                Debug.Log("ゲームシーン読み込み完了");
                break;
            }
        }
    }
    public void ClickStart()
    {
        StartCoroutine(SceneActivation(true));
    }
    private IEnumerator SceneActivation(bool act)
    {
        yield return null;
        async.allowSceneActivation = act;
    }
}

