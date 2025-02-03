#include <Arduino.h>
#include <toneAC.h>
#include <NewPing.h>
#include "define.h"

/// @section 蜂鳴器運作副程式
void sonarDetected ()
{
  digitalWrite ( ledPin, HIGH );
  toneAC ( buzzerTone, buzzerVolume, 150, 1 );
  digitalWrite ( ledPin, LOW );
  delay ( 175 );

  digitalWrite ( ledPin, HIGH );
  toneAC ( buzzerTone, buzzerVolume, 300, 1 );
  digitalWrite ( ledPin, LOW );
  delay ( 450 );

  digitalWrite ( ledPin, HIGH );
  toneAC ( buzzerTone, buzzerVolume, 300, 1 );
  digitalWrite ( ledPin, LOW );
  delay ( 1300 );
} 