#include "square_pattern.h"

SquarePattern::SquarePattern(int setLoopTime, int setMinLightness, int setMaxLightness) {
  // Constructor
  hue = 300;
  saturation = 100;
  minLightness = setMinLightness;
  maxLightness = setMaxLightness;
  lightness = minLightness;
  rgb = HslToRgb(hue, saturation, lightness);

// horizontal steps change hue. There are 360 horz steps
// vertical steps change lightness. There are maxLight-minLight (45) full steps
// vertical steps are repeated every waveWidth (20) degrees, so 360/waveWidth = 18
// therefore vert steps = 45 * 18 = 810
  loopSteps = 360 + ((maxLightness - minLightness) * 360 / waveWidth);
  delayPerStep = int(setLoopTime * 1000.0 / loopSteps);
  state = 0;
}

Rgb SquarePattern::Update() {
  currentMillis = millis();
  if ((state == 0) && ((currentMillis - previousMillis) >= (delayPerStep /5))) {
      // brightening lightness
      previousMillis = currentMillis;
      lightness = lightness + 0.2;
      if (lightness >= maxLightness) 
        state = state + 1;        
    } else if ((state == 1) && ((currentMillis - previousMillis) >= delayPerStep)) {
      // increasing hue at max lightness
      previousMillis = currentMillis;
      hue = hue + 1;
      if ((hue % (waveWidth * 2)) == waveWidth)
        state = state + 1;
        
    } else if ((state == 2) && ((currentMillis - previousMillis) >= (delayPerStep /5))) {
      // reducing lightness
      previousMillis = currentMillis;
      lightness = lightness - 0.2;
      if (lightness <= minLightness)
        state = state + 1;
        
    } else if ((state == 3) && ((currentMillis - previousMillis) >= delayPerStep)) {
      // increasing hue at min lightness
      previousMillis = currentMillis;
      hue = hue + 1;
      if ((hue % (waveWidth * 2)) == 0)
        state = 0;
    }
  
    if (hue == 360)
      hue = 0;
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

