using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using MonobitEngine;
using System.Text;
using System;
using TMPro;

public class ChatSystem : MonobitEngine.MonoBehaviour
{
    [SerializeField]
    private TMP_InputField chatInput;
    [SerializeField]
    private Scrollbar scrollbar;
    [SerializeField]
    private TextMeshProUGUI logText; 
    private StringBuilder logTextSB;
    private List<string> chatLog = new List<string>();

    void Start()
    {
        logTextSB = new StringBuilder();
    }

    private void OnOtherPlayerConnected(MonobitEngine.MonobitPlayer newPlayer)
    {
        JoinedMassage(newPlayer.name);
    }

    private void OnOtherPlayerDisconnected(MonobitEngine.MonobitPlayer otherPlayer)
    {
        LeftMassage(otherPlayer.name);
    }

    public void OnChatInput()
    {
        if(!MonobitNetwork.isConnect) return;
        string text = chatInput.text;
        if(text == "") return;
        monobitView.RPC("RecvChat", MonobitTargets.All, MonobitNetwork.playerName, text);
        chatInput.text = "";
        chatInput.ActivateInputField();
    }

    void ViewLogText()
    {
        logTextSB.Clear();
        foreach (var log in chatLog) {
			logTextSB.Insert(0, log + "\n");
		}
		logText.text = logTextSB.ToString().TrimEnd();
        scrollbar.value = 1f;
    }

    [MunRPC]
    void RecvChat(string senderName, string senderWord)
    {
        chatLog.Add(senderName + " : " + senderWord);
        LogSort();
        ViewLogText();
    }

    void JoinedMassage(string senderName)
    {
        chatLog.Add(senderName + " Joined room");
        LogSort();
        ViewLogText();
    }

    void LeftMassage(string senderName)
    {
        chatLog.Add(senderName + " Left room");
        LogSort();
        ViewLogText();
    }

    void LogSort()
    {
        if( chatLog.Count > 20 )
        chatLog.RemoveAt(0);
    }
}
