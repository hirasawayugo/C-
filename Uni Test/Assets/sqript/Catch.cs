using UnityEngine;
using UniRx;
using System;
using System.Threading.Tasks;

public class ExceptionA : Exception { }
public class ExceptionB : Exception { }

public class Catch : MonoBehaviour
{

void Start() {
    CatchThrowError(new ExceptionA());
    CatchThrowError(new ExceptionB());
}

private void CatchThrowError(Exception error) {
    UniRx.Observable
        .Range(0, 1)
        .Select(x => x.ToString())
        .Do(_ => throw error)
        .Catch((ExceptionA e) => {
            return UniRx.Observable.Return("Catch A");
        })
        .Catch((ExceptionB e) => {
            return UniRx.Observable.Return("Catch B");
        })
        .Subscribe(x => {
            Debug.Log("OnNext : " + x);
        }, e => {
            Debug.Log("OnError : " + e);
        }, () => {
            Debug.Log("OnCompleted");
        });
}
}
