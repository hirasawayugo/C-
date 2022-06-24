using UnityEngine;
using UniRx;
using UniRx.Triggers;

public class Return : MonoBehaviour
{
    void Start()
    {
        string text = "A";
        UniRx.Observable
                .Return(text)
                .Subscribe(msg => Debug.Log(msg));
    }
}
