#include "MOVE_ANG_PRINT.h"
#include "Arduino.h"
#include <Servo.h>

MOVE_ANG_PRINT::MOVE_ANG_PRINT()
{

}

//////////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::INICIA(int S1, int S2, int S3, int S4) {
  
  // ATTACH Y LIMITES
  
  // 0 ---> 180
  BASE.attach(S1);
  HOMBRO.attach(S2);
  CODO.attach(S3);
  
  // 0 ---> 110
  PINZA.attach(S4);
  
  // PRIMER ESCRITURA Y FUNCIONAMIENTO
  delay(500);
  
  OPEN();
  //PINZA --- CIERRA EN 110 ABRE CON 0  LOS LIMITES SON 20 Y 65
  
  MOVE_ANG_PRINT::JUST_GO(0, 90, 120); 
  
  //CODO ---- FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90 -- CERO ES DELANTE Y 90 ES DETRAS POR LO QUE FUNCIONA DETRAS HACIA ADELANTE
  //HOMBRO --- FUNCIONA NORMAL -- 0 ES DETRAS Y 180 ES DELANTE POR LO QUE VA DETRAS HACIA DELANTE
  //BASE --- FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90
  
}


//////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::TRAY(){

 float CAM1, CAM2, CAM3;
  
  R1[0] = Q1_0;
  R2[0] = Q2_0;
  R3[0] = Q3_0;

  CAM1 = (Q1_1 - Q1_0)/ PTS;
  CAM2 = (Q2_1 - Q2_0)/ PTS;
  CAM3 = (Q3_1 - Q3_0)/ PTS;
        
  for (int j = 1; j <= PTS; j ++)
  {
    R1[j] = R1[j-1] + CAM1;
    R2[j] = R2[j-1] + CAM2;
    R3[j] = R3[j-1] + CAM3;  
  }

}

//////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::ARMWRITE(){

  int a, b;

// TOMAR EN CUENTA QUE ESTAN RECIBIENDO DE UNO EN UNO
  if (UP){
    for(b = 0; b <= PTS; b++){
      Serial.print("HOMBRO: ");
      Serial.println(R2[b]);
      //HOMBRO.write(R2[b]);
      delay (50);
      Serial.print("CODO: ");
      Serial.println(R3[b]);
      //CODO.write(R3[b]);
      delay (50);
    }
  }
    
  else {
    for(a = 0; a <= PTS; a++){
      //BASE.write(R1[a]);
      delay (50);
      Serial.print("BASE: ");
      Serial.println(R1[a]);
    }
      
    for(b = 0; b <= PTS; b++){
      Serial.print("CODO: ");
      Serial.println(R3[b]);
      //CODO.write(R3[b]);
      delay (50);
      Serial.print("HOMBRO: ");
      Serial.println(R2[b]);
      //HOMBRO.write(R2[b]);
      delay (50);
    }
  }
}


///////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::CLOSE(){
  
  delay (100);
  Serial.println("CLOSE PINZA");

  int i = 65;
  int j = 0;

  j = i;
  
  if(i < 20){
    
    while(j < 21)
    {
      //PINZA.write(i);
      
      delay (100);
      Serial.print("PINZA: ");
      Serial.println(j);

      j++;
    }
  }
  
  else{
    
    while(j > 19)
    {
      //PINZA.write(i);
      delay (100);
      Serial.print("PINZA: ");
      Serial.println(j);

      j--;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::OPEN(){
  
  delay (100);
  Serial.println("OPEN PINZA");

//  int i = PINZA.read();
  
  int i = 20;
  int j = 0;

  j = i;
  
  if(i > 65){
    
    while(j > 64)
    {
      //PINZA.write(i);
      delay (100);
      Serial.println("PINZA: ");
      Serial.println(j);

      j--;
    }
  }
  
  else{
    
    while(j < 66)
    {
      //PINZA.write(i);
      delay (100);
      Serial.println("PINZA: ");
      Serial.println(j);

      j++;
    }
  }
}

////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::LIFT(){

  delay (100);
  Serial.println("UP");
  
  delay(100);
/*
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/

  Q1_0 = 75;
  Q2_0 = 80;
  Q3_0 = 25;
  
  delay(100);

  Q1_1 = Q1_0;
  Q2_1 = 80;
  Q3_1 = 100;

  MOVE_ANG_PRINT::TRAY();

  UP = true;

  MOVE_ANG_PRINT::ARMWRITE();

  UP = false;
}

//////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::GO_TO_0 (){

  delay (100);
  Serial.println("GO TO 0");
/*
  
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/

  Q1_0 = 75;
  Q2_0 = 80;
  Q3_0 = 25;
  
  Q1_1 = 90;
  Q2_1 = 120;
  Q3_1 = 90;

  MOVE_ANG_PRINT::TRAY();  
  MOVE_ANG_PRINT::ARMWRITE();  
}

/////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::JUST_GO (float Q1, float Q2, float Q3){
  
  delay (100);
  Serial.println("JUST GO");
/*
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/

  Q1_0 = 75;
  Q2_0 = 80;
  Q3_0 = 25;

  if(Q1_0 != Q1 || Q2_0 != Q2 || Q3_0 != Q3)
  {
    Q1_1 = Q1;
    Q2_1 = Q2;
    Q3_1 = Q3;
  
    MOVE_ANG_PRINT::TRAY(); 
    MOVE_ANG_PRINT::ARMWRITE(); 
  }

}

///////////////////////////////////////////////////////////////////////////////////

void MOVE_ANG_PRINT::LLEVAR(float Q1, float Q2, float Q3, float Q4, float Q5, float Q6){
  
//  Serial.println("PICK");
  
  delay(100);
/*
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/

  Q1_0 = 75;
  Q2_0 = 80;
  Q3_0 = 25;
  
  delay(100);

  Q1_1 = Q1;
  Q2_1 = Q2;
  Q3_1 = Q3;
  
  MOVE_ANG_PRINT::TRAY();
  MOVE_ANG_PRINT::ARMWRITE();  
  MOVE_ANG_PRINT::CLOSE();

///////////////////////////////////
  
  MOVE_ANG_PRINT::LIFT();

//  Serial.println("PLACE");

  delay(100);
/*
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/

  Q1_0 = 75;
  Q2_0 = 80;
  Q3_0 = 25;
  
  delay(100);
  
  Q1_1 = Q4;
  Q2_1 = Q5;
  Q3_1 = Q6;

  MOVE_ANG_PRINT::TRAY();
  MOVE_ANG_PRINT::ARMWRITE();  
  MOVE_ANG_PRINT::OPEN();

////////////////////////////////
  
  MOVE_ANG_PRINT::LIFT();
  MOVE_ANG_PRINT::GO_TO_0();

}

/////////////////////////////////////////////////////////////////////////////////
