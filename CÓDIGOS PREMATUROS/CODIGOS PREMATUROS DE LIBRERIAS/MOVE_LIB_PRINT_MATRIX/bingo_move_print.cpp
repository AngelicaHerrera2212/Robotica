#include "bingo_move_print.h"
#include "Arduino.h"
#include <Servo.h>

bingo_move_print::bingo_move_print()
{
    INICIA();   
}

//////////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::INICIA() {

/* 
    int S1 = 10, S2 = 11, S3 = 6, S4 = 9;

    Servo BASE;
    Servo HOMBRO;
    Servo CODO;
    Servo PINZA;
    
  // ATTACH Y LIMITES
  
  // 0 ---> 180
  BASE.attach(S1);
  HOMBRO.attach(S2);
  CODO.attach(S3);
  
  // 0 ---> 110
  PINZA.attach(S4);

  // PRIMER ESCRITURA Y FUNCIONAMIENTO
  delay(500);
  
  PINZA.write(180); // CIERRA EN 110 ABRE CON 0
  delay(50);
  
  CODO.write(120); //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90 -- CERO ES DELANTE Y 90 ES DETRAS POR LO QUE FUNCIONA DETRAS HACIA ADELANTE
  delay(50);
  
  HOMBRO.write(90); // FUNCIONA NORMAL -- 0 ES DETRAS Y 180 ES DELANTE POR LO QUE VA DETRAS HACIA DELANTE
  delay(500);
  
  BASE.write(0);  //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90
  delay(50);
*/
  Serial.println("INCIANDO");
}

////////////////////////////////////////////////////////////////////////////

