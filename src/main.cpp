#include <Arduino.h>
#include <toneAC.h>
#include <NewPing.h>
#include "define.h"

/// @brief 距離感測器初始化
NewPing sonar ( triggerPin, echoPin, maxDistance );

/// @section Setup 程式
void setup ()
{
  /// @brief 初始化序列埠, 鮑率: 9600
  Serial.begin ( 9600 );

  /// @brief 初始化元件腳位
  pinMode ( buzzerPin, OUTPUT );
  pinMode ( ledPin, OUTPUT );
}

/// @section 主程式
void loop ()
{
  /// @brief 距離感測器測距
  unsigned int distance = sonar.ping_cm ();

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