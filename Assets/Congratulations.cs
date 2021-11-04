using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Congratulations : MonoBehaviour
{
    AudioSource Text_lift;
    // Start is called before the first frame update
    void Start()
    {
        Text_lift = transform.GetComponent<AudioSource>();//give the value to the asset
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.O)) //Detect if O is pressed

        {
            Text_lift.Stop();//when press 'O' the sound stop

        }
        if (Input.GetKeyDown(KeyCode.P)) //Detect if P is pressed

        {
            Text_lift.Play();//when press 'P' the sound continue to play

        }

    }
}
