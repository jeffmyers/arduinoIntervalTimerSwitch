/*
  Time.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#include "Arduino.h"
#include "chrono.h"


ChronoMode::ChronoMode()
{
	bool edit=false;
	int Hours;
	int Minutes;
	int Seconds;
    int totalSeconds = 85800;
    int hmsActive = 0;

}
String ChronoMode::sayHello(){

return "Hello_from_Chrono";
}