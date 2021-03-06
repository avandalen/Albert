/* 
Version 17-12-2015 analogReadfast, heartbeat
Version 29-4-2016 #if defined(__arm__)
Version 8-2-2017 Added analogReadFast code for SAMD21
Version 4-9-2017 deleted heartbeat
Version 5-3-2018 deleted adcMean and analogReadFast
*/

#include <Arduino.h>
#include "Albert.h"

void openDrain(byte pin, bool value)
{ if(value) pinMode(pin, INPUT);
  else pinMode(pin, OUTPUT); 
  digitalWrite(pin, LOW);  
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

void blinkLed(byte pin, int n, bool onLevel)
{ pinMode(pin, OUTPUT); 
  for(byte i=0; i<n; i++)
  { digitalWrite(pin, onLevel);       
    delay(300);                 
    digitalWrite(pin, !onLevel);   
    delay(300);
  }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

void maxLoops(const unsigned long loops)
{ static unsigned long i=0;
  if(++i > loops) while(1);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

bool SimpleSoftPWM::pwm(byte value) // 0 ... 255, only for LEDs
{ unsigned long now_us = micros();
  if((now_us - start_us) >= periodTime_us) start_us = now_us;
  return((now_us - start_us) < value * 78); // 19890/255=78
}


