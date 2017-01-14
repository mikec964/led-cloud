// Controls an RGB LED strip

// All LEDs will be the same color; they're not individually addressable

#define COMMON_ANODE
//#define DEBUG_LOG

#include "hsl.h"

struct rgb_t rgb;
int hue = 0;

// AdaFruit Trinket requires pins 4, 1, 0
const byte RED_PIN = 4;
const byte GREEN_PIN = 1;
const byte BLUE_PIN = 0;

void setup() {
  int i;
  
  #ifdef DEBUG_LOG
    Serial.begin(9600);
    Serial.println();
    Serial.println("-----");
  #endif

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // quick connectivity test
  for(i=0; i <= 255; i++) { setLedColor(i, 0, 0); delay(24); }
  for(i=0; i <= 256; i++) { setLedColor(0, i, 0); delay(24); }
  for(i=0; i <= 255; i++) { setLedColor(0, 0, i); delay(24); }
  setLedColor(128, 128, 128);
  delay(1000);
  setLedColor(0, 0, 0);
  delay(1000);
}

void loop() {
  rgb = hueWheel(hue);
  setLedColor(rgb.red, rgb.green, rgb.blue);
  delay(27); // .027 seconds. 10 seconds per loop around color wheel
  #ifdef DEBUG_LOG
    Serial.print(F("Hue: "));
    Serial.print(hue);
    Serial.print(": ");
    Serial.print(rgb.red);
    Serial.print(", ");
    Serial.print(rgb.green);
    Serial.print(", ");
    Serial.println(rgb.blue);
  #endif
  hue = (hue + 1) % 360;
}

void setLedColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}


