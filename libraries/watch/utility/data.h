/*
  Watch.h - Library for creating a watch.
  Created by Jeffrey L. Myers, Feburary 20, 2013.
  Released into the public domain.
*/
#ifndef Data_h
#define Data_h

#include "Arduino.h"




class DataMode
{
  public:
	DataMode();
    bool edit;
	/* int getCurrentMode();
    void changeMode();*/
   virtual String sayHello();

  private:
   int Hours;
	int Minutes;
	int Seconds;
    int totalSeconds;
    int hmsActive;


};

#endif