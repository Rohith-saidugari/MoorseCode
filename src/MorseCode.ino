/*
 * Project MorseCode
 * Description: This Project listens for the messsages and plays a sound based on the input message
 * Author: Rohit Saidugari
 * Date: 09/25/2019
 */
#include "MorseHelper.h"
#include <string>

using namespace std;
//Set connection pins 
int speaker_PIN    = D0;
int dit_LED_PIN    = D1;
int dah_LED_PIN    = D2;
int SOS_Button_PIN = D3;

int playMorseCode(String command);
// setup() runs once, when the device is first turned on.
void setup() {
  initializeCodes();
  pinMode(speaker_PIN,OUTPUT);
  pinMode(dit_LED_PIN,OUTPUT);
  pinMode(dah_LED_PIN,OUTPUT);
  //Switch INPUT_PULLUP
  pinMode(SOS_Button_PIN,INPUT_PULLUP);
  Serial.begin(9600);
  Particle.function("PlayMorseCode",playMorseCode);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  if(digitalRead(SOS_Button_PIN) == LOW ){
    playMorseCode("SOS");
  }
}
/*
 * This  method called evertime when playMorsecode is called 
 *  Aslo publishes messages to cloud
 *  I did this to display message on OLED Screen
 */

int playMorseCode(String command){
  Particle.publish("Message",command,PUBLIC);
  string text= command.c_str();
  resolveMorseCode(text);
  return 1;
}