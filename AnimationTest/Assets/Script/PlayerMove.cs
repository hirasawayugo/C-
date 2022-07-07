using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public float speed;
    public float jumpPower;
    private Animator anim;
    private Rigidbody rb;
    private Vector3 movingVelocity;
    private Vector3 movingDirecion;
    private Vector3 latestPos;
    private bool jumping = false;

    void Start(){
        rb = GetComponent<Rigidbody>();
        anim = GetComponent<Animator>();
    }

    void Update() {
        //移動値の処理
        MoveVec();
        //飛ぶ入力
        Jump();
        //アニメーション管理
        Animation();
    }

    void FixedUpdate() {
        //移動
        Move();
        //進行方向回転
        Rotate();
    }

    void OnCollisionEnter(Collision other)
    {
        if(jumping == true)
        {
            if(other.gameObject.CompareTag("Ground"))
            {
                jumping = false;
            } 
        }
    }

    void Animation()
    {
        if(movingVelocity == new Vector3(0, 0, 0))
        {
            anim.SetBool("walking", false);
        }
        else
        {
            anim.SetBool("walking", true);
        }
        anim.SetBool("jumping", jumping);
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
    void Jump(){
        if(jumping == true) return;
        if (Input.GetKeyDown(KeyCode.Space)) 
        {
            rb.AddForce(transform.up * jumpPower, ForceMode.Impulse);
            jumping = true;
	    }
    }
}
