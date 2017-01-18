#ifndef SQUAREPATTERN_H
#define SQUAREPATTERN_H

class SquarePattern
{
  /* Returns RGB values around the color wheel while varying lightness
   *  
   *  setLoopTime is (roughly) seconds to go around the color wheel
   *  Call Update() repeatedly; colors change as time passes
   *  
   *  Go from dim to bright,
   *  change hue,
   *  go from bright to dim
   *  change hue.
   */

  private:
    struct Rgb rgb;
    int hue;
    byte saturation;
    byte maxLightness;
    byte minLightness;
    byte lightness;
    
    byte state;
    long previousMillis;
    long currentMillis;
    int delayPerStep;

  public:
    SquarePattern(int setLoopTime, int setMaxLum, int setMinLum);
    Rgb Update();
};

#endif

