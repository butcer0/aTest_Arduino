// Do not remove the include below
#include "aTest.h"

Flasher led1(FLASHER_DATA1[0], FLASHER_DATA1[1], FLASHER_DATA1[2]);
Flasher led2(FLASHER_DATA2[0], FLASHER_DATA2[1], FLASHER_DATA2[2]);
Flasher led3(FLASHER_DATA3[0], FLASHER_DATA3[1], FLASHER_DATA3[2]);

Sweeper sweeper1(SWEEPER_INTERVAL1);
Sweeper sweeper2(SWEEPER_INTERVAL2);


void setup()
{
	sweeper1.Attach(9);
	sweeper2.Attach(10);

	  // Timer0 is already used for millis() - we'll just interrupt somewhere
	  // in the middle and call the "Compare A" function below
	  OCR0A = 0xAF;
	  TIMSK0 |= _BV(OCIE0A);

	  // external interrupt
	  pinMode(2, INPUT_PULLUP);
	  attachInterrupt(0, Reset, FALLING);
}

// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
SIGNAL(TIMER0_COMPA_vect)
{
	// Extra Comment

  unsigned long currentMillis = millis();
  sweeper1.Update(currentMillis);

  if(digitalRead(2) == HIGH)
  {
     sweeper2.Update(currentMillis);
     led1.Update(currentMillis);
  }

  led2.Update(currentMillis);
  led3.Update(currentMillis);
}


void loop()
{

}

void Reset()
{
	Serial.println("Sweeper 1 Reset: "+ sweeper1.Reset());
	Serial.println("Sweeper 2 Reset: "+ sweeper2.Reset());
}


