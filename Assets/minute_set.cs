using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class minute_set : MonoBehaviour
{
    string number_m = null;
    InputField i;
    // Start is called before the first frame update
    void Start()
    {
        i = GetComponent<InputField>();
    }

    // Update is called once per frame
    void Update()
    {
        if (i.text != number_m)
        {
            number_m = i.text;
            Debug.Log(i.text);

        }

            if (Input.GetKeyDown(KeyCode.A))
            {
                
                if (int.Parse(i.text) < 45)
                {
                    i.text = (int.Parse(i.text) + 15).ToString();
                } else
                {
                    i.text = 0.ToString();
                }
            }
            if (Input.GetKeyDown(KeyCode.S))
            {
                if (int.Parse(i.text) > 0)
                {
                    i.text = (int.Parse(i.text) - 15).ToString();
                } else
                {
                    i.text = 45.ToString();
                }
            }
        
    }
}
