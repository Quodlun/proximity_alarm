#include <Arduino.h>
#include "MyLib.h"

void allLedOn ()
{
  for ( int i = 5; i < 8; i ++ )
  {
    digitalWrite ( i, HIGH );
  }
}

void allLedOff ()
{
  for ( int i = 5; i < 8; i ++ )
  {
    digitalWrite ( i, LOW );
  }
}

void ledSetup ()
{
  int ledSetupSort [ 4 ] = { 5, 6, 7, 5 };
  
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

  allLedOn ();
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
  allLedOff ();
  delay( 150 );
  noTone( buzzerPin );
  allLedOn ();
  delay( 25 );
  
  tone( buzzerPin, buzzerTone );
  allLedOff ();
  delay( 300 );
  noTone( buzzerPin );
  allLedOn ();
  delay( 150 );
  
  tone( buzzerPin, buzzerTone );
  allLedOff ();
  delay( 300 );
  noTone( buzzerPin );
  allLedOn ();
  delay( 1000 );
}