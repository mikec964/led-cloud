// Controls an RGB LED strip

// All LEDs will be the same color; they're not individually addressable

// LED strip is NOT common_anode
// Test LED IS common_anode
//#define COMMON_ANODE
#define DEBUG_LOG

// For Trinket, program with USBtinyISP
// For Arduino, program with AVR ISP

#include "hsl.h"
#include "square_pattern.h"
#include "rainbow_pattern.h"

struct Rgb rgb;
bool once = false;

// AdaFruit Trinket requires pins 4, 1, 0
const byte RED_PIN = 4;
const byte GREEN_PIN = 1;
const byte BLUE_PIN = 0;

//RainbowPattern rainbowP(10); // loop time
SquarePattern squareP(126, 25, 65); // loop time, min luminance, max luminance

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
  SetLedColor(0, 0, 0);
  for(i=0; i <= 255; i++) { SetLedColor(i, 0, 0); delay(12); }
  for(i=0; i <= 255; i++) { SetLedColor(0, i, 0); delay(12); }
  for(i=0; i <= 255; i++) { SetLedColor(0, 0, i); delay(12); }
  SetLedColor(128, 128, 128);
  delay(1000);
  SetLedColor(0, 0, 0);
  delay(500);
}

void loop() {
  if (once == false) {
    //rgb = rainbowP.Update();
    rgb = squareP.Update();
    SetLedColor(rgb.red, rgb.green, rgb.blue);
  }
  //once = true;
}

void SetLedColor(int red, int green, int blue)
{
  #ifdef DEBUG_LOG
    Serial.print("RGB: ");
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.print(blue);
    Serial.println(". ");
  #endif
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}

