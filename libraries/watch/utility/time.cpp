/*
  Time.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#include "Arduino.h"
#include "time.h"
TimeMode::TimeMode()
{
	edit=false;
	blinkOn=true;
	Hours=0;
	Minutes=0;
	Seconds=0;
    totalSeconds =0;
    hmsActive = 0;

		blinkOn=true;

	 TMRinterval=500;           // interval at which to blink (milliseconds)
     TMRpreviousMillis=0;

	 strHours="";
	 strMinutes="";
	 strSeconds="";


}
void TimeMode::addSecond(){
totalSeconds+=1;

}
void TimeMode::changeEditAttribute(){
hmsActive +=1;
if (hmsActive >3){
hmsActive=0;
}
}
void TimeMode::subtractValue(){
	if (edit==true){
		switch (hmsActive){
		case 0 :
			Hours -=1;
			Serial.println("Hours: "+ String(Hours));
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
	Serial.println(totalSeconds);
	totalSeconds= ((long)Hours *3600)+((long)Minutes *60)+ (long)Seconds;
	Serial.println(totalSeconds);
}

void TimeMode::addValue(){
	if (edit==true){
		switch (hmsActive){
		case 0 :
			Hours +=1;
			Serial.println("Hours: "+ String(Hours));
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
	Serial.println(totalSeconds);
	totalSeconds= ((long)Hours *3600)+((long)Minutes *60)+ (long)Seconds;
	Serial.println(totalSeconds);
}
String TimeMode::getCurrentValue(){
	

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
long TimeMode::getTotalSeconds(){
return totalSeconds;
}
String TimeMode::sayHello(){
	return getCurrentValue();
}
