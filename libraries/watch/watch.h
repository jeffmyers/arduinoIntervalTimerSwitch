/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef Watch_h
#define Watch_h

#include "Arduino.h"
#include "utility/time.h"
#include "utility/interval.h"
#include "utility/data.h"
#include "utility/timer.h"
#include "utility/alarm.h"
#include "utility/timer_alarmSeries.h"


class Watch
{
	
  public:
	
	//modes mode[4];
    int getCurrentMode();
    void changeMode();
	void addSecond();
	void toggleEdit();
	void startLap();
	void stop();


	TimeMode time;
	IntervalMode interval;
	DataMode data;
	TimerMode timer;
	AlarmMode alarm;
	TimerAlarmMode timerAlarm;

	
	Watch(int i, int switchPin);
  private:
    int _modeIndex;
	int _switchPin;
	long _previousMillis;
	
	
};

#endif