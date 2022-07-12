using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float speed;
    private Rigidbody rb;
    private Vector3 movingVelocity;
    private Vector3 movingDirecion;
 
    void Start(){
        rb = GetComponent<Rigidbody>();
    }
 
    void Update() {
        //移動値の処理
        MoveVec();
    }
 
    void FixedUpdate() {
        //移動
        Move();
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
        rb.velocity = new Vector3(movingVelocity.x, rb.velocity.y, movingVelocity.z);
    } 

}
