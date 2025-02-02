#include <Arduino.h>
#include <NewTone.h>
#include <NewPing.h>

#define buzzerPin   3
#define buzzerTone  1568
#define triggerPin  9
#define echoPin     10
#define maxDistance 300

NewPing sonar ( triggerPin, echoPin, maxDistance );

void buzzerWork ()
{
  NewTone ( buzzerPin, buzzerTone, 150 );
  delay ( 175 );

  NewTone ( buzzerPin, buzzerTone, 300 );
  delay ( 450 );

  NewTone ( buzzerPin, buzzerTone, 300 );
  delay ( 1300 );
}

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