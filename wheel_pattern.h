#ifndef WHEELPATTERN_H
#define WHEELPATTERN_H

class WheelPattern
{
  private:
    struct Rgb rgb;
    int hue;
    int loopTime;

  public:
    WheelPattern(int setLoopTime);
    Rgb Update();
};

#endif

