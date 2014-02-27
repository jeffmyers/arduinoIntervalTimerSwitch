#include <watch.h>
Watch watch(0);
void setup()
{
  Serial.begin(9600);

}

void loop()
{
  String _string;
  _string=watch.time.sayHello();
  char _str[sizeof(_string)];
  _string.toCharArray(_str,sizeof(_str));
  
 
    
  Serial.println(_str);
  

}



