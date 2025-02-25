#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

int ledPin = 13;
int sleepPin = 12;
int interruptPin = 10;
int wakePin = 2;
int sleepStatus = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, OUTPUT);
  pinMode(sleepPin, INPUT_PULLUP);
  pinMode(wakePin, INPUT_PULLUP);
  attachInterrupt(0, wakeUpNow, LOW);
}

void sleepNow()
{
  Serial.println("going to sleep");
  delay(15);

  sleep_enable();

  attachInterrupt(0, wakeUpNow, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  sleep_mode();
  sleep_disable();

  detachInterrupt(0);

  delay(1000);
  digitalWrite(interruptPin, LOW);
}

void wakeUpNow()
{
  digitalWrite(interruptPin, HIGH);
}

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  sleepStatus = digitalRead(sleepPin);

  if (sleepStatus == LOW)
  {
    sleepNow();
  }
}