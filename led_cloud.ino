// Controls an RGB LED strip

// All LEDs will be the same color; they're not individually addressable

#include "LedWheel.h"
#define COMMON_ANODE

LedWheel cloud(4, 3, 2, 0); // redPin, greenPin, bluePin, initColor

void setup() {
  cloud.Update();

}

void loop() {
  delay(3000); //ms
  cloud.Update();
}

void setLedColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(4, red);
  analogWrite(3, green);
  analogWrite(2, blue);  
}

