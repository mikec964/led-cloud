// Controls an RGB LED strip

// All LEDs will be the same color; they're not individually addressable

//#include "LedWheel.h"
#define COMMON_ANODE

//#define DEBUG_LOG

//LedWheel cloud(4, 3, 2, 0); // redPin, greenPin, bluePin, initColor

struct rgb_t {
  byte red;
  byte green;
  byte blue;
} rgb;
int hue = 0;

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

