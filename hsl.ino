struct Rgb HslToRgb(float hue, float saturation=100, float lightness=50) {
  /* Hue 0–360, Lightness 0-100, Saturation 0-100, returns RGB tuple
   * 
   * As lightness shifts (by 1), RGB colors shift by about 5 or 6.
   * This makes increasing brightness look bumpy.
   */

  float r, g, b;
  float q, p;
  float hue01 = hue / 360.0f;
  float sat01 = saturation / 100.0f;
  float light01 = lightness / 100.0f;
  Rgb rgb;
  Hsl hsl;

  if (sat01 == 0.0f) {
      r = g = b = light01;
  } else {
      q = light01 < 0.5f ? light01 * (1.0f + sat01) : light01 + sat01 - light01 * sat01;
      p = 2.0f * light01 - q;
      
      r = HueToRgb(p, q, hue01 + 1.0f / 3.0f);
      g = HueToRgb(p, q, hue01);
      b = HueToRgb(p, q, hue01 - 1.0f / 3.0f);
  }

//  return Rgb((int)(r * 255), (int)(g * 255), (int)(b * 255));
  rgb.red = (int)(r * 255);
  rgb.green = (int)(g * 255);
  rgb.blue = (int)(b * 255);
  return rgb;
}

static float HueToRgb(float p, float q, float t) {
    if (t < 0.0f) t += 1.0f;
    if (t > 1.0f) t -= 1.0f;
    if (t < 1.0f / 6.0f) return p + (q - p) * 6.0f * t;
    if (t < 1.0f / 2.0f) return q;
    if (t < 2.0f / 3.0f) return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
    return p;
}

#ifdef DEBUG_LOG
void printHsl (int h, int s, int l, bool eol) {
  Serial.print(F("HSL "));
  Serial.print(h);
  Serial.print(F(", "));
  Serial.print(s);
  Serial.print(F(", "));
  Serial.print(l);
  Serial.print(F(" "));
  if (eol) { Serial.println(); }
}

void printRgb (byte r, byte g, byte b, bool eol) {
  Serial.print(F("RGB "));
  Serial.print(r);
  Serial.print(F(", "));
  Serial.print(g);
  Serial.print(F(", "));
  Serial.print(b);
  Serial.print(F(" "));
  if (eol) { Serial.println(); }
}
#endif

