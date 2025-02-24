#include <Arduino.h>

//These are the two libraries that are needed 
#include <avr/interrupt.h>
#include <avr/sleep.h>

/* Here we set up our inputs and outputs.  LEDs connected to pins 10 and 13 and pushbuttons attached to 2 and 12 */
int ledPin = 13;
int sleepPin = 12;
int interruptPin = 10;
int wakePin = 2;
//sleepStatus is set up to keep track of the button input on pin 12.
int sleepStatus = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);        
  pinMode(interruptPin, OUTPUT);   
  pinMode(sleepPin, INPUT_PULLUP);  
  pinMode(wakePin, INPUT_PULLUP);

/* Next we have to enable an interrupt.  

The function is set up like this attachInterrupt(pin, function, triggerMode)  

PIN – can be either a 0 to call out digital pin 2 or 1 to call out digital pin 3.

FUNCTION – This is the function that will be run while in the interrupt

TRIGGER MODE – this will be the mode of the interrupt pin.  
It can be one the following:
	LOW – a low level trigger
	CHANGE – a change in level trigger
	RISING – a rising edge trigger
	FALLING – a falling edge trigger

The IDLE sleep mode is the only mode that can use CHANGE, RISING, and FALLING modes.*/


  attachInterrupt(0, wakeUpNow, LOW);
}

void sleepNow()
{
//print message to serial monitor to let the user know board has gone to sleep
Serial.println("going to sleep");
//delay is added to allow user to get the full message on the serial monitor before going to sleep
delay(15);

//enables the sleep mode
sleep_enable();

// This is where we enable the interrupt, the reason it is done here is so that if the button is pressed accidently it doesn’t interrupt the running program.  
attachInterrupt(0,wakeUpNow, LOW);


/* The next line is where we choose the sleep mode we want to use for this code.  There are a few options to choose from, each with their own uses.  For more information on the sleep modes, please review the Atmega8 datasheet at [http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf](http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf)

The 5 different options for sleep modes, they are listed below from least power savings to most power savings:
	SLEEP_MODE_IDLE
	SLEEP_MODE_ADC
	SLEEP_MODE_PWR_SAVE
	SLEEP_MODE_STANDBY
	SLEEP_MODE_PWR_DOWN

For this sketch, we will be using the most power savings possible so we choose SLEEP_MODE_PWR_DOWN */

//sleep mode is set here
set_sleep_mode(SLEEP_MODE_PWR_DOWN);


//This is where the device is actually put to sleep
sleep_mode();

//Here is where the device begins to wake up.

//First thing that is done is to disable the sleep mode
sleep_disable();

//disables the interrupt on pin 2 so the wakeUpNow code will not be executed during normal run time
detachInterrupt(0);

//wait 1 second so the user can notice the LED signaling the interrupt
delay(1000);
digitalWrite (interruptPin, LOW);
}

void wakeUpNow()  //This is the code that runs when the interrupt button is pressed and interrupts are enabled
{
digitalWrite(interruptPin, HIGH);
}

void loop()
{
// turns the LED on
  digitalWrite(ledPin, HIGH);   
// waits for a second         
  delay(1000);         
// turns the LED off                  
  digitalWrite(ledPin, LOW); 
// waits for a second            
  delay(1000);          
//This is where the sleep pin is read.  It is only active when the LED is off.                 
  sleepStatus = digitalRead(sleepPin);   

//If button is pressed, device will run the sleepNow function                                         
  if (sleepStatus == LOW) {            
      sleepNow();                      
      }
}