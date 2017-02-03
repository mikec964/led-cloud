#ifndef TRANSITIONPATTERN_H
#define TRANSITIONPATTERN_H

class TransitionPattern
{
  /* Returns RGB values as it transitions from one HSL color to another
   *  
   *  setLoopTime is (roughly) seconds to change from one to the other
   *  Call Update() repeatedly; colors change as time passes
   *  
   */

  private:
    struct Rgb rgb;
    int hue, endHue;
    byte saturation, endSaturation;
    float lightness, endLightness;
    int deltaHue, deltaSaturation, deltaLightness;
    int hueDelay, saturationDelay, lightnessDelay;
    
    long huePreviousMillis, saturationPreviousMillis, lightnessPreviousMillis;
    long currentMillis;

  public:
    TransitionPattern(int setLoopTime, struct Hsl startColor, struct Hsl endColor);
    Rgb Update();
};

#endif

