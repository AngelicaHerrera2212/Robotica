#ifndef bingo_move_print_h
#define bingo_move_print_h
#include "POSI.h"
#include "Arduino.h"

class bingo_move_print
{
  public:
    
    bingo_move_print();

    void POSITION(float, float, float);
    
    void LIFT();
    void GO_0();
    
    void OPEN(void);
    void CLOSE(void);

    void MOV(char MV, int PS);
    
  private:

    void INICIA(void);
    
    void PICK(float, float, float);
    void PLACE(float, float, float);

    void COPY(const float C[][3], int);
    
    float Q1, Q2, Q3;
    float Q1_0, Q2_0, Q3_0, Q1_1, Q2_1, Q3_1;
    float X, X_SAVE, X_R, Y_SAVE, Y, Y_R, Z, Z_R, K_R, CSTNT_GIRO = 1.5;
    
    int i, j, a, b, c, o;
    bool FINISH = false, CAMBIO = false, RECORRIDO = false, MOVEIT = false, UP = false;
    int PTS = 39;
    double POSI[4];
    float IR[3] = {};
    float R1[40], R2[40], R3[40];

    
    void ECU(float, float, float);
    void ARMWRITE(void);
    void TRAY(void);

    // int S1 = 10, S2 = 11, S3 = 6, S4 = 9;
    
};

#endif
