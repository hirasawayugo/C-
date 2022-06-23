using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;
using System;

public class Reactiveproperty : MonoBehaviour
{
    private ReactiveProperty<int> hp = new ReactiveProperty<int>(100);
    void Start()
    {
        hp.Subscribe( hp => Debug.Log(hp));
    }
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.A)){
            hp.Value -= 10;
        }
    }
}
