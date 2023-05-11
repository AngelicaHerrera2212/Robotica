#include "Arduino.h"
#include "notas.h"
#include "BINGO_SING.h"

BINGO_SING::BINGO_SING(int pin)
{
  pinMode (pin, OUTPUT);
  _pin = pin;
}

void BINGO_SING::play(int id)
{
  _id = id;
  
  switch(_id)
  {

    case 0:
    {
      //SONIDO DE PERDER
      
        duracion = 1000/4;
        tone(_pin, NOTE_C4, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/8;
        tone(_pin, NOTE_G3, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/8;
        tone(_pin, NOTE_G3, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/4;
        tone(_pin, NOTE_A3, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/4;
        tone(_pin, NOTE_G3, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/4;
        tone(_pin, 0, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/4;
        tone(_pin, NOTE_B3, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

        duracion = 1000/4;
        tone(_pin, NOTE_C4, duracion);
         
        silencio = duracion * 1.30;
        delay(silencio);
        noTone(_pin);

    break;
    
    }

    case 1:
    {
        for(nota = 0; nota < S0; nota++)
        {
          duracion = 1000 / F0_D[nota];
          tone(_pin, F0_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }

    case 2:
    {
        for(nota = 0; nota < S1; nota++)
        {
          duracion = 1000 / F1_D[nota];
          tone(_pin, F1_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }

    case 3:
    {
        for(nota = 0; nota < S2; nota++)
        {
          duracion = 1000 / F2_D[nota];
          tone(_pin, F2_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }

    case 4:
    {
        for(nota = 0; nota < S3; nota++)
        {
          duracion = 1000 / F3_D[nota];
          tone(_pin, F3_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }

    case 5:
    {
        for(nota = 0; nota < S4; nota++)
        {
          duracion = 1000 / F4_D[nota];
          tone(_pin, F4_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }

    case 6:
    {
        for(nota = 0; nota < S5; nota++)
        {
          duracion = 1000 / F5_D[nota];
          tone(_pin, F5_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }

    case 7:
    {
        for(nota = 0; nota < NE; nota++)
        {
          duracion = 1000 / NE_D[nota];
          tone(_pin, NE_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }
    
    case 8:
    {
        for(nota = 0; nota < LE; nota++)
        {
          duracion = 1000 / LE_D[nota];
          tone(_pin, LE_M[nota], duracion);
          
          silencio = duracion * 1.30;
          delay(silencio);
          noTone(_pin);
        }

    break;
    }
    
    default:
    {
      break;
    }
    
  }
}
