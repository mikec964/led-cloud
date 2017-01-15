struct Rgb SinPattern(int timeForLoop) {
  /* Goes around the color wheel, varies luminance
   *  
   *  Time is seconds to complete a 360 degree circuit
   *  It can be called as often as you'd like
   *  
   *  Go from dim (25) to bright (70) on hue,
   *  increment hue,
   *  go from bright to dim
   *  increment hue
   *  
   *  GOAL:
   *  This code is basically an interator. Each time it's called it returns the rgb.
   *  If enough time has passed, it returns the next calculated rgb.
   */

  struct Rgb rgb;
  const byte MAX_LUMINANCE = 75;
  const byte MIN_LUMINANCE = 25;
  const byte saturation = 100;

  if (state == 0) {
    // brightening lum
    luminance = luminance + 1;
    if (luminance == MAX_LUMINANCE)
      state = state + 1;
      
  } else if (state == 1) {
    // increasing hue at max lum
    hue = hue + 1;
    if ((hue % 40) == 20)
      state = state + 1;
      
  } else if (state == 2) {
    // reducing lum
    luminance = luminance - 1;
    if (luminance == MIN_LUMINANCE)
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
  delay(int(timeForLoop / 1260.0 * 1000)); // 360 degrees per loop
  return rgb;
}

