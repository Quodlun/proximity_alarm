#include <Arduino.h>
#include "define.h"

void alarmWork ()
{
  tone( buzzerPin, 1568 );
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
  
  tone( buzzerPin, 1568 );
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
  
  tone( buzzerPin, 1568 );
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