#ifndef SQUAREPATTERN_H
#define SQUAREPATTERN_H

class SquarePattern
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
    SquarePattern(int setLoopTime, int setMaxLum, int setMinLum);
    Rgb Update();
};

#endif
