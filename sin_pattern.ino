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
  const byte MAX_LUMINANCE = 70;
  const byte MIN_LUMINANCE = 25;

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
      
  } else if (state == 3) {
    // reducing lum
    luminance = luminance - 1;
    if (luminance == MIN_LUMINANCE)
      state = state + 1;
      
  } else if (state == 4) {
    // increasing hue at min lum
    hue = hue + 1;
    if ((hue % 40) == 0)
      state = state + 1;
  }

  if (hue == 360)
    hue = 0;
  rgb = HslToRgb(hue, 100, luminance);
  delay(int(timeForLoop / 360.0 * 1000)); // 360 degrees per loop
  return rgb;
}

