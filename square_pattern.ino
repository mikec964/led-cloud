#include "square_pattern.h"

SquarePattern::SquarePattern(int setLoopTime, int setMinLum, int setMaxLum) {
  /* Concerns:
   * what if starting luminance > maxLum??
   * Luminance increments by 1, but this causes RGB to increment by 4... jaggy.
   */

  // Constructor
  hue = 300;
  saturation = 100;
  minLuminance = setMinLum;
  maxLuminance = setMaxLum;
  luminance = minLuminance;
  rgb = HslToRgb(hue, saturation, luminance);

  // A loop is 50 * 18 + 360 steps... 
  delayPerStep = int(setLoopTime * 1000.0 / 1260.0);
  state = 0;
}

Rgb SquarePattern::Update() {
  currentMillis = millis();
  if ((currentMillis - previousMillis) >= delayPerStep) {
    previousMillis = currentMillis;
    if (state == 0) {
      // brightening lum
      luminance = luminance + 1;
      if (luminance == maxLuminance)
        state = state + 1;
        
    } else if (state == 1) {
      // increasing hue at max lum
      hue = hue + 1;
      if ((hue % 40) == 20)
        state = state + 1;
        
    } else if (state == 2) {
      // reducing lum
      luminance = luminance - 1;
      if (luminance == minLuminance)
        state = state + 1;
        
    } else if (state == 3) {
      // increasing hue at min lum
      hue = hue + 1;
      if ((hue % 40) == 0)
        state = 0;
    }
  
    if (hue == 360)
      hue = 0;
    rgb = HslToRgb(hue, saturation, luminance);
  }
  
//  #ifdef DEBUG_LOG
//    Serial.print(F("State: "));
//    Serial.print(state);
//    Serial.print(F(". HSL: "));
//    Serial.print(hue);
//    Serial.print(F(", "));
//    Serial.print(saturation);
//    Serial.print(F(", "));
//    Serial.print(luminance);
//    Serial.print(F(". "));
//  #endif

  return rgb;
}

