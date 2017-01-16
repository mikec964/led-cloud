struct Rgb HslToRgb(int hue, byte saturation, byte luminance)
{
  /* Hue 0–359, Luminance 0-100, Saturation 0-100, returns RGB tuple
   * 
   * Usually use saturation 100, luminance 50
   * 
   * As luminance shifts (by 1), RGB colors shift by about 5 or 6.
   * This makes increasing brightness look bumpy.
   */

  struct Rgb rgb;
  byte red, green, blue;

//  #ifdef DEBUG_LOG
//    Serial.print(F("HSL "));
//    Serial.print(hue);
//    Serial.print(F(", "));
//    Serial.print(saturation);
//    Serial.print(F(", "));
//    Serial.print(luminance);
//    Serial.print(F(". "));
//  #endif

  // Calc based on luminance = 50
  if(hue < 60) {
    red = 255; blue = 0; // count green
    green = int(255 * hue / 60);
  } else if (hue < 120) {
    green = 255; blue = 0; // countdown red
    red = 255 - int(255 * (hue - 60) / 60);
  } else if (hue < 180) {
    red = 0; green = 255; // count blue
    blue = int(255 * (hue - 120) / 60);
  } else if (hue < 240) {
    red = 0; blue = 255; // countdown green
    green = 255 - int(255 * (hue - 180) / 60);
  } else if (hue < 300) {
    green = 0; blue = 255; // count red
    red = int(255 * (hue - 240) / 60);
  } else {
    red = 255; green = 0; // countdown blue
    blue = 255 - int(255 * (hue - 300) / 60);
  }

  red = AdjustLuminance(red, luminance);
  green = AdjustLuminance(green, luminance);
  blue = AdjustLuminance(blue, luminance);

  rgb.red = AdjustSaturation(red, saturation);
  rgb.green = AdjustSaturation(green, saturation);
  rgb.blue = AdjustSaturation(blue, saturation);
 
  return rgb;
}

int AdjustLuminance (int color, byte luminance) {
  /* color = 0-255, luminance = 0-100
   *  
   * If luminance is 50, leave color alone.
   * If luminance > 50, adjust color toward 255.
   * If luminance < 50, adjust color toward 0.
   */

  float factor, dist, adjust;

  // If luminance > 50, blend RGB to white (255)
  factor = (luminance - 50.0) / 50.0; // What % should we go? (positive means up)
  if (luminance > 50)
    dist = 255 - color; // Blend toward white?
  else
    dist = color; // How far from 0?
  adjust = dist * factor; // scale dist by factor

//  #ifdef DEBUG_LOG
//    Serial.print(F("factor, dist, adjust: "));
//    Serial.print(factor);
//    Serial.print(F(", "));
//    Serial.print(dist);
//    Serial.print(F(", "));
//    Serial.print(adjust);
//    Serial.print(F(". "));
//  #endif
  
  color = color + adjust;
  return color;
}

int AdjustSaturation (int color, byte saturation) {
  /* color = 0-255, saturation= 0-100
   *  
   * If saturation is 100, leave color alone.
   * As saturation approaches 0, adjust color to 128.
   */

   return color;
}

