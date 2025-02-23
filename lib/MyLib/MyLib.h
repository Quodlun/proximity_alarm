#ifndef DEFINE_H
#define DEFINE_H

#define ledPin1 5
#define ledPin2 6
#define ledPin3 7

#define trigPin 12
#define echoPin A0

#define buzzerPin 8
#define buzzerTone 1568

void ledSetup ();
float rangeFinding ();
void alarmWork ();

#endif