using System.Collections;
using UniRx;
using UnityEngine;
using System;

public class Observer : MonoBehaviour
{
    private Subject<int> sub = new Subject<int>();
    public IObservable<int> Subject
    {
        get { return sub; }
    } 
    void Start()
    {
        sub.OnNext(100);
    }
}
