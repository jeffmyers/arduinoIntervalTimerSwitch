/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#include "Arduino.h"
#include "watch.h"
#include "utility/time.h"


Watch::Watch(int i, int switchPin){
	_modeIndex=i;
	_switchPin=switchPin;
	 _previousMillis = 0;

	//TimerMode timer2(13);
	//timer=timer2;

}
void Watch::addSecond(){
	time.addSecond();
	 unsigned long _currentMillis = millis();
	 if ((interval.getTotalSeconds())>0){ //don't check the intervals if there isn't any set
		 	  // don't start the interval timer unless it's done counting down from the previous count down.
			  if (timer.started==false){
				if(_currentMillis - _previousMillis > (interval.getTotalSeconds()*1000)) { 
				  timer.start();
			     }
				}
			  else{//if the timer has started keep _previousMillis and _currentMillis the same so the interval doesn't start counting until the timer stops.
			   _previousMillis = _currentMillis; 
			  }
		  
	 }//finished checking that an interval exists




	
	timerAlarm.checkAlarm(time.getTotalSeconds());
	if (timer.started==true){
	timer.subtractSecond();
	if (timer.getTotalSeconds()==0){
	timer.stop();
	}
	}else{
	}
}
void Watch::stop(){
	switch(_modeIndex){
	case 0: 
		if (time.edit==true){
		time.subtractValue();
		}
		break;
	case 1: 
		if (interval.edit==true){
		interval.subtractValue();
		}
		break;
	case 3: 
		if (timer.edit==true){
		timer.subtractValue();
		}else{
		timer.stop();
		}
		break;
	case 4: 
		if (alarm.edit==true){
		alarm.subtractValue();
		}
		break;
	
	case 5:
		if (timerAlarm.getEditValue()==true){
		timerAlarm.removeTimerAlarm(timerAlarm.getPosition());
		}
		else{
		timerAlarm.changePosition(-1);
		}
		break;
	}

}
void Watch::startLap(){
	Serial.println(_modeIndex);
	switch(_modeIndex){
	case 0: 
		if (time.edit=true){
		time.addValue();
		}
		break;
	case 1: 
		if (interval.edit=true){
		interval.addValue();
		}
		break;
	case 3: 
		Serial.println(timer.started);

		if (timer.edit==true){
		timer.addValue();
		}else{
			if (timer.started==true){
				//timer.started=false;
			}
			else{
			timer.start();
			timer.startSeconds=timer.getTotalSeconds();

			Serial.println(timer.started);
			}
		
		}
	break;
	case 4:
		//Serial.println(alarm.started);

		if (alarm.edit==true){
		alarm.addValue();
		}else{
			if (alarm.started==true){
				alarm.started=false;
			}
			else{
			alarm.started=true;
			Serial.println(alarm.started);
			}
		
		}
	break;
	case 5:
		if (timerAlarm.getEditValue()==true){
			timerAlarm.addTimerAlarm(timer,alarm);
		}else
		{
		timerAlarm.changePosition(1);
		}
		break;
	}

}

void Watch::toggleEdit(){
	switch(_modeIndex){
	case 0:
		if (time.edit==true){
		time.edit=false;
		}else{
		time.edit=true;
		}
		break;
	case 1:
		if (interval.edit==true){
		interval.edit=false;
		}else{
		interval.edit=true;
		}
		break;
	case 3:
		if (timer.edit==true){
		timer.edit=false;
		}else{
		timer.edit=true;
		}
		break;
	case 4:
		Serial.println("edit A");
		if (alarm.edit==true){
		alarm.edit=false;
		}else{
		alarm.edit=true;
		}
		break;
	case 5:
		timerAlarm.changeEditValue();
		break;

	}
}
void Watch::changeMode()
{
	switch (_modeIndex){
		case 0:
			//if I'm not in editing mode then change modes
			if (time.edit==false){
			_modeIndex +=1;
			Serial.println("Interval");
			}
			else{//if I'm in editing mode then adjust editing for HH MM or SS
			time.changeEditAttribute();
			}


			break;
		case 1:
			if (interval.edit==false){
				_modeIndex +=1;
				Serial.println("Data");
			}
			else{//if I'm in editing mode then adjust editing for HH MM or SS
			interval.changeEditAttribute();
			}

			
			break;
		case 2:
			_modeIndex +=1;
			Serial.println("Timer");
			break;
		case 3:
			//if I'm not in editing mode then change modes
			if (timer.edit==false){
			_modeIndex +=1;
			Serial.println("Alarm");
			}
			else{//if I'm in editing mode then adjust editing for HH MM or SS
				Serial.println("EA");
			timer.changeEditAttribute();
			}

			
			break;
		case 4:
			if (alarm.edit==false){
				_modeIndex +=1;
			Serial.println("Timer Alarm Series");
			}else{
			alarm.changeEditAttribute();
			}
			break;

		case 5:
			_modeIndex +=1;
			Serial.println("Time");
			break;		
	}

	//if I'm not editing the current mode
	if (_modeIndex<6){

	}
	else{
		_modeIndex=0;
	}

}
int Watch::getCurrentMode(){
return _modeIndex;
}