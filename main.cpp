/**
 *  @file
 */

#include "mbed.h"
#include "arm_book_lib.h"
#include <cstdio>


#define DEACTIVATE_ALARM_BUS_IN_CODE 0b1000

/**
 *  @Brief Main program.
 */
int main()
{

  DigitalIn gasDetector(D2);
  gasDetector.mode(PullDown);
  
  DigitalIn overTempDetector(D3) ;
  overTempDetector.mode(PullDown);

  BusIn userButtons(D4, D5, D6, D7);
  userButtons.mode(PullDown);
    
  DigitalOut alarmLed(LED1) ;
    
  alarmLed = OFF ;

  bool alarmState = OFF;

  while (true) {

    if ( gasDetector || overTempDetector ) {
      alarmState = ON;
    }

    alarmLed = alarmState;

    if (userButtons.read() == DEACTIVATE_ALARM_BUS_IN_CODE) {
      alarmState = OFF ;
    }

    printf("Gas detector = %d | Overtemperature detector = %d | User buttons code = %X | Alarm led = %d\n", gasDetector.read(), overTempDetector.read(), userButtons.read(), alarmLed.read()) ;
  }
}
