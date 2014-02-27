/*
  Time.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#include "Arduino.h"
#include "timer.h"

TimerMode::TimerMode()
{
	bool edit=false;
	
	Hours=0;
	Minutes=0;
	Seconds=0;
    totalSeconds = 120;
    hmsActive = 0;
	blinkOn=true;
	started=false;
	_switchPin=13;

	 TMRinterval=500;           // interval at which to blink (milliseconds)
     TMRpreviousMillis=0;
	 strHours="";
	 strMinutes="";
	 strSeconds="";


}
//TimerMode::TimerMode(int switchPin)
//{
//	bool edit=false;
//	
//	Hours=0;
//	Minutes=0;
//	Seconds=0;
//    totalSeconds = 120;
//    hmsActive = 0;
//	blinkOn=true;
//	started=false;
//	_switchPin=switchPin;
//
//
//}
void TimerMode::subtractSecond(){
//Serial.println(totalSeconds);
totalSeconds-=1;
}
void TimerMode::changeEditAttribute(){
hmsActive +=1;
if (hmsActive >3){
hmsActive=0;
}
}
void TimerMode::subtractValue(){
	if (edit==true){
		switch (hmsActive){
		case 0 :
			Hours -=1;
			break;
		case 1:
			Minutes -=1;
			break;
		case 2:
			Seconds -=1;
			break;
		case 3:
			if (Hours<=12){
			Hours +=12;
			}else
			{
			 Hours -= 12;
			}
			break;
		}
	
	}
	totalSeconds= ((long)Hours *3600)+((long)Minutes *60)+ (long)Seconds;




}

void TimerMode::addValue(){
	if (edit==true){
		switch (hmsActive){
		case 0 :
			Hours +=1;
			break;
		case 1:
			Minutes +=1;
			break;
		case 2:
			Seconds +=1;
			break;
		case 3:
			if (Hours<=12){
			Hours +=12;
			}else
			{
				Hours -= 12;
			}
			break;
		}
	
	}
	totalSeconds= ((long)Hours *3600)+((long)Minutes *60)+ (long)Seconds;
	


}
String TimerMode::getCurrentValue(){
	

	Seconds=totalSeconds % 60;
	
	Minutes=((totalSeconds-Seconds)/60) % 60;
	Hours=((totalSeconds-(Seconds+(Minutes*60)))/3600) % 60;
	
	if (Hours >23){
	Hours=0;
	}

    strHours=String(Hours);
	strMinutes=String(Minutes);
	strSeconds=String(Seconds);
	if (Seconds<10){
		strSeconds="0" + String(Seconds);
	}
	if (Minutes<10){
		strMinutes="0" + String(Minutes);
	}
	

	
	if (edit==true){
	 TMRcurrentMillis = millis();
 
  if(TMRcurrentMillis - TMRpreviousMillis >TMRinterval) {
    // save the last time you blinked the LED
   if (blinkOn==true){
	   blinkOn=false;}
   else
			{
			blinkOn=true;
			}


	  TMRpreviousMillis = TMRcurrentMillis;  
  }


		if (blinkOn==true){
	
			switch(hmsActive){
				case 0:
					strHours= " ";
						break;
				case 1:
					strMinutes=" ";
						break;
				case 2:
					strSeconds=" ";
						break;

			}

		}
	}
	return (strHours + ":" + strMinutes +":" + strSeconds);



}
long TimerMode::getTotalSeconds(){
return totalSeconds;
}
void TimerMode::stop(){
started=false;
totalSeconds=startSeconds;
digitalWrite(_switchPin,LOW);
}
void TimerMode::start(){
started=true;
startSeconds=totalSeconds;
digitalWrite(_switchPin,HIGH);
//Serial.println("turned on");


}
String TimerMode::sayHello(){

//return "Hello_from_Timer";
	return getCurrentValue();
//	return String(_switchPin);

}

//void Watch::changeMode()
//{
//
//}
//int Watch::getCurrentMode(){
//return _modeIndex;
//}