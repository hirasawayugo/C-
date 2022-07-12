using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Agent : MonoBehaviour
{
    public GameObject target;          //目的地となるオブジェクトのトランスフォーム格納用
    private NavMeshAgent agent;     //エージェントとなるオブジェクトのNavMeshAgent格納用 
 
	// Use this for initialization
	void Update () {
        //エージェントのNaveMeshAgentを取得する
        agent = GetComponent<NavMeshAgent>();
        Transform tTran = target.GetComponent<Transform>();
        Transform mTran = this.GetComponent<Transform>();
        //目的地となる座標を設定する
        agent.SetDestination(tTran.position);
    
	}

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "target")
        {
            agent.isStopped = true;
        }
    }

    
}
