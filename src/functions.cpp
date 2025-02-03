#include <Arduino.h>
#include <NewTone.h>
#include <NewPing.h>
#include "define.h"

/// @section 蜂鳴器運作副程式
void buzzerWork ()
{
  NewTone ( buzzerPin, buzzerTone, 150 );
  delay ( 175 );

  NewTone ( buzzerPin, buzzerTone, 300 );
  delay ( 450 );

  NewTone ( buzzerPin, buzzerTone, 300 );
  delay ( 1300 );
}
