#include <Arduino.h>
#include "define.h"

void alarmWork ()
{
  tone( buzzerPin, 1568 );
  digitalWrite( ledPin, LOW );
  delay( 150 );
  noTone( buzzerPin );
  digitalWrite( ledPin, HIGH );
  delay( 25 );
  
  tone( buzzerPin, 1568 );
  digitalWrite( ledPin, LOW );
  delay( 300 );
  noTone( buzzerPin );
  digitalWrite( ledPin, HIGH );
  delay( 150 );
  
  tone( buzzerPin, 1568 );
  digitalWrite( ledPin, LOW );
  delay( 300 );
  noTone( buzzerPin );
  digitalWrite( ledPin, HIGH );
  delay( 1000 );
}