using UnityEngine;
using UniRx;
using UniRx.Triggers;

public class Repeat : MonoBehaviour
{
    void Start()
    {
        string text = "A";
        int num = 5;
        UniRx.Observable
                .Repeat(text, num)
                .Subscribe(msg => Debug.Log(msg));
    }
}
