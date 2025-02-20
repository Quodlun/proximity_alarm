#include <Arduino.h>
#include "define.h"

void ledSetup ()
{
  int ledSetupSort [ 4 ] = { 5, 6, 7, 5 };
  
  for ( int i = 5; i < 8; i ++ )
  {
    pinMode ( i, OUTPUT );
  }
  
  for ( int i = 0, i < 4, i ++ )
  {
    digitalWrite ( ledSetupSort [ i ], HIgh )
    delay ( 30 );
    digitalWrite ( ledSetupSort [ i ], LOW )
  }
  
  delay ( 1000 );
  
  for ( int i = 5; i < 8; i ++ )
  {
    digitalWrite ( i, HIGH );
  }
  
  
}

unsigned float rangeFinding ()
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
  for ( int i = 5; i < 8; i++ )
  {
    digitalWrite( i, LOW );
  }
  delay( 150 );
  noTone( buzzerPin );
  for ( int i = 5; i < 8; i++ )
  {
    digitalWrite( i, HIGH );
  }
  delay( 25 );
  
  tone( buzzerPin, buzzerTone );
  for ( int i = 5; i < 8; i++ )
  {
    digitalWrite( i, LOW );
  }
  delay( 300 );
  noTone( buzzerPin );
  for ( int i = 5; i < 8; i++ )
  {
    digitalWrite( i, HIGH );
  }
  delay( 150 );
  
  tone( buzzerPin, buzzerTone );
  for ( int i = 5; i < 8; i++ )
  {
    digitalWrite( i, LOW );
  }
  delay( 300 );
  noTone( buzzerPin );
  for ( int i = 5; i < 8; i++ )
  {
    digitalWrite( i, HIGH );
  }
  delay( 1000 );
}