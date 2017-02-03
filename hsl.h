#ifndef HSL_H
#define HSL_H

struct Rgb {
  byte red;
  byte green;
  byte blue;
};

struct Hsl {
    int hue;
    byte saturation;
    float lightness;
};

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

