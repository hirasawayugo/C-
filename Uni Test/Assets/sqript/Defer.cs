using UnityEngine;
using UniRx;
using UniRx.Triggers;

public class Defer : MonoBehaviour
{
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    void Start()
    {
        sub1.Subscribe(msg => Debug.Log(msg));
        sub2.Subscribe(msg => Debug.Log(msg));
        UniRx.Observable
                .Defer(()=> sub1)
                .Subscribe(msg => Debug.Log("Defer" + msg));
        sub1.OnNext("A");
        sub2.OnNext("B");
    }
}
