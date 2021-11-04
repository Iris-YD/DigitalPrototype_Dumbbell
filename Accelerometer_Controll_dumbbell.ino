#include <Adafruit_CircuitPlayground.h>
#include "Keyboard.h"

// define the number of the pushbutton pins
const int button1Pin = 4; //lilypad left button    
const int button2Pin = 19; //lilypad right button     
float X, Y, Z;
int curls = 0;
int degreesX = 0;
int degreesY = 0;
int degreesZ = 0;
int i=0;
int curlCounter = 0;
bool dumbellUp = false;

void setup() {
  //initialise the keyboard library
  Keyboard.begin();
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  
  //initialise the serial library
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  CircuitPlayground.clearPixels();
    
    if (X<-8 && !dumbellUp) { //if user lift the dumbbell to the top(when the tilt angle almost reach 90 degree)
      dumbellUp = true;
      curlCounter++;
      CircuitPlayground.setPixelColor(curls, 0,  255,   0); //the light will turn green
      CircuitPlayground.playTone(400,500); //there will be a sound when user successfully lift up the dumbbell
    } if (X>-1 && dumbellUp) { //if user lift down the dumbbell)
      dumbellUp = false;
      curlCounter++;
      CircuitPlayground.setPixelColor(curls, 255, 0,   0); // the light will turn red
    }
    if(curlCounter == 2) {
      Serial.println("completed curl");
      curlCounter = 0;
      i++;
    }
    if(i == 5) { //set 10 times to stop the alarm
      Serial.println("FINISHED!");
      CircuitPlayground.setPixelColor(curls, 255, 255,   0); //the light will turn yellow which presents that the whole process has finished
      Keyboard.print('R'); //send the R character as a keyboard press.In unity, pressing 'R' in keyboard will stop the sound.
    }

  //read the button1 state and check if it is pressed
  if (digitalRead(button1Pin) == HIGH) {
    //send the R character as a keyboard press.
    Keyboard.print('R');
  }
 
  //read the button2 state and check if it is pressed
  if (digitalRead(button2Pin) == HIGH) {
    //send the U character as a keyboard press.
    Keyboard.write('U');
  }

  //wait for 0.1 seconds between keypresses.
  //delay(10);
  

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);

  delay(100);

}
