#include <Arduino.h>
#include <NewTone.h>
#include <NewPing.h>
#include "define.h"

NewPing sonar ( triggerPin, echoPin, maxDistance );

void setup ()
{
  Serial.begin ( 9600 );
  pinMode ( buzzerPin, OUTPUT );
}

void loop ()
{
  unsigned int distance = sonar.ping_cm ();

  if ( distance <= 50 )
  {
    buzzerWork ();
    Serial.println ( "Buzzer Worked" );
  }

  else 
  {
    delay ( 2000 );
    Serial.println ( "Buzzer Not Worked" );
  }

  Serial.print ( "距離(cm)：" );
  Serial.println ( distance );
}