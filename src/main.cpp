#include <Arduino.h>
#include <NewTone.h>
#include <NewPing.h>
#include "define.h"

/// @brief 距離感測器初始化
NewPing sonar ( triggerPin, echoPin, maxDistance );

void setup ()
{
  /// @brief 初始化序列埠, 鮑率: 9600
  Serial.begin ( 9600 );

  /// @brief 初始化蜂鳴器腳位
  pinMode ( buzzerPin, OUTPUT );
}

void loop ()
{
  /// @brief 距離感測器測距
  unsigned int distance = sonar.ping_cm ();

  /// @brief 偵測距離是否小於等於 50 公分
  if ( distance <= 50 )
  {
    /// @brief 呼叫蜂鳴器副程式
    buzzerWork ();
  }

  else 
  {
    /// @brief 平衡偵測時間
    delay ( 2000 );
  }

  /// @brief 顯示距離
  Serial.print ( "距離(cm)：" );
  Serial.println ( distance );
}