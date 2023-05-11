#ifndef LIB_SING_REDUCE_h
#define LIB_SING_REDUCE_h
#include "Arduino.h"

class LIB_SING_REDUCE
{
  public:
    LIB_SING_REDUCE(int pin);
    void play(int id);

  private:
    int _pin, _id;
    int nota, silencio, duracion;

};

#endif
