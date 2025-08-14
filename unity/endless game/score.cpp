using UnityEngine;
using TMPro;

public class ScoreManager : MonoBehaviour
{
    public TextMeshProUGUI scoreText;
    private float score;

    void Update()
    {
        score += Time.deltaTime * 5; // Increase score over time
        scoreText.text = "Score: " + Mathf.FloorToInt(score).ToString();
    }
}