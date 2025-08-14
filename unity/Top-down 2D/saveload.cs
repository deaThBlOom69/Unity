using UnityEngine;
using System.IO;

public class SaveLoadManager : MonoBehaviour
{
    public PlayerController player;
    public PlayerInventory inventory;

    [System.Serializable]
    public class SaveData
    {
        public int ammo;
        public float health;
        public InventoryItem[] items;
    }

    public void SaveGame()
    {
        SaveData data = new SaveData();
        data.ammo = player.ammo;
        data.health = 100; // Add your health variable
        data.items = inventory.items.ToArray();

        string json = JsonUtility.ToJson(data, true);
        File.WriteAllText(Application.persistentDataPath + "/save.json", json);
        Debug.Log("Game Saved");
    }

    public void LoadGame()
    {
        string path = Application.persistentDataPath + "/save.json";
        if (File.Exists(path))
        {
            string json = File.ReadAllText(path);
            SaveData data = JsonUtility.FromJson<SaveData>(json);

            player.ammo = data.ammo;
            inventory.items.Clear();
            inventory.items.AddRange(data.items);
            Debug.Log("Game Loaded");
        }
    }
}