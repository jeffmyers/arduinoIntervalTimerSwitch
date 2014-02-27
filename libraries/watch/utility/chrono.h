/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef Chrono_h
#define Chrono_h

#include "Arduino.h"




class ChronoMode
{
  public:
	ChronoMode();
    bool edit;
   virtual String sayHello();

  private:
   int Hours;
	int Minutes;
	int Seconds;
    int totalSeconds;
    int hmsActive;


};

#endif