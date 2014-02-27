/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"




class AlarmMode
{
  public:
	AlarmMode();
     bool edit;
	bool started;

	/* int getCurrentMode();
    void changeMode();*/
   virtual String sayHello();
   String getCurrentValue();
   void addValue();
   void subtractValue();
   void changeEditAttribute();
   void addSecond();
   long getTotalSeconds();


  private:
   int Hours;
	int Minutes;
	int Seconds;
    long totalSeconds;
    int hmsActive;
    bool blinkOn;
	long ALinterval;           // interval at which to blink (milliseconds)
    long ALpreviousMillis; // will store last time LED was updated
	unsigned long ALcurrentMillis;
		String strHours;
	String strMinutes;
	String strSeconds;


};

#endif