#ifndef DEFINE_H
#define DEFINE_H

/// @section 腳位定義
#define ledPin        8
#define triggerPin    11
#define echoPin       12

/// @section 常數定義
#define buzzerTone    1568
#define buzzerVolume  10
#define maxDistance   300

/// @section 副程式定義
void sonarDetected ();
void ledDebug ();

#endif