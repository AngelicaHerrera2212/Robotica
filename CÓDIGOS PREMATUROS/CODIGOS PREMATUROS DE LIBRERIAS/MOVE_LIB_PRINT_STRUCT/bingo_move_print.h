#ifndef bingo_move_print_h
#define bingo_move_print_h
#include "Arduino.h"
#include <Servo.h>

class bingo_move_print
{
  public:
    
    bingo_move_print();
    
    void POSITION(float, float, float);
    void PICK(float, float, float);
    void PLACE(float, float, float);
    
    void LIFT();
    void GO_TO_0();
    
    void PINZA_PLEASE(void);
    void PINZA_NO(void);
    
  private:
    
    float Q1, Q2, Q3, Q1_G, Q2_G, Q3_G, Q1_WRI, Q2_WRI, Q3_WRI;
    float Q1_0, Q2_0, Q3_0, Q1_1, Q2_1, Q3_1, CAM1, CAM2, CAM3;
    float X, X_SAVE, X_R, Y_SAVE, Y, Y_R, Z, Z_R, K_R, CSTNT_GIRO = 1.5;
    
    int i, j, a, b, c, o;
    bool FINISH = false, CAMBIO = false, RECORRIDO = false, MOVEIT = false, UP = false;
    int PTS = 39;
    double POSI[4];
    float IR[3] = {};
    float R1[40], R2[40], R3[40];
    
    // BASE || HOMBRO || CODO || PINZA    
    int S1 = 10, S2 = 11, S3 = 6, S4 = 9;

    Servo BASE;
    Servo HOMBRO;
    Servo CODO;
    Servo PINZA;
    
    void INICIA(void);
    void ECU(float, float, float);
    void ARMWRITE(void);
    void TRAY(void);
};

#endif
