// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _aTest_H_
#define _aTest_H_
#include "Arduino.h"
//add your includes for the project aTest here
#include "Flasher.h"
#include "Sweeper.h"

extern const int FLASHER_DATA1[3] = {11, 123, 400};
extern const int FLASHER_DATA2[3] = {12, 350, 350};
extern const int FLASHER_DATA3[3] = {13, 200, 222};

const int SWEEPER_INTERVAL1 = 25;
const int SWEEPER_INTERVAL2 = 35;

void Reset();

//Do not add code below this line
#endif /* _aTest_H_ */
