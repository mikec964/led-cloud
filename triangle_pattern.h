#ifndef TRIANGLEPATTERN_H
#define TRIANGLEPATTERN_H

class TrianglePattern
{
  /*  Returns RGB values around the color wheel while varying lightness
   *  
   *  setLoopTime is (roughly) seconds to go around the color wheel
   *  Call Update() repeatedly; colors change as time passes
   *  
   *  While lightness increases to max, hue increases, 
   *  Then while lightness decreases to min, hue increases
   */

  private:
    struct Rgb rgb;
    int hue;
    byte saturation;
    byte minLightness;
    byte maxLightness;
    float lightness;
    const int waveWidth = 20;
    int loopSteps;
    
    byte state;
    long previousMillis;
    long currentMillis;
    int delayPerStep;

  public:
    TrianglePattern(int setLoopTime, int setMinLightness, int setMaxLightness);
    Rgb Update();
};

#endif

