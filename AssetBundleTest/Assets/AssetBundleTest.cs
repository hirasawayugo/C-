using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AssetBundleTest : MonoBehaviour
{
    void Start () {
        StartCoroutine(AssetLoad()); 
	}

    IEnumerator AssetLoad()
    {
        string path = Application.streamingAssetsPath + "/Cube";
        AssetBundleCreateRequest request = AssetBundle.LoadFromFileAsync(path);
        while (!request.isDone)
        {
            yield return null;
        }
        AssetBundle assetBundle = request.assetBundle;
        AssetBundleRequest cube = assetBundle.LoadAssetAsync<GameObject>("cube");
        GameObject obj = (GameObject)Instantiate( cube.asset );
    }
}
