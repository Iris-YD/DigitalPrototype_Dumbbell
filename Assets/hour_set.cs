using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class hour_set : MonoBehaviour
{
    private string number_h = null;
    InputField i;
    // Start is called before the first frame update
    void Start()
    {
        i = GetComponent<InputField>();
    }

    // Update is called once per frame
    void Update()
    {
        if (i.text != number_h)
        {
            number_h = i.text;
            Debug.Log(i.text);

        }

        if (Input.GetKeyDown(KeyCode.Q))
        {
            if (int.Parse(i.text) < 23)
            {
                i.text = (int.Parse(i.text) + 1).ToString();
            }
            else
            {
                i.text = 0.ToString();
            }
            
        }

        if (Input.GetKeyDown(KeyCode.W))
        {
            if (int.Parse(i.text) > 0)
            {
                i.text = (int.Parse(i.text) - 1).ToString();
            }
            else
            {
                i.text = 23.ToString();
            }
        }
    }
}
