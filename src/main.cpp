#include <Arduino.h>
#include "..\lib\define.h"
#include "..\lib\script.cpp"

void setup ()
{
  Serial.begin ( 9600 );
  
  ledSetup ();

  pinMode ( trigPin, OUTPUT );
  pinMode ( echoPin, INPUT );

  pinMode ( buzzerPin, OUTPUT );
}

void loop ()
{
  float cm = rangeFinding ();
  
  if ( cm < 10 )
  {
    alarmWork ();
  }
  
  delay ( 50 );
}