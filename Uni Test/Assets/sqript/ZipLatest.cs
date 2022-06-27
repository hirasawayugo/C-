using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class ZipLatest : MonoBehaviour
{
    private Subject<string> sub1 = new Subject<string>();
    private Subject<string> sub2 = new Subject<string>();
    private Subject<string> sub3 = new Subject<string>();
    void Start()
    {
        UniRx.Observable
            .ZipLatest(sub1,sub2,sub3)
            .Subscribe(_=>Debug.Log(_[0] + ", " + _[1] + "," + _[2]));
        sub1.OnNext("A");
        sub2.OnNext("B");
        sub3.OnNext("C");
        sub1.OnNext("D");
        sub2.OnNext("E");
        sub2.OnNext("F");
        sub3.OnNext("G");
    }
}
