#include <Arduino.h>
#include "define.h"

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