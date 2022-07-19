using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon.Realtime;

public class MatchMaker : MonoBehaviourPunCallbacks
{
    public GameObject PhotonObject;

    void Start()
    {
        PhotonNetwork.ConnectUsingSettings();
    }

    public override void OnConnectedToMaster()
    {
        PhotonNetwork.JoinRandomRoom();
    }

    public override void OnJoinRandomFailed(short returnCode, string message)
    {
        RoomOptions roomOptions = new RoomOptions();
        roomOptions.MaxPlayers = 8;
        PhotonNetwork.CreateRoom(null, roomOptions);
    }

    public override void OnJoinedRoom()
    {
        PhotonNetwork.Instantiate(
            PhotonObject.name,
            new Vector3(0f, 1f, 0f),
            Quaternion.identity,
            0
        );
        GameObject mainCamera = GameObject.FindWithTag("MainCamera");
        mainCamera.GetComponent<UnityChan.ThirdPersonCamera>().enabled = true;
    }
}
