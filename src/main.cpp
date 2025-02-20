#include <Arduino.h>
#include "define.h"

float duration, cm;

void setup()
{
  Serial.begin ( 9600 );
  
  for ( int i = 5; i < 8; i++ )
  {
    pinMode( i, OUTPUT );
    digitalWrite( i, HIGH );
  }

  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );

  pinMode( buzzerPin, OUTPUT );
}

void loop()
{
  digitalWrite( trigPin, LOW );
  delayMicroseconds( 2 );
  digitalWrite( trigPin, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( trigPin, LOW );
  
  duration = pulseIn( echoPin, HIGH );
  
  cm = ( duration/2 ) / 29.1;
  if( cm < 10 )
  {
    alarmWork ();
  }
  
  Serial.print( "Distance:" ); 
  Serial.print( cm );
  Serial.print( "cm" );
  Serial.println();
  
  delay(50);
}