void bingo_move_print::ECU(float X, float Y, float Z) {
  
  X_SAVE = X;
  Y_SAVE = Y;
    
  if (X > 0){
      
    X = -X;
    Y = -Y;
    
    Q1 = atan(Y/X) + PI;
    Q2 = atan((fabs(X)*(Z*-1.08E+2+sqrt(Z*-9.2016E+4+(X*X)*Z*1.92E+2+(Y*Y)*Z*1.92E+2+(X*X)*1.5336E+4-(X*X*X*X)*1.6E+1+(Y*Y)*1.5336E+4-(Y*Y*Y*Y)*1.6E+1+(Z*Z)*1.476E+4+(Z*Z*Z)*1.92E+2-(Z*Z*Z*Z)*1.6E+1-(X*X)*(Y*Y)*3.2E+1-(X*X)*(Z*Z)*3.2E+1-(Y*Y)*(Z*Z)*3.2E+1-1.05705E+5)+3.24E+2))/(fabs(X)*-4.59E+2-Z*fabs(X)*2.4E+1+(X*X)*fabs(X)*4.0+(Y*Y)*fabs(X)*4.0+(Z*Z)*fabs(X)*4.0+X*sqrt(X*X+Y*Y)*1.08E+2))*-2.0;
    Q3 = atan((sqrt(Z*-9.2016E+4+(X*X)*Z*1.92E+2+(Y*Y)*Z*1.92E+2+(X*X)*1.5336E+4-(X*X*X*X)*1.6E+1+(Y*Y)*1.5336E+4-(Y*Y*Y*Y)*1.6E+1+(Z*Z)*1.476E+4+(Z*Z*Z)*1.92E+2-(Z*Z*Z*Z)*1.6E+1-(X*X)*(Y*Y)*3.2E+1-(X*X)*(Z*Z)*3.2E+1-(Y*Y)*(Z*Z)*3.2E+1-1.05705E+5)-9.72E+2)/(Z*-2.4E+1+(X*X)*4.0+(Y*Y)*4.0+(Z*Z)*4.0-2.97E+2))*-2.0;
    
  }
    
  else {
    
    Q1 = (atan(Y/X))*180/PI;
    Q2 = atan((fabs(X)*(Z*-1.08E+2+sqrt(Z*-9.2016E+4+(X*X)*Z*1.92E+2+(Y*Y)*Z*1.92E+2+(X*X)*1.5336E+4-(X*X*X*X)*1.6E+1+(Y*Y)*1.5336E+4-(Y*Y*Y*Y)*1.6E+1+(Z*Z)*1.476E+4+(Z*Z*Z)*1.92E+2-(Z*Z*Z*Z)*1.6E+1-(X*X)*(Y*Y)*3.2E+1-(X*X)*(Z*Z)*3.2E+1-(Y*Y)*(Z*Z)*3.2E+1-1.05705E+5)+3.24E+2))/(fabs(X)*-4.59E+2-Z*fabs(X)*2.4E+1+(X*X)*fabs(X)*4.0+(Y*Y)*fabs(X)*4.0+(Z*Z)*fabs(X)*4.0+X*sqrt(X*X+Y*Y)*1.08E+2))*-2.0;
    Q3 = atan((sqrt(Z*-9.2016E+4+(X*X)*Z*1.92E+2+(Y*Y)*Z*1.92E+2+(X*X)*1.5336E+4-(X*X*X*X)*1.6E+1+(Y*Y)*1.5336E+4-(Y*Y*Y*Y)*1.6E+1+(Z*Z)*1.476E+4+(Z*Z*Z)*1.92E+2-(Z*Z*Z*Z)*1.6E+1-(X*X)*(Y*Y)*3.2E+1-(X*X)*(Z*Z)*3.2E+1-(Y*Y)*(Z*Z)*3.2E+1-1.05705E+5)-9.72E+2)/(Z*-2.4E+1+(X*X)*4.0+(Y*Y)*4.0+(Z*Z)*4.0-2.97E+2))*-2.0;
     
  }
  /*
  Q1_G = (Q1)*180/PI;
  Q2_G = (Q2)*180/PI;
  Q3_G = (Q3)*180/PI;
  */ 
  Q1_1 = ((Q1)*180/PI)/CSTNT_GIRO;
  Q2_1 = (Q2)*180/PI;
  Q3_1 = (((Q3)*180/PI) + 180)/CSTNT_GIRO;
/*
  Serial.println("\nVALORES DE POSICION 1\n");
  Serial.println(Q1_1);
  Serial.println(Q2_1);
  Serial.println(Q3_1);
*/   
}

//////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::TRAY(){
  
  R1[0] = Q1_0;
  R2[0] = Q2_0;
  R3[0] = Q3_0;
/*
  CAM1 = (Q1_1 - Q1_0)/ PTS;
  CAM2 = (Q2_1 - Q2_0)/ PTS;
  CAM3 = (Q3_1 - Q3_0)/ PTS;
*/        
  for (j = 1; j <= PTS; j ++)
  {
    R1[j] = R1[j-1] + ((Q1_1 - Q1_0)/ PTS);
    R2[j] = R2[j-1] + ((Q2_1 - Q2_0)/ PTS);
    R3[j] = R3[j-1] + ((Q3_1 - Q3_0)/ PTS);  
  }

}

//////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::ARMWRITE(){
// TOMAR EN CUENTA QUE ESTAN RECIBIENDO DE UNO EN UNO
  if (UP){
    
    Serial.print("HOMBRO");
    Serial.print("CODO");
  
    for(b = 0; b <= PTS; b++){
            
      //HOMBRO.write(R2[b]);
      delay (50);
          
      //CODO.write(R3[b]);
      delay (50);
    }
  }
    
  else {
    Serial.print("BASE");
    for(a = 0; a <= PTS; a++){
      
      //BASE.write(R1[a]);
      delay (50);
    }
      
    Serial.print("CODO");  
    Serial.print("HOMBRO");
    
    for(b = 0; b <= PTS; b++){

      //CODO.write(R3[b]);
      delay (50);
      //HOMBRO.write(R2[b]);
      delay (50);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

void bingo_move_print::CLOSE(){
  Serial.println("PINZA PICK");
/*  
  delay (500);
  PINZA.write(0);
  delay (500);
  PINZA.write(120);
  delay (500);      
*/

}

///////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::OPEN(){
  Serial.println("PINZA PUT");
/*
  delay (500);
  PINZA.write(0);
  delay (500);
*/
}


///////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::COPY(const float C[][3], int S){

  for(o = 0; o < 3; o++){
    IR[o] = C[S][o];
    
    Serial.println(IR[o]);
  }
}

