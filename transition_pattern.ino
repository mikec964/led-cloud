#include "transition_pattern.h"

TransitionPattern::TransitionPattern(int setLoopTime, Hsl startColor, Hsl endColor) {
  // Constructor
  // for h, s, and l, calculate how much they must change
  // positive/negative values indicate increment/decrement
  hue = startColor.hue;
  saturation = startColor.saturation;
  lightness = startColor.lightness;
  endHue = endColor.hue;
  endSaturation = endColor.saturation;
  endLightness = endColor.lightness;
  
  deltaHue = (endColor.hue - startColor.hue) % 360;
  if (deltaHue > 180) { deltaHue = 360 - abs(deltaHue); }
  if (deltaHue < -180) { deltaHue = -(360 - abs(deltaHue)); }

  deltaSaturation = endColor.saturation - startColor.saturation;
  deltaLightness = endColor.lightness - startColor.lightness;

  // for each calculate how many millis between changes
  hueDelay = int(setLoopTime * 1000 / abs(deltaHue));
  saturationDelay = int(setLoopTime * 1000 / abs(deltaSaturation));
  lightnessDelay = int(setLoopTime * 1000 / abs(deltaLightness));
}

Rgb TransitionPattern::Update() {
  if ((hue == endHue) and (saturation == endSaturation) and (abs(lightness - endLightness) < 1)) { return rgb; }
//  #ifdef DEBUG_LOG
//    printHsl(hue, saturation, lightness, true);
//  #endif

  currentMillis = millis();
  if ((hue != endHue) and ((currentMillis - huePreviousMillis) >= hueDelay)) {
    huePreviousMillis = currentMillis;
    (deltaHue > 1) ? hue++ : hue--;
//    #ifdef DEBUG_LOG
//      Serial.print("................H: ");
//      printHsl(hue, saturation, lightness, true);
//    #endif
  }
  if ((saturation != endSaturation) and ((currentMillis - saturationPreviousMillis) >= saturationDelay)) {
    saturationPreviousMillis = currentMillis;
    (deltaSaturation > 1) ? saturation++ : saturation--;
//    #ifdef DEBUG_LOG
//      Serial.print("................S: ");
//      printHsl(hue, saturation, lightness, true);
//    #endif
  }
  if ((abs(lightness - endLightness) >= 1) and ((currentMillis - lightnessPreviousMillis) >= lightnessDelay)) {
    lightnessPreviousMillis = currentMillis;
    (deltaLightness > 1) ? lightness++: lightness--;
//    #ifdef DEBUG_LOG
//      Serial.print("................L: ");
//      printHsl(hue, saturation, lightness, true);
//    #endif
  }

  rgb = HslToRgb(hue, saturation, lightness);

  return rgb;
}


