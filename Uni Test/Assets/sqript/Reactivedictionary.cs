using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;
using System;

public class Reactivedictionary : MonoBehaviour
{
    private ReactiveDictionary<int, int> dict;
    private int counter = 0;
    void Start()
    {
        dict = new ReactiveDictionary<int,int>();
        dict.ObserveAdd()
        .Subscribe(x => Debug.Log(x))
        .AddTo(this);
        dict.ObserveRemove()
        .Subscribe(x => Debug.Log(x))
        .AddTo(this);
        dict.ObserveCountChanged()
        .Subscribe(x => Debug.Log("要素数" + x))
        .AddTo(this);
    }
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.A)){
            counter++;
            dict.Add(counter-1, counter);
        }
        if(Input.GetKeyDown(KeyCode.D)){
            dict.Remove(counter-1);
            counter--;
        }
    }
}
