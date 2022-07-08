using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test : MonoBehaviour
{
    [SerializeField] GameObject effect;
    [SerializeField] float deleteTime;
    void Update()
    {
        if(Input.GetMouseButtonDown(0))
        {
            //マウスカーソルの位置を取得。
            Vector3 mousePosition = Input.mousePosition;
            mousePosition.z = 3f;
             GameObject clone = Instantiate(effect, Camera.main.ScreenToWorldPoint(mousePosition),
                 Quaternion.identity);
            Destroy(clone, deleteTime);
        }
    }
}
