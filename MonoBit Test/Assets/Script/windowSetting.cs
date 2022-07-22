using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class windowSetting
{
    [RuntimeInitializeOnLoadMethod]
    static void OnRuntimeMethodLoad() {
        // スクリーンサイズの指定
        Screen.SetResolution(1024, 880, false);
    }
}
