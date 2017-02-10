#ifndef HSL_H_
#define HSL_H_

struct Rgb {
  byte red;
  byte green;
  byte blue;
};

struct Hsl {
  int hue;
  float saturation;
  float lightness;
};

struct Rgb HslToRgb(int hue, float saturation, float lightness); //prototype
  /* Hue 0–359, Saturation 0-100, Lightness 0-100, returns RGB tuple
   * 
   * As lightness shifts (by 1), RGB colors shift by about 5 or 6.
   * This makes increasing brightness look bumpy.
   */

#endif

// From http://hslpicker.com
// and http://www.w3schools.com/colors/colors_hex.asp
// red        = {0, 100, 50};
// orange     = {39, 100, 50};
// yellow     = {60, 100, 50};
// green      = {120, 100, 25};
// lime       = {120, 100, 50};
// cyan       = {180, 100, 50};
// blue       = {240, 100, 50};
// navy       = {240, 100, 25};
// rebeccapurple = {270, 50, 40};
// purple      = {300, 100, 25};
// magenta     = {300, 100, 50};