////////////////////////////////////////////////////////////////////////////

void bingo_move_print::LIFT(){

  Serial.println("LIFT");
  
  delay(100);

/*  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/
  Q1_0 = 90;
  Q2_0 = 90;
  Q3_0 = 0;
  
  delay(100);

  Q1_1 = Q1_0;
  Q2_1 = 80;
  Q3_1 = 100;

  bingo_move_print::TRAY();

  UP = true;

  bingo_move_print::ARMWRITE();

  UP = false;
}

/////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::GO_0 (){

  Serial.println("GO_0");
  
 /*  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/
  Q1_0 = 90;
  Q2_0 = 90;
  Q3_0 = 0;

  //                    X   Y   Z
  bingo_move_print::ECU(20, 0, 24);
  bingo_move_print::TRAY(); 
  bingo_move_print::ARMWRITE();

}

///////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::PLACE(float P1, float P2, float P3){

  Serial.println("PLACE");
  delay(1000);
/*  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/
  Q1_0 = 90;
  Q2_0 = 90;
  Q3_0 = 0;

  delay(100);
  
  //                    X   Y   Z
  bingo_move_print::ECU(P1, P2, P3);
  bingo_move_print::TRAY();
  bingo_move_print::ARMWRITE();  
  bingo_move_print::OPEN();
  
  delay(100);
  bingo_move_print::LIFT();
}


///////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::PICK(float P1, float P2, float P3){

  Serial.println("PICK");
  
  delay(1000);

  /*  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/
  Q1_0 = 90;
  Q2_0 = 90;
  Q3_0 = 0;

  delay(100);

  //                    X   Y   Z
  bingo_move_print::ECU(P1, P2, P3);
  bingo_move_print::TRAY();  
  bingo_move_print::ARMWRITE();  
  bingo_move_print::CLOSE();
  
  delay(100);
  bingo_move_print::LIFT();
}

//////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::POSITION(float P1, float P2, float P3){

  Serial.println("POSITION");
  
  delay(1000);

  /*  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
*/
  Q1_0 = 0;
  Q2_0 = 90;
  Q3_0 = 90;

  delay(100);

  //                    X   Y   Z
  bingo_move_print::ECU(P1, P2, P3);
  bingo_move_print::TRAY();
  bingo_move_print::ARMWRITE();  
}

///////////////////////////////////////////////////////////////////////////////////

void bingo_move_print::MOV(char MV, int PS){
    switch(MV)
    {
      case 'C':
        bingo_move_print::COPY(MCAM, PS-1);  
        bingo_move_print::POSITION(IR[0], IR[1], IR[2]);

        break;
      case 'V':
        // FALTA ESTE TIPO DE MOVIMIENTO
        
        break;
      case 'L':
        bingo_move_print::COPY(MB, 2);
        bingo_move_print::POSITION(IR[0], IR[1], IR[2]);
        break;
              
      case 'P':
        bingo_move_print::COPY(MPI, PS-1);  
        bingo_move_print::PICK(IR[0], IR[1], IR[2]);
        break;
        
      case 'T':
        bingo_move_print::COPY(MTB, PS-1);  
        bingo_move_print::PLACE(IR[0], IR[1], IR[2]);
        
        break;        
      
      default:
        Serial.println("NO ES UN TIPO DE MOVIMIENTO ADMITIDO");
        break;
    }
}
