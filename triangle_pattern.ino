#include "triangle_pattern.h"

TrianglePattern::TrianglePattern(int setLoopTime, int setMinLightness, int setMaxLightness) {
  // Constructor
  hue = 300;
  saturation = 100;
  minLightness = setMinLightness;
  maxLightness = setMaxLightness;
  lightness = minLightness;
  rgb = HslToRgb(hue, saturation, lightness);

  loopSteps = 360;
  delayPerStep = int(setLoopTime * 1000.0 / loopSteps);
  state = 0;
}

Rgb TrianglePattern::Update() {
  currentMillis = millis();
  if ((state == 0) && ((currentMillis - previousMillis) >= delayPerStep)) {
      // increase hue and lightness
      previousMillis = currentMillis;
      hue = (hue + 1) % 360;
      lightness = lightness + 0.2;
      if (lightness >= maxLightness) 
        state = 1;

  } else if ((state == 1) && ((currentMillis - previousMillis) >= delayPerStep)) {
      // incrase hue, decrease lightness
      previousMillis = currentMillis;
      hue = (hue + 1) % 360;
      lightness = lightness - 0.2;
      if (lightness <= minLightness)
        state = 0;
        
  }
  
  rgb = HslToRgb(hue, saturation, lightness);
  
//  #ifdef DEBUG_LOG
//    Serial.print(F("State: "));
//    Serial.print(state);
//    Serial.print(F(". HSL: "));
//    Serial.print(hue);
//    Serial.print(F(", "));
//    Serial.print(saturation);
//    Serial.print(F(", "));
//    Serial.print(lightness);
//    Serial.print(F(". "));
//  #endif

  return rgb;
}

