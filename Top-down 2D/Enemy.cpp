using UnityEngine;
using UnityEngine.AI;

public class EnemyAI : MonoBehaviour
{
    public enum AIState { Patrol, Chase, Attack }
    public AIState currentState;

    public Transform[] patrolPoints;
    private int patrolIndex = 0;

    public Transform player;
    public float chaseRange = 5f;
    public float attackRange = 1.5f;

    private NavMeshAgent agent;

    void Start()
    {
        agent = GetComponent<NavMeshAgent>();
        currentState = AIState.Patrol;
    }

    void Update()
    {
        float distance = Vector3.Distance(player.position, transform.position);

        switch (currentState)
        {
            case AIState.Patrol:
                Patrol();
                if (distance < chaseRange) currentState = AIState.Chase;
                break;

            case AIState.Chase:
                agent.SetDestination(player.position);
                if (distance < attackRange) currentState = AIState.Attack;
                if (distance > chaseRange) currentState = AIState.Patrol;
                break;

            case AIState.Attack:
                Debug.Log("Enemy attacking!");
                if (distance > attackRange) currentState = AIState.Chase;
                break;
        }
    }

    void Patrol()
    {
        agent.SetDestination(patrolPoints[patrolIndex].position);
        if (Vector3.Distance(transform.position, patrolPoints[patrolIndex].position) < 0.5f)
        {
            patrolIndex = (patrolIndex + 1) % patrolPoints.Length;
        }
    }
}