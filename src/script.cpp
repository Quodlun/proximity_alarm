#include <Arduino.h>
#include "define.h"

unsigned long measureDistance ()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return ( pulseIn(echoPin, HIGH) / 58 );
}

void ledBlink ()
{
  digitalWrite ( ledPin, HIGH );
  delay ( 150 );
  digitalWrite ( ledPin, LOW );
  delay ( 25 );

  digitalWrite ( ledPin, HIGH );
  delay ( 300 );
  digitalWrite ( ledPin, LOW );
  delay ( 150 );

  digitalWrite ( ledPin, HIGH );
  delay ( 300 );
  digitalWrite ( ledPin, LOW );
  delay ( 1000 );
}