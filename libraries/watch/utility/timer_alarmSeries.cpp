/*
  Time.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#include "Arduino.h"
#include "timer_alarmSeries.h"


TimerAlarmMode::TimerAlarmMode()
{
	 edit=false;
	 alarmI=0;
	 numAlarms=4;
	 int activeTimerAlarm[4]={0,0,0,0};
	  ALinterval=500;           // interval at which to blink (milliseconds)
     ALpreviousMillis=0;
	 int i=0;

}
void TimerAlarmMode::addTimerAlarm(TimerMode timer, AlarmMode alarm){
	  
	 alarms[alarmI]=alarm;
     timers[alarmI]=timer;
	activeTimerAlarm[alarmI]=1;
	//numAlarms += 1;
	// Serial.println("two");
}
void TimerAlarmMode::checkAlarm(long totalSeconds){
	i=0;

	for ( i=0; i<numAlarms; i=i+1){
		if (activeTimerAlarm[i] !=0){
			if(activeTimerAlarm[i] !=0){
				////put a huge loop to iterater throug and break it... it works with four now
				//int z=0;
				//int counter=0;
				//	for (z=0;z<20000;z=z+1){
				//counter=counter+1;

//				}

				if ((alarms[i].getTotalSeconds()==totalSeconds) && (activeTimerAlarm[i] !=0) ){//watch.time.getTotalSeconds()){//i'm guessing it fails when I check the .getTotalSeconds() when the array is full of empty objects
				  timers[i].start();
				}	
		   if ((timers[i].started==true) && (activeTimerAlarm[i] !=0) ){
			 timers[i].subtractSecond();
				 if (timers[i].getTotalSeconds()==0) {
					 timers[i].stop();
					}
 			 }
		   }
			}


		}
	}
void TimerAlarmMode::changePosition(int i){
	
	alarmI += i;
	if (alarmI>numAlarms-1){alarmI=0;}
	if (alarmI<0){alarmI=numAlarms-1;}
}
int TimerAlarmMode::getPosition(){
return alarmI;
}

void TimerAlarmMode::removeTimerAlarm(int position){
	  alarms[position]=blankalarm;
	  timers[position]=blanktimer;
	  activeTimerAlarm[alarmI]=0;
	 // numAlarms-=1;
}
void TimerAlarmMode::changeEditValue(){
	if (edit==true){
		edit=false;
	}else
	{	edit=true;
		}

}
bool TimerAlarmMode::getEditValue(){
return edit;
}
String TimerAlarmMode::sayHello(){
	
		if (edit==true){
	 ALcurrentMillis = millis();
 
  if(ALcurrentMillis - ALpreviousMillis > ALinterval) {
    // save the last time you blinked the LED
   if (blinkOn==true){
	   blinkOn=false;}
   else
			{
			blinkOn=true;
			}


	  ALpreviousMillis = ALcurrentMillis;  
  }

		
		}
		if (edit==true && blinkOn==false){
		return ("|");
		
		}
		else{
			if (activeTimerAlarm[alarmI] != 0 ){
				
		//return ("||" + String(alarmI));//(alarms[alarmI].getCurrentValue() +"  " + timers[alarmI].getCurrentValue()); //"Hello_from_ Timer Alarm Series";
			//return(String(alarms[alarmI].getCurrentValue()));
			//return(String(timers[alarmI].getCurrentValue()));.
		    String timerValue=(String(timers[alarmI].getCurrentValue()));
			String alarmValue=(String(alarms[alarmI].getCurrentValue()));
			return (alarmValue+" "+timerValue);
			/*String combinedValue=(alarmValue +"|" +timerValue);
			combinedValue=alarmValue;
			combinedValue=timerValue;*/
			//combinedValue="1231456789111213141516";
			//char myString[50];
			//timerValue.toCharArray(myString,50);

		/*
			char str1[48];
			alarmValue.toCharArray(str1,48);
			char str2[50];
			timerValue.toCharArray(str2,48);*/
			
			
			/*char str3[100];
			strcpy(str3,str1);
			strcat(str3,str2);
*/


			//fails	//return(String(alarms[alarmI].getCurrentValue())+" "+ String(timers[alarmI].getCurrentValue()));
			//return ("||" + String(alarmI));//(alarms[alarmI].getCurrentValue() +"  " + timers[alarmI].getCurrentValue()); //"Hello_from_ Timer Alarm Series";
		//return myString;


			}else{
				return ("no alarms " +  String(activeTimerAlarm[alarmI]));

			}
		}
	}
	