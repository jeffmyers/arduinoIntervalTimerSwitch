/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef TimerAlarm_h
#define TimerAlarm_h

#include "Arduino.h"
#include "utility/timer.h"
#include "utility/alarm.h"




class TimerAlarmMode
{
  public:
	TimerAlarmMode();
	void checkAlarm(long totalSeconds);
	void changeEditValue();
	void addTimerAlarm(TimerMode timer, AlarmMode alarm);
	int getPosition();
	void changePosition(int i);
	void removeTimerAlarm(int position);
	bool getEditValue();
    virtual String sayHello();
	int alarmI;
	


  private:
	  bool edit;
	  int numAlarms;
	  
	  	TimerMode blanktimer;
	    AlarmMode blankalarm;
	  AlarmMode alarms[4];//rather than making this store a whole class lets just store the total seconds then make it if they match...
      TimerMode timers[4];//rather than making this store a whole class lets just store the total seconds then make it if they match...
	  int activeTimerAlarm[4];//rather than making this store a whole class lets just store the total seconds then make it if they match...
	  bool blinkOn;
	long ALinterval;           // interval at which to blink (milliseconds)
    long ALpreviousMillis; // will store last time LED was updated
	unsigned long ALcurrentMillis;
	int i;//iterate throuh each alarm and see if it matches the current milliseconds...



};

#endif