using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float jumpForce = 7f;
    private Rigidbody2D rb;
    private Animator animator;
    private bool isGrounded = true;
    public ParticleSystem jumpEffect;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) && isGrounded)
        {
            rb.velocity = new Vector2(rb.velocity.x, jumpForce);
            isGrounded = false;
            animator.SetTrigger("Jump");
            jumpEffect.Play();
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.collider.CompareTag("Ground"))
        {
            isGrounded = true;
            animator.SetTrigger("Run");
        }
        else if (collision.collider.CompareTag("Obstacle"))
        {
            Debug.Log("Game Over");
            Time.timeScale = 0;
        }
    }
}