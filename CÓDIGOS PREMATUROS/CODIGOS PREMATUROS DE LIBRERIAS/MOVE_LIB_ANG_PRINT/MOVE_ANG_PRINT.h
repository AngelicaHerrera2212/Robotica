#ifndef MOVE_ANG_PRINT_h
#define MOVE_ANG_PRINT_h

#include "Arduino.h"

#include <Servo.h>

class MOVE_ANG_PRINT
{
  public:
    
    MOVE_ANG_PRINT();
    
    void INICIA(int, int, int, int);

    void JUST_GO(float, float, float); 
    void LLEVAR(float, float, float, float, float, float);
       
    void GO_TO_0 (void);

    void CLOSE(void);
    void OPEN(void);
    void LIFT(void);

  private:

      float Q1_0, Q2_0, Q3_0, Q1_1, Q2_1, Q3_1;
      bool UP = false;
      int PTS = 39;
      double POSI[4];
      float R1[40], R2[40], R3[40];
      
      // BASE || HOMBRO || CODO || PINZA      
      // int A1 = 10, A2 = 11, A3 = 6, A4 = 9;
      
      Servo BASE;
      Servo HOMBRO;
      Servo CODO;
      Servo PINZA;
      
      void TRAY(void);
      void ARMWRITE(void);
           
};

#endif
