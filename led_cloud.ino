/* LED Cloud
 *  Controls an RGB LED strip; LEDs are not individually addressable
 */

//#define COMMON_ANODE  // Test LED IS common_anode, LED strip is NOT common_anode
//#define DEBUG_LOG

#include "hsl.h"
#include "square_pattern.h"
#include "rainbow_pattern.h"

struct Rgb rgb;
long startMillis;
byte state = 0;
const byte maxState = 3;

#if defined(IS_BEAN)
#else
  // AdaFruit Trinket requires pins 4, 1, 0
  const byte RED_PIN = 4; 
  const byte GREEN_PIN = 1;
  const byte BLUE_PIN = 0;
#endif

RainbowPattern rainbowP(60); // loop time
SquarePattern squareP(120, 15, 60); // loop time, min lightness, max lightness

void setup() {
  int i;
  
  #ifdef DEBUG_LOG
    Serial.begin(19200);
    Serial.println();
    Serial.println(F("-----"));
  #endif

  #if defined(IS_BEAN)
  #else
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
  #endif

  // quick connectivity test
  SetLedColor(0, 0, 0);
  for(i=0; i <= 255; i++) { SetLedColor(i, 0, 0); delay(12); }
  for(i=0; i <= 255; i++) { SetLedColor(0, i, 0); delay(12); }
  for(i=0; i <= 255; i++) { SetLedColor(0, 0, i); delay(12); }
  SetLedColor(128, 128, 128);
  delay(500);
  SetLedColor(0, 0, 0);
  delay(500);

  startMillis = millis();
}

void loop() {
  switch (state) {
    case 0:
      rgb = rainbowP.Update();
      SetLedColor(rgb.red, rgb.green, rgb.blue);
      state = CheckState(state, maxState, 30);
      break;
    case 1:
      SetLedColor(0, 0, 0);
      state = CheckState(state, maxState, 3);
      break;
    case 2:
      rgb = squareP.Update();
      SetLedColor(rgb.red, rgb.green, rgb.blue);
      state = CheckState(state, maxState, 60);
      break;
    case 3:
      SetLedColor(0, 0, 0);
      state = CheckState(state, maxState, 3);
      break;
  }
}

byte CheckState (byte state, byte maxState, long timeInState) {
  // state is current state
  // timeInState is seconds until state transition
  long currentMillis;
  currentMillis = millis();
  if ((currentMillis - startMillis) > (timeInState * 1000)) {
    #ifdef DEBUG_LOG
      Serial.println();
      Serial.print(F("State, cm, sm: "));
      Serial.print(state);
      Serial.print(F(", "));
      Serial.print(currentMillis);
//      Serial.print(F(", "));
//      Serial.print(startMillis);
      Serial.println();
    #endif
    startMillis = currentMillis;
    state = (state + 1) % (maxState + 1);
  }
  return state;
}

void SetLedColor(int red, int green, int blue)
{
//  #ifdef DEBUG_LOG
//    Serial.print("RGB: ");
//    Serial.print(red);
//    Serial.print(", ");
//    Serial.print(green);
//    Serial.print(", ");
//    Serial.print(blue);
//    Serial.println(". ");
//  #endif
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  
  #if defined(IS_BEAN)
    Bean.setLed(red, green, blue);
  #else
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
  #endif
}

