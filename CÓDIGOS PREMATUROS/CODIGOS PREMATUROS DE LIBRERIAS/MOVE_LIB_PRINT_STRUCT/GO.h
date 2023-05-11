#ifndef GO_h
#define GO_h

#include "bingo_move_print.h"
#include "Arduino.h"
#include "POSI.h"

class GO
{
  public:
    GO();

    void UP();
    void GO_0();

    void SOLO_IR(float, float, float);
        
    void CLOSE(void);
    void OPEN(void);

    void CONV_MOV(char, int);
    
  private:

    void TOMAR_PIEZA(int);
    void COLOCAR_PIEZA(int);
    void POSICIONAR_CAM(int);
    
    bingo_move_print LLEVAR;

    float IR[3] = {};
    int o;
    
    // ESTRUCTURA DE POSICIONES      
    MPI P_PZ;
    MTB P_TB;
    MB P_CEN;
    MCAM P_CAM;

    void COPY(const float C[]);
    
};

#endif
