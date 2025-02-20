#include <Arduino.h>
#include "define.h"

float cm;

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
  cm = rangeFinding ();
  
  if ( cm < 10 )
  {
    alarmWork ();  }
  
  Serial.print ( "Distance:" ); 
  Serial.print ( cm );
  Serial.print ( "cm" );
  Serial.println ();
  
  delay ( 50 );
}