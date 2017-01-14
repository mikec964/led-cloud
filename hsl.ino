struct rgb_t hueWheel(int hue)
{
  // given hue 0-359, return rgb value from color wheel

  struct rgb_t rgb;
  int red, green, blue;

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
  
  rgb.red = red;
  rgb.blue = blue;
  rgb.green = green;
  return rgb;
}

