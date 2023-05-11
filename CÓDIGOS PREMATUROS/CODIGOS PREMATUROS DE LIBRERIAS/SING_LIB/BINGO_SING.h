#ifndef BINGO_SING_h
#define BINGO_SING_h

#include "notas.h"
#include "Arduino.h"

class BINGO_SING
{
  public:
    BINGO_SING(int pin);
    void play(int id);

  private:
    int _pin, _id;
    int nota, silencio, duracion;
    
    // size de las melodias
    int SL = 8;
    int NE = 12;
    int LE = 14;
    int S0 = 8;
    int S1 = 3;
    int S2 = 3;
    int S3 = 14;
    int S4 = 4;
    int S5 = 22;
    
    // notes in the melody:
    int L_M[8] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};              // SONIDO PERDER
    int NE_M[12] = { NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4}; // SONIDO NO EXISTE
    int LE_M[14] = {NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4};    // SONIDO LEIDO    
    int F0_M[8] = { NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_G4};  // SONIDO FASE 0
    int F1_M[3] = { NOTE_C4, NOTE_E4, NOTE_G4};                                                    // SONIDO FASE 1
    int F2_M[3] = { NOTE_F4, NOTE_A4, NOTE_C5};                                                    // SONIDO FASE 2
    int F3_M[14] = { NOTE_A3, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_CS4, NOTE_DS4, NOTE_A3};  // SONIDO FASE 3
    int F4_M[4] = { NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4};                                           // SONIDO FASE 4
    int F5_M[22] = { NOTE_B3, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_B4, NOTE_B4, NOTE_B4};  // SONIDO FASE 5
        
    
    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int L_D[8] = {4, 8, 8, 4, 4, 4, 4, 4};                     // DURACION SONIDO PERDER
    int NE_D[12] = {2, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2};       // DURACION SONIDO NO EXISTE
    int LE_D[14] = {8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4}; // DURACION SONIDO LEIDO
    
    int F0_D[8] = {8, 8, 8, 8, 8, 8, 4, 2};                    // DURACION SONIDO FASE 0
    int F1_D[3] = {2, 2, 2};                                   // DURACION SONIDO FASE 1-2
    int F2_D[3] = {2, 2, 2};
    int F3_D[14] = {3, 2, 6, 3, 2, 3, 1, 1, 2, 6, 3, 2, 3, 1};  // DURACION SONIDO FASE 3
    int F4_D[4] = {2, 2, 2, 2};                                // DURACION SONIDO FASE 4
    int F5_D[22] = {8, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 4, 8, 8, 4, 8, 8, 4, 4, 2};  // DURACION SONIDO FASE 5
    
};

#endif
