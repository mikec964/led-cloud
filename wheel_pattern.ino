struct Rgb WheelPattern(int timeForLoop) {
  /* Goes around the color wheel
   *  
   *  Time is seconds to complete a 360 degree circuit
   *  It can be called as often as you'd like
   *  
   *  GOAL:
   *  This code is basically an interator. Each time it's called it returns the rgb.
   *  If enough time has passed, it returns the next calculated rgb.
   */

  struct Rgb rgb;
  
  hue = (hue + 1) % 360;
  rgb = HslToRgb(hue, 100, 50);
  delay(int(timeForLoop / 360.0 * 1000)); // 360 degrees per loop
  return rgb;
}

