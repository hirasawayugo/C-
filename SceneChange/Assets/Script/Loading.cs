using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using UniRx;
using UniRx.Triggers;
using Cysharp.Threading.Tasks; 
using System.Threading.Tasks;
using System.Threading;
using System.IO;
using System;

public class Loading : MonoBehaviour
{
    [SerializeField]
    public GameObject button;
    [SerializeField]
    public GameObject LoadUI;
    [SerializeField]
    public Slider slider;
    [SerializeField]
    private float fadeTime = 0;
    private float time = 0;
    private bool fadeFlag = false;
    private Image fadeImage;
    private ReactiveProperty<float> alpha = new ReactiveProperty<float>(0);
    private AudioSource audio;
    private const float MaxVolume = 0.2f;

    private void Start()
    {
        audio = GetComponent<AudioSource>();
        fadeImage = LoadUI.GetComponent<Image>();
        //フェードでのα値の変化でUIの更新を行う
        alpha.Subscribe( value =>
        {
            fadeImage.color = new Color(0,0,0,value);
        });
    }
    public void ClickStart()
    {
        UniRx.Observable
        .TimerFrame(1)
        .Repeat()
        .TakeWhile(_ => fadeFlag == false)
        .Subscribe(_ => fadeOut());
        button.SetActive(false);
        audio.Play();
        MainRun(this.GetCancellationTokenOnDestroy()).Forget();
        ReadFile(this.GetCancellationTokenOnDestroy()).Forget();
    }
    private void fadeOut()
    {
        if( time <= fadeTime){
            alpha.Value = time / fadeTime;
            audio.volume = MaxVolume * (time / fadeTime);
            time += Time.deltaTime;
        }
    }
    private void fadeIn()
    {
        if( time <= fadeTime){
            alpha.Value = 1 - time / fadeTime;
            audio.volume = MaxVolume * (1 - time / fadeTime);
            time += Time.deltaTime;
        }
    }
    private async UniTask MainRun(CancellationToken token)
    {
        await UniTask.WaitUntil(() => alpha.Value >= 0.9f,cancellationToken: token);
        Debug.Log("フェードアウト終了");
        FadeOutEnd();
        await UniTask.WaitUntil(() => slider.value >= 1.0f,cancellationToken: token);
        Debug.Log("ロード画面終了");
        LoadEnd();
        await UniTask.WaitUntil(() => alpha.Value <= 0.1f,cancellationToken: token);
        Debug.Log("フェードイン終了");
        FadeInEnd();
    }
    private async UniTask ReadFile(CancellationToken token)
    {
        Debug.Log("ファイル読み込み開始");
        //非同期ファイル読み込み
        string path = "C:/Users/hirasawa.yugo/Desktop/SceneChange/test.txt";
        for(int i = 0; i < 100; i++){
            StreamReader fs = new StreamReader(path, System.Text.Encoding.GetEncoding("UTF-8"));
            string result = fs.ReadToEnd();
            await UniTask.Delay(100,cancellationToken: token);
            slider.value = Mathf.Lerp(0,1,(float)(i / 95.0));
        }
    }
    private void FadeOutEnd()
    {
        fadeFlag = true;
        time = 0;
        fadeImage.color = new Color(0,0,0,1);
        foreach(Transform child in LoadUI.transform)
        {
            GameObject cObject = child.gameObject;
            cObject.SetActive(true);
        }
    }
    private void LoadEnd()
    {
        foreach(Transform child in LoadUI.transform)
        {
            GameObject cObject = child.gameObject;
            cObject.SetActive(false);
        }
        UniRx.Observable
        .TimerFrame(1)
        .Repeat()
        .TakeWhile(_ => fadeFlag == true)
        .Subscribe(_ => fadeIn());
    }
    private void FadeInEnd()
    {
        fadeImage.color = new Color(0,0,0,0);
        fadeFlag = false;
        time = 0;
        button.SetActive(true);
        audio.Stop();
    }
}
