#include "square_pattern.h"

SquarePattern::SquarePattern(int setLoopTime, int setMinLum, int setMaxLum) {
  /* Concerns:
   * what if starting lightness > maxLightness??
   * Lightness increments by 1, but this causes RGB to increment by 4... jaggy.
   */

  // Constructor
  hue = 300;
  saturation = 100;
  minLightness = setMinLum;
  maxLightness = setMaxLum;
  lightness = minLightness;
  rgb = HslToRgb(hue, saturation, lightness);

  // A loop is 50 * 18 + 360 steps... 
  delayPerStep = int(setLoopTime * 1000.0 / 1260.0);
  state = 0;
}

Rgb SquarePattern::Update() {
  currentMillis = millis();
  if ((currentMillis - previousMillis) >= delayPerStep) {
    previousMillis = currentMillis;
    if (state == 0) {
      // brightening lightness
      lightness = lightness + 1;
      if (lightness == maxLightness)
        state = state + 1;
        
    } else if (state == 1) {
      // increasing hue at max lightness
      hue = hue + 1;
      if ((hue % 40) == 20)
        state = state + 1;
        
    } else if (state == 2) {
      // reducing lightness
      lightness = lightness - 1;
      if (lightness == minLightness)
        state = state + 1;
        
    } else if (state == 3) {
      // increasing hue at min lightness
      hue = hue + 1;
      if ((hue % 40) == 0)
        state = 0;
    }
  
    if (hue == 360)
      hue = 0;
    rgb = HslToRgb(hue, saturation, lightness);
  }
  
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

