using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;
using System;

public class Reactivecollection : MonoBehaviour
{
    private ReactiveCollection<int> list;
    private int counter = 0;
    void Start()
    {
        list = new ReactiveCollection<int>();
        list.ObserveAdd()
        .Subscribe(x => Debug.Log(x))
        .AddTo(this);
        list.ObserveRemove()
        .Subscribe(x => Debug.Log(x))
        .AddTo(this);
        list.ObserveCountChanged()
        .Subscribe(x => Debug.Log("要素数" + x))
        .AddTo(this);
    }
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.A)){
            counter++;
            list.Add(counter);
        }
        if(Input.GetKeyDown(KeyCode.D)){
            list.Remove(counter);
            counter--;
        }
    }
}
