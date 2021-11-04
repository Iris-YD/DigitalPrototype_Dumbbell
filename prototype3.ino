#include <Keyboard.h>
#include <Adafruit_CircuitPlayground.h>

//define the XYZ axis for the accelerometer
float X, Y, Z;
int curls = 0;
int degreesX = 0;
int degreesY = 0;
int degreesZ = 0;
int i = 0;
int j = 0;
int downCounter = 0;
int curlCounter = 0;
bool dumbellDown = false;
bool dumbellUp = false;
bool isFinished = false;


void setup() {
  // put your setup code here, to run once:
  
  //initialise the keyboard library
  Keyboard.begin();
  
  CircuitPlayground.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  CircuitPlayground.clearPixels();
//  if user lift the dumbbell to the bottom(when the tilt angle almost reach -90 degree)
  if (X > 8 && !dumbellDown) { 
      dumbellDown = true;
      downCounter++;
      CircuitPlayground.setPixelColor(curls, 0,  255,   0); //the light will turn green
      CircuitPlayground.playTone(400,500); //there will be a sound when user successfully lift down the dumbbell to vertical
    } 
    
//    if user lift up the dumbbell to horizontal)
    if (X<1 && dumbellDown) { 
      dumbellDown = false;
      downCounter++;
      CircuitPlayground.setPixelColor(curls, 255, 0,   0); // the light will turn red
    }
    if(downCounter == 2) {
      Serial.println("completed down");
      downCounter = 0;
      i++;
//      send the Z character as a keyboard press.
//      In unity, pressing 'Z' in keyboard will 
//      set the number of lifting times on the screen.
      Keyboard.press('Z');
      Keyboard.releaseAll();
      delay(100);
    }

  
  if (X<-8 && !dumbellUp) { //if user lift the dumbbell to the top(when the tilt angle almost reach 90 degree)
      dumbellUp = true;
      curlCounter++;
      CircuitPlayground.setPixelColor(curls, 0,  255,   0); //the light will turn green
      CircuitPlayground.playTone(400,500); //there will be a sound when user successfully lift up the dumbbell
    } if (X>-1 && dumbellUp) { //if user lift down the dumbbell to horizontal)
      dumbellUp = false;
      curlCounter++;
      CircuitPlayground.setPixelColor(curls, 255, 0,   0); // the light will turn red
    }
    if(curlCounter == 2) {
      Serial.println("completed curl");
      curlCounter = 0;
      j++;
      
//      send the X character as a keyboard press.
//      In unity, pressing 'X' in keyboard will 
//      reduce the number of lifting times on the screen.
      Keyboard.press('X');
      Keyboard.releaseAll();
      delay(100);
    }

    if (j == i && i!=0 && !isFinished) {
      Serial.println("FINISHED!");
      CircuitPlayground.setPixelColor(curls, 255, 255,   0); //the light will turn yellow which presents that the whole process has finishedXXX
      isFinished = true;
      
//      send the P character as a keyboard press.
//      In unity, pressing 'P' in keyboard will stop the alarm audioclip 
//      and play the congratulation audioclip.
      Keyboard.write('P');
      Keyboard.releaseAll();
    } 
    
    
    Serial.print("X: ");
    Serial.print(X);
    Serial.print("  Y: ");
    Serial.print(Y);
    Serial.print("  Z: ");
    Serial.println(Z);
    Serial.print("  downCounter：");
    Serial.print(downCounter);
    Serial.print("  curlCounter：");
    Serial.print(curlCounter);
    Serial.print("  Setting times:  ");
    Serial.print(i);
    Serial.print("  Finished lift:  ");
    Serial.println(j);
  
    delay(50);


}
