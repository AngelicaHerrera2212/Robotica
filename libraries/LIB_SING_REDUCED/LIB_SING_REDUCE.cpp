#include "Arduino.h"
#include "notas.h"
#include "LIB_SING_REDUCE.h"

LIB_SING_REDUCE::LIB_SING_REDUCE()
{
  pinMode (5, OUTPUT);
  _pin = 5;
}

void LIB_SING_REDUCE::play(int id)
{
  
  _id = id;
  
  switch(_id)
  {

    case 0:
    { //SONIDO DE PERDER
      
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
    {  // SONIDO PARA FASE_0
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_DS4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_DS4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_DS4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_AS3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_DS4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;
    }

    case 2:
    { // SONIDO FASE 1
    
      duracion = 1000 / 2;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 2;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 2;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;
    }

    case 3:
    { // SONIDO FASE 2
    
      duracion = 1000 / 2;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 2;
      tone(_pin, NOTE_A4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 2;
      tone(_pin, NOTE_C5, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;
    }

    case 4:
    {  // SONIDO FASE 3

      duracion = 1000 / 3;
      tone(_pin, NOTE_A3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 6;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 3;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 3;
      tone(_pin, NOTE_A4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 1;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 1;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 6;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 3;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_CS4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 3;
      tone(_pin, NOTE_DS4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 1;
      tone(_pin, NOTE_A3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;
    }

    case 5:
    {   // SONIDO FASE 4
    
      duracion = 1000 / 2;
      tone(_pin, NOTE_C3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_E3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_G3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;

    }

    case 6:
    {   // SONIDO FASE 5
    
      duracion = 1000 / 8;
      tone(_pin, NOTE_B3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_B3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_B3, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_B4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_B4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_B4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
 
      
      break;
    
    }

    case 7:
    { // SONIDO NO EXISTE
      
      duracion = 1000 / 2;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 4;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 2;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;
    }
    
    case 8:
    {   // SONIDO LEIDO  
    
      duracion = 1000 / 8;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      duracion = 1000 / 8;
      tone(_pin, NOTE_A4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_A4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 4;
      tone(_pin, NOTE_G4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_F4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_E4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 8;
      tone(_pin, NOTE_D4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);
      
      duracion = 1000 / 4;
      tone(_pin, NOTE_C4, duracion);
          
      silencio = duracion * 1.30;
      delay(silencio);
      noTone(_pin);

      break;
    }
    
    default:
    {
      break;
    }
    
  }
}
