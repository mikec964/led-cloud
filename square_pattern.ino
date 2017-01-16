#include "square_pattern.h"

SquarePattern::SquarePattern(int setLoopTime, int setMinLum, int setMaxLum) {
  /* Goes around the color wheel, varies luminance
   *  
   *  Time is seconds to complete a 360 degree circuit
   *  It can be called as often as you'd like
   *  
   *  Go from dim to bright on hue,
   *  increment hue,
   *  go from bright to dim
   *  increment hue
   *  
   *  GOAL:
   *  This code is basically an interator. Each time it's called it returns the rgb.
   *  If enough time has passed, it returns the next calculated rgb.
   */

// what if starting luminance > maxLum??

  // Constructor
  hue = 300;
  saturation = 100;
  minLuminance = setMinLum;
  maxLuminance = setMaxLum;
  luminance = minLuminance;
  loopTime = setLoopTime;
  state = 0;
}

Rgb SquarePattern::Update() {
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
  #ifdef DEBUG_LOG
    Serial.print(F("State: "));
    Serial.print(state);
    Serial.print(F(". HSL: "));
    Serial.print(hue);
    Serial.print(F(", "));
    Serial.print(saturation);
    Serial.print(F(", "));
    Serial.print(luminance);
    Serial.print(F(". "));
  #endif

  // A loop is 50 * 18 + 360 steps... 
  delay(int(loopTime / 1260.0 * 1000)); // 360 degrees per loop
  return rgb;
}

