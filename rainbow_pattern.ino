#include "rainbow_pattern.h"

RainbowPattern::RainbowPattern(int setLoopTime) {
  // Constructor
  hue = 300;
  delayPerStep = int(setLoopTime * 1000 / 360);
}

Rgb RainbowPattern::Update() {
  currentMillis = millis();
  if ((currentMillis - previousMillis) >= delayPerStep) {
    previousMillis = currentMillis;
    hue = (hue + 1) % 360;
  }
  rgb = HslToRgb(hue, 100, 50);

//  #ifdef DEBUG_LOG
//    Serial.print(F("Hue: "));
//    Serial.print(hue);
//    Serial.print(F(". "));
//  #endif
  
  return rgb;
}

