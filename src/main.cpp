#include <Arduino.h>
#include "..\lib\define.h"
#include "..\lib\script.cpp"

void setup ()
{
  ledSetup ();

  pinMode ( trigPin, OUTPUT );
  pinMode ( echoPin, INPUT );

  pinMode ( buzzerPin, OUTPUT );
}

void loop ()
{  
  if ( rangeFinding () < 10 )
  {
    alarmWork ();
  }
  
  delay ( 50 );
}