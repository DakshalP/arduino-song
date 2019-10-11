/*

An Arduino program for playing songs on a piezo buzzer at the press of a button; buzzer must be connected to 10.

 */

//Setup: Buzzer has to be on pin 10
 
#define msPerTick 1
#include "pitches.h"

#include "doStarWars.h"
#include "doRatherBe.h"
#include "doPerformance.h"
#include "doFurElise.h"

//***BUZZER PIN IS ALWAYS 10*** Since it was coded into all the music files

// This constant won't change:
const int  buttonPin = 4;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
    pinMode(10, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button
      // went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(10);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;


   /* 
    *  Turns on the LED every four button pushes by 
    *  checking the modulo of the button push counter.
   */
   
  /**if (buttonPushCounter % 2 == 0) {
    digitalWrite(ledPin, HIGH);
    doPerformance();
  } else {
    digitalWrite(ledPin, LOW);
    noTone(10);
  }**/
  if (buttonPushCounter == 1) {
    digitalWrite(ledPin, HIGH);
    ++buttonPushCounter;
    doPerformance();
  }

  if (buttonPushCounter == 3) {
    digitalWrite(ledPin, LOW);
    ++buttonPushCounter;
    doStarWars();
  }

  if (buttonPushCounter == 5) {
    digitalWrite(ledPin, HIGH);
    ++buttonPushCounter;
    doRatherBe();
  }

  if (buttonPushCounter == 7) {
    digitalWrite(ledPin, LOW);
    ++buttonPushCounter;
    doFurElise();
  }
  

}
