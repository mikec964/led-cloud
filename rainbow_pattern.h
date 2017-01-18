#ifndef RAINBOWPATTERN_H
#define RAINBOWPATTERN_H

class RainbowPattern
{
   /* Returns RGB values around the color wheel
   *  
   *  setLoopTime is (roughly) seconds to go around the color wheel
   *  Call Update() repeatedly; colors change as time passes
   */

  private:
    struct Rgb rgb;
    int hue;

    long previousMillis;
    long currentMillis;
    int delayPerStep;

  public:
    RainbowPattern(int setLoopTime);
    Rgb Update();
};

#endif

