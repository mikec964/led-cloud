// Controls an RGB LED strip

// All LEDs will be the same color; they're not individually addressable

// LED strip is NOT common_anode
// Test LED IS common_anode
//#define COMMON_ANODE
#define DEBUG_LOG

// For Trinket, program with USBtinyISP
// For Arduino, program with AVR ISP

#include "hsl.h"
#include "sin_pattern.h"
#include "wheel_pattern.h"

struct Rgb rgb;
bool once = false;

// AdaFruit Trinket requires pins 4, 1, 0
const byte RED_PIN = 4;
const byte GREEN_PIN = 1;
const byte BLUE_PIN = 0;

WheelPattern wheelP(10); // loop time
//SinPattern sinP(126, 25, 65); // loop time, min luminance, max luminance

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
    rgb = wheelP.Update();
    //rgb = sinP.Update();
    SetLedColor(rgb.red, rgb.green, rgb.blue);
    
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
  //once = true;
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


