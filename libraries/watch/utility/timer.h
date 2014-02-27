/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef Timer_h
#define Timer_h

#include "Arduino.h"




class TimerMode
{
  public:
	//TimerMode(int switchPin);
	TimerMode();
    bool edit;
	bool started;

	/* int getCurrentMode();
    void changeMode();*/
   virtual String sayHello();
   String getCurrentValue();
   void changeEditAttribute();
   void addValue();
   void subtractValue();
   void subtractSecond();
   long getTotalSeconds();
   long startSeconds;
   void start();
   void stop();




  private:
   int Hours;
	int Minutes;
	int Seconds;
    long totalSeconds;
    
	int hmsActive;
	bool blinkOn;
	int _switchPin;

	long TMRinterval;           // interval at which to blink (milliseconds)
    long TMRpreviousMillis; // will store last time LED was updated
	unsigned long TMRcurrentMillis;
	String strHours;
	String strMinutes;
	String strSeconds;

	


};

#endif