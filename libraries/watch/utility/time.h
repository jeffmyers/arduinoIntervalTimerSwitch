/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef Time_h
#define Time_h

#include "Arduino.h"




class TimeMode
{
  public:
	TimeMode();
    bool edit;
	/* int getCurrentMode();
    void changeMode();*/
   virtual String sayHello();
   void addSecond();
   String getCurrentValue();
   void changeEditAttribute();
   void addValue();
   void subtractValue();
   long getTotalSeconds();


  private:
   int Hours;
	int Minutes;
	int Seconds;
    long totalSeconds;
    int hmsActive;
	bool blinkOn;

		long TMRinterval;           // interval at which to blink (milliseconds)
    long TMRpreviousMillis; // will store last time LED was updated
	unsigned long TMRcurrentMillis;

	String strHours;
	String strMinutes;
	String strSeconds;



};

#endif