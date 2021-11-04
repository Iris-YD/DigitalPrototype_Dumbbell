
using UnityEngine;

public class StopAlarm : MonoBehaviour

{
    AudioSource Panel;//Recieve Asset

    void Start()

    {
        Panel = transform.GetComponent<AudioSource>();//give the value to the asset

    }

    void Update()

    {
        if (Input.GetKeyDown(KeyCode.P)) //Detect if P is pressed

        {
            Panel.Stop();//when press 'P' the sound stop

        }
        if (Input.GetKeyDown(KeyCode.Return)) //Detect if return is pressed

        {
            Panel.Play();//when press 'Return' the sound continue to play

        }

    }
}

 