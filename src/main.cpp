#include <Arduino.h>
#include "define.h"

void setup ()
{
  Serial.begin ( 9600 );
  
  pinMode ( ledPin, OUTPUT );

  digitalWrite ( ledPin, LOW );
}

void loop ()
{
  Serial.println ( measureDistance () );
}