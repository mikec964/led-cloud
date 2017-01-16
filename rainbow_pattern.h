#ifndef RAINBOWPATTERN_H
#define RAINBOWPATTERN_H

class RainbowPattern
{
  private:
    struct Rgb rgb;
    int hue;
    int loopTime;

  public:
    RainbowPattern(int setLoopTime);
    Rgb Update();
};

#endif

