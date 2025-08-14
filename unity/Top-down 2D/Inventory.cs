using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class InventoryItem
{
    public string itemName;
    public int quantity;
}

public class PlayerInventory : MonoBehaviour
{
    public List<InventoryItem> items = new List<InventoryItem>();

    public void AddItem(string name, int qty)
    {
        items.Add(new InventoryItem { itemName = name, quantity = qty });
    }

    public void RemoveItem(string name)
    {
        items.RemoveAll(i => i.itemName == name);
    }
}