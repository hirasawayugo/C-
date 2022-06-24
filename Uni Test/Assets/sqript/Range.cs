using UnityEngine;
using UniRx;
using UniRx.Triggers;

public class Range : MonoBehaviour
{
    void Start()
    {
        int start = 7;
        int count = 5;
        UniRx.Observable
                .Range(start, count)
                .Subscribe(msg => Debug.Log(msg));
    }
}
