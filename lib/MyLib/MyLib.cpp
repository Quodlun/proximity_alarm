#include <Arduino.h>
#include "define.h"

void ledSetup ()
{
  int ledSetupSort [ 4 ] = { 5, 6, 7, 5 };
  
  pinMode ( allLedPin, OUTPUT );
  
  for ( int i = 5; i < 8; i ++ )
  {
    pinMode ( i, OUTPUT );
    digitalWrite ( i, LOW );
  }
  
  for ( int i = 0; i < 4; i ++ )
  {
    digitalWrite ( ledSetupSort [ i ], HIGH );
    delay ( 100 );
    digitalWrite ( ledSetupSort [ i ], LOW );
  }
  
  delay ( 500 );
  
  digitalWrite ( allLedPin, HIGH );
  
  
}

float rangeFinding ()
{
  digitalWrite( trigPin, LOW );
  delayMicroseconds( 2 );
  digitalWrite( trigPin, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( trigPin, LOW );
  
  return ( ( pulseIn( echoPin, HIGH ) / 2 ) / 29.1 );
}

void alarmWork ()
{
  tone( buzzerPin, buzzerTone );
  digitalWrite ( allLedPin, LOW );
  delay( 150 );
  noTone( buzzerPin );
  digitalWrite ( allLedPin, HIGH );
  delay( 25 );
  
  tone( buzzerPin, buzzerTone );
  digitalWrite ( allLedPin, LOW );
  delay( 300 );
  noTone( buzzerPin );
  digitalWrite ( allLedPin, HIGH );
  delay( 150 );
  
  tone( buzzerPin, buzzerTone );
  digitalWrite ( allLedPin, LOW );
  delay( 300 );
  noTone( buzzerPin );
  digitalWrite ( allLedPin, HIGH );
  delay( 1000 );
}