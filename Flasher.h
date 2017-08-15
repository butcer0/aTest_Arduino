/*
 * Flasher.h
 *
 *  Created on: Aug 15, 2017
 *      Author: b010515
 */

#ifndef FLASHER_H_
#define FLASHER_H_

class Flasher {

	// Class Member Variables
	int ledPin;	//ledState used to set the LED
	long OnTime;	// milliseconds of on-time
	long OffTime;	// milliseconds of off-time

	// State properties
	int ledState;
	unsigned long previousMillis;	//will store last time LED was updated

public:
	Flasher(int pin, long on, long off);
	virtual ~Flasher();
	void Update(unsigned long currentMillis);

};

#endif /* FLASHER_H_ */
