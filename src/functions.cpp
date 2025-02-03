#include <Arduino.h>
#include <NewTone.h>
#include <NewPing.h>
#include "define.h"

/// @section 蜂鳴器運作副程式
void sonarDetected ()
{
  digitalWrite ( ledPin, HIGH );
  NewTone ( buzzerPin, buzzerTone, 150 );
  digitalWrite ( ledPin, LOW );
  delay ( 175 );

  digitalWrite ( ledPin, HIGH );
  NewTone ( buzzerPin, buzzerTone, 300 );
  digitalWrite ( ledPin, LOW );
  delay ( 450 );

  digitalWrite ( ledPin, HIGH );
  NewTone ( buzzerPin, buzzerTone, 300 );
  digitalWrite ( ledPin, LOW );
  delay ( 1300 );
}