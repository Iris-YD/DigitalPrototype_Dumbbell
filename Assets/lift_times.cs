using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class lift_times : MonoBehaviour
{
    string number = "";

    InputField i;
    // Start is called before the first frame update
    void Start()
    {
        i = GetComponent<InputField>();
    }

    // Update is called once per frame
    void Update()
    {
        if (i.text != number)
        {
            number = i.text;
            Debug.Log(i.text);

        }

        if (Input.GetKeyDown(KeyCode.Z))
        {
            i.text = (int.Parse(i.text) + 1).ToString();
        }

        if (Input.GetKeyDown(KeyCode.X))
        {
            i.text = (int.Parse(i.text) - 1).ToString();
        }
    }
}
