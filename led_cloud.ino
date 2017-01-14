// Controls an RGB LED strip

// All LEDs will be the same color; they're not individually addressable

#define COMMON_ANODE
//#define DEBUG_LOG

#include "hsl.h"

struct Rgb rgb;
int hue = 0;
byte saturation = 100;
byte luminance = 50;
bool once = false;

// AdaFruit Trinket requires pins 4, 1, 0
const byte RED_PIN = 4;
const byte GREEN_PIN = 1;
const byte BLUE_PIN = 0;

void setup() {
  int i;
  
  #ifdef DEBUG_LOG
    Serial.begin(9600);
    Serial.println();
    Serial.println(F("-----"));
  #endif

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // quick connectivity test
  for(i=0; i <= 255; i++) { SetLedColor(i, 0, 0); delay(24); }
  for(i=0; i <= 255; i++) { SetLedColor(0, i, 0); delay(24); }
  for(i=0; i <= 255; i++) { SetLedColor(0, 0, i); delay(24); }
  SetLedColor(128, 128, 128);
  delay(1000);
  SetLedColor(0, 0, 0);
  delay(1000);
}

void loop() {
  if (once == false) {
    for(hue = 0; hue <= 359; hue = hue + 20) {
      for(luminance = 0; luminance <= 100; luminance = luminance + 5) {
        rgb = HslToRgb(hue, saturation, luminance);
        SetLedColor(rgb.red, rgb.green, rgb.blue);
        delay(27); // .027 seconds. 10 seconds per loop around color wheel
        #ifdef DEBUG_LOG
          Serial.print("RGB: ");
          Serial.print(rgb.red);
          Serial.print(", ");
          Serial.print(rgb.green);
          Serial.print(", ");
          Serial.print(rgb.blue);
          Serial.println(". ");
        #endif  
      }
    }
    once = true;
  }
  //hue = (hue + 1) % 360;
  //luminance = (luminance + 5) % 101;
}

void SetLedColor(int red, int green, int blue)
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


