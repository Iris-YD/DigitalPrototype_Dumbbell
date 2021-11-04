using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

//public int TotalTime = 90;//总时间
//public Text TimeText;//在UI里显示时间
//private int mumite;//分
//private int second;//秒

public class timer1 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //StartCoroutine(startTime());        
    }

	//public IEnumerator startTime()
 //   {
 //       WaitForSeconds waitForSeconds = new WaitForSeconds(1);
 //       while (TotalTime >= 0)
 //       {
 //           yield return waitForSeconds;
 //           TotalTime--;
 //           TimeText.text = "Time:" + TotalTime;

 //           if (TotalTime <= 0)
 //           {                
 //               Debug.Log("Finished");
 //           }
 //           mumite = TotalTime / 60; //输出显示分
 //           second = TotalTime % 60; //输出显示秒
 //           string length = mumite.ToString();
 //           //如果秒大于10的时候，就输出格式为 00：00
 //           if (second >= 10)
 //           {
 //               TimeText.text = "0" + mumite + ":" + second;
 //           }
 //           //如果秒小于10的时候，就输出格式为 00：00
 //           else
 //               TimeText.text = "0" + mumite + ":0" + second;
 //       }
 //   }

}

