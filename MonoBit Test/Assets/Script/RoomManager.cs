using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using MonobitEngine;
using System.Text;
using System;
using TMPro;
using Cysharp.Threading.Tasks; 

[RequireComponent(typeof(MonobitView))]
public class RoomManager : MonobitEngine.MonoBehaviour
{
    [SerializeField]
    GameObject playerPrefab = null;
    [SerializeField]
    private GameObject enterRoomPanel = null;
    [SerializeField]
    private GameObject chatUI = null;
    [SerializeField]
    private TMP_InputField playerNameInput = null;
    [SerializeField]
    private TMP_InputField roomNameInput = null;
    [SerializeField]
    private TextMeshProUGUI playersText; 
    private GameObject player = null;
    private Camera camera = null;

    public void OnEntry()
    {
        MonobitNetwork.playerName = playerNameInput.text;
        string roomName = roomNameInput.text;
        MonobitNetwork.autoJoinLobby = true;
        MonobitNetwork.autoSyncScene = true;
        MonobitNetwork.ConnectServer("v0.1");
        JoinRoom(roomName).Forget();
    }

    private void OnOtherPlayerConnected(MonobitEngine.MonobitPlayer newPlayer)
    {
        WritePlayers();
    }

    private void OnOtherPlayerDisconnected(MonobitEngine.MonobitPlayer otherPlayer)
    {
        WritePlayers();
    }

    private async UniTask JoinRoom(string roomName)
    {
        await UniTask.WaitUntil(() => MonobitNetwork.isConnect == true,cancellationToken: this.GetCancellationTokenOnDestroy());
        if(!MonobitNetwork.inRoom)
        {
            RoomSettings roomSettings = new RoomSettings();
            MonobitNetwork.JoinOrCreateRoom(roomName, roomSettings, null);
        }
    }

    private void OnJoinedRoom()
    {
       CreatePlayer();
       WritePlayers();
        enterRoomPanel.SetActive(false);
        chatUI.SetActive(true);
    }

    void CreatePlayer()
    {
        if (playerPrefab == null) return;
        player = MonobitNetwork.Instantiate(playerPrefab.name, Vector3.zero, Quaternion.identity, 0) as GameObject;
        if (player != null)
        {
            Camera mainCamera = GameObject.FindObjectOfType<Camera>();
            mainCamera.GetComponent<Camera>().enabled = false;

            camera = player.GetComponentInChildren<Camera>();
            if (camera == null)
            {
                GameObject camObj = new GameObject();
                camObj.name = "Camera";
                camera = camObj.AddComponent<Camera>();
                camera.transform.parent = player.transform;
            }
            camera.transform.position = new Vector3(1, 1, -3);
            camera.transform.rotation = Quaternion.identity;
        }
    }

    public void OnLeftRoom()
    {
        MonobitNetwork.LeaveRoom();
        enterRoomPanel.SetActive(true);
        chatUI.SetActive(false);
    }
    
    private void WritePlayers()
    {
        playersText.text = "";
        foreach(MonobitPlayer player in MonobitNetwork.playerList)
        {
            playersText.text += player.name + " \n";
        }
    }
}
