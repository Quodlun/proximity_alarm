#include <Arduino.h>
#include <toneAC.h>
#include <Ultrasonic.h>
#include "define.h"

/// @brief 距離感測器初始化
Ultrasonic ultrasonic ( triggerPin, echoPin );

/// @section Setup 程式
void setup ()
{
  /// @brief 初始化序列埠, 鮑率: 9600
  Serial.begin ( 9600 );

  /// @brief 初始化元件腳位
  pinMode ( ledPin, OUTPUT );
}

/// @section 主程式
void loop ()
{
  /// @brief 距離感測器測距
  int distance = ultrasonic.read();

  /// @brief 偵測距離是否小於等於 20 公分
  if ( distance <= 20 )
  {
    /// @brief 呼叫蜂鳴器副程式
    sonarDetected ();
  }

  /// @brief 顯示距離
  Serial.print ( "距離(cm)：" );
  Serial.println ( distance );
}