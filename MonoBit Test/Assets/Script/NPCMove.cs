using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
 
public class NPCMove : MonoBehaviour
{
    private NavMeshAgent agent;
    private Vector3 nextPos;

    void Start()
    {
        nextPos = GetComponent<Transform>().position;
    }
 
    void Update () 
    {
        agent = GetComponent<NavMeshAgent>();
        Vector3 nowPos = GetComponent<Transform>().position;
        float diff = Vector3.Distance(nowPos, nextPos);
        if( diff < 2.0f)
        {
            nextPos = new Vector3(Random.Range(-10f, 10f), 0, Random.Range(-10f, 10f));
            agent.SetDestination(nextPos);
        }
    }
}

