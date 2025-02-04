#include <Arduino.h>

void setup ()
{
  pinMode ( 8, OUTPUT );
}

void loop ()
{
  digitalWrite ( 8, HIGH );
  delay ( 150 );
  digitalWrite ( 8, LOW );
  delay ( 25 );

  digitalWrite ( 8, HIGH );
  delay ( 300 );
  digitalWrite ( 8, LOW );
  delay ( 150 );

  digitalWrite ( 8, HIGH );
  delay ( 300 );
  digitalWrite ( 8, LOW );
  delay ( 1000 );
}