/*
 * Sweeper.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: b010515
 */

#include "Sweeper.h"
#include "Arduino.h"

Sweeper::Sweeper(int interval) {
	updateInterval = interval;
	increment = 1;
	pos = lastUpdate = 0;

}

Sweeper::~Sweeper() {

}

void Sweeper::Attach(int pin)
{
	servo.attach(pin);
}

void Sweeper::Detach()
{
	servo.detach();
}

void Sweeper::Update(unsigned long currentMillis)
{
	if((currentMillis - lastUpdate) > updateInterval)	// time to update
	{
		lastUpdate = millis();
		pos += increment;
		servo.write(pos);
		if ((pos >= 180) || (pos <= 0)) // end of sweep
		{
			// reverse direction
			increment = -increment;
		}
	}
}

bool Sweeper::Reset()
{
	pos = 0;
	servo.write(pos);
	increment = abs(increment);
}



