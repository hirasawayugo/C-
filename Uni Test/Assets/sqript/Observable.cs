using UnityEngine;
using UniRx;
using System;

public class Observable : MonoBehaviour
{
    [SerializeField] private Observer sever = new Observer();

    void Start()
    {
        sever.Subject.Subscribe(value =>Debug.Log(value));
    }
}
