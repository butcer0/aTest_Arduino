/*
 * Sweeper.h
 *
 *  Created on: Aug 15, 2017
 *      Author: b010515
 */

#include "Servo.h"

#ifndef SWEEPER_H_
#define SWEEPER_H_

class Sweeper {
	Servo servo;	// the servo
	int pos;		// current servo position
	int increment;	// incrememnt to move for each interval
	int updateInterval; // interval between updates
	unsigned long lastUpdate;	// last update of position


public:
	Sweeper(int interval);
	virtual ~Sweeper();
	void Attach(int pin);
	void Detach();
	void Update(unsigned long currentMillis);
	bool Reset();
};

#endif /* SWEEPER_H_ */
