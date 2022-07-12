using System.Collections;
using System.Collections.Generic;
using UnityEngine;
 
public class PlayerMove : MonoBehaviour
{
    public float speed;
    public float audioTime;
    private AudioSource audio;
    private Rigidbody rb;
    private Vector3 movingVelocity;
    private Vector3 movingDirecion;
    private Vector3 latestPos;
 
    void Start(){
        rb = GetComponent<Rigidbody>();
        audio = GetComponent<AudioSource>();
    }
 
    void Update() {
        //移動値の処理
        MoveVec();
    }
 
    void FixedUpdate() {
        //移動
        Move();
        //進行方向回転
        Rotate();
    }
    void MoveVec()
    {
        float x = Input.GetAxisRaw("Horizontal");
        float z = Input.GetAxisRaw("Vertical");
        movingDirecion = new Vector3(x, 0, z);
        movingDirecion.Normalize();
        movingVelocity = movingDirecion * speed;
    }
    void Move()
    {
        rb.velocity = rb.velocity + new Vector3(movingVelocity.x, 0, movingVelocity.z);
    }
    void Rotate()
    {
        Vector3 angleDiff = new Vector3(transform.position.x, 0, transform.position.z) - new Vector3(latestPos.x, 0, latestPos.z);
        latestPos = transform.position;
        if (Mathf.Abs(angleDiff.x) > 0.001f || Mathf.Abs(angleDiff.z) > 0.001f)
        {
            if (movingDirecion == new Vector3(0, 0, 0)) return;
            Quaternion rot = Quaternion.LookRotation(angleDiff);
            rot = Quaternion.Slerp(rb.transform.rotation, rot, 0.2f);
            this.transform.rotation = rot;
        }
    }
}

