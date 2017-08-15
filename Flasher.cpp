/*
 * Flasher.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: b010515
 */

#include "Flasher.h"
#include "Arduino.h"


Flasher::Flasher(int pin, long onTime, long offTime)
{
	ledPin = pin;
	pinMode(ledPin, OUTPUT);

	OnTime = onTime;
	OffTime = offTime;

	ledState = LOW;
	previousMillis = 0;
}

Flasher::~Flasher() {

}


void Flasher::Update(unsigned long currentMillis)
{
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
    	ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);	  // Update the actual LED
    }
}
