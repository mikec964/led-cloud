#ifndef SINPATTERN_H
#define SINPATTERN_H

class SinPattern
{
  private:
    struct Rgb rgb;
    int hue;
    byte saturation;
    byte maxLuminance;
    byte minLuminance;
    byte luminance;
    int loopTime;
    byte state;

  public:
    SinPattern(int setLoopTime, int setMaxLum, int setMinLum);
    Rgb Update();
};

#endif
