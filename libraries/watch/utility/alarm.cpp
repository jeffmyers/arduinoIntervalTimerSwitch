/*
  Time.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#include "Arduino.h"
#include "alarm.h"


AlarmMode::AlarmMode()
{
	bool edit=false;
	int Hours;
	int Minutes;
	int Seconds;
    totalSeconds = 20;
     hmsActive = 0;
	 ALinterval=500;           // interval at which to blink (milliseconds)
     ALpreviousMillis=0;

	  String strHours="";
	String strMinutes="";
	String strSeconds="";


}

void AlarmMode::addSecond(){
totalSeconds+=1;

}
void AlarmMode::changeEditAttribute(){
hmsActive +=1;
if (hmsActive >3){
hmsActive=0;
}
}
void AlarmMode::subtractValue(){
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

void AlarmMode::addValue(){
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

long AlarmMode::getTotalSeconds(){
return totalSeconds;
}
String AlarmMode::getCurrentValue(){
	

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


String AlarmMode::sayHello(){

//return "Hello_from_Alarm";
return getCurrentValue();

}

//void Watch::changeMode()
//{
//
//}
//int Watch::getCurrentMode(){
//return _modeIndex;
//}