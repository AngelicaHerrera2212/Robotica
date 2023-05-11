#include <Servo.h>

float Q1, Q2, Q3, Q1_G, Q2_G, Q3_G, Q1_WRI, Q2_WRI, Q3_WRI;
float Q1_0, Q2_0, Q3_0, Q1_1, Q2_1, Q3_1, CAM1, CAM2, CAM3;
float X, X_SAVE, X_R, Y_SAVE, Y, Y_R, Z, Z_R, CSTNT_GIRO = 1.5;

int i, j, a, b, c, IDX;
String VAL = "";
bool UP = false;
const char SEP = ',';
const int CANT = 4, PTS = 39, SIZE = PTS + 1;
double POSI[CANT];

float R1[SIZE], R2[SIZE], R3[SIZE];

// BASE || HOMBRO || CODO || PINZA

int S1 = 10, S2 = 11, S3 = 6, S4 = 9;

Servo BASE;
Servo HOMBRO;
Servo CODO;
Servo PINZA;

//
void INICIA(void);

//
void ECU(float, float, float);
void ARMWRITE(void);
void TRAY(void);
void PINZA_PLEASE(void);
void PINZA_NO(void);



void IR_A_INICIO();
void PICK(float, float, float);
void PLACE(float, float, float);
void LIFT(float, float, float);

//POSICION 0 DE MOVIMIENTO
float POS_1
[] = {20, 0, 24};
float POS_0 [] = {19, -2, 16};

// POSIBLES POSICIONES DE LAS PIEZAS

// PIEZAS_BINGO_#
float P_B_1 [] = {13.5, -26.25, 5.75};
float P_B_2 [] = {15.75, -24.25, 5.75};
float P_B_3 [] = {18.25, -22.25, 5.75};
float P_B_4 [] = {20.75, -20.25, 5.75};
float P_B_5 [] = {22, -18.5, 5.75};

// POSISION DEL BASO
// PLANCHA_BINGO_POSICION_#
float PL_BASO_1 [] = {19, -2, 16};


float PL_B_P_26 [] = {27.75, 1.25, 7.5};
float PL_B_P_27 [] = {26.25, 1.25, 7};
float PL_B_P_28 [] = {25.25, 1.25, 6.5};
float PL_B_P_29 [] = {23.75, 1, 6.5};
float PL_B_P_30 [] = {22.25, 1.1, 6};

float PL_B_P_31 [] = {27.75, -0.75, 7.5};
float PL_B_P_32 [] = {26.25, -0.75, 7};
float PL_B_P_33 [] = {25.25, -0.75, 6.5};
float PL_B_P_34 [] = {23.75, -1, 6.5};
float PL_B_P_35 [] = {22.25, -0.9, 6};

float PL_B_P_36 [] = {27.75, -2.75, 7.5};
float PL_B_P_37 [] = {26.5, -2.75, 7};
float PL_B_P_38 [] = {25.5, -2.6, 6.75};
float PL_B_P_39 [] = {24, -3, 6.5};
float PL_B_P_40 [] = {22.75, -3, 6};

float PL_B_P_41 [] = {28, -4.75, 7.75};
float PL_B_P_42 [] = {26.5, -4.75, 7};
float PL_B_P_43 [] = {25.5, -4.75, 6.75};
float PL_B_P_44 [] = {24, -5, 6.5};
float PL_B_P_45 [] = {22.75, -5, 6};

float PL_B_P_46 [] = {28, -6, 7.75};
float PL_B_P_47 [] = {26.75, -6.3, 7.75};
float PL_B_P_48 [] = {25.5, -6.5, 7.5};
float PL_B_P_49 [] = {24.5, -6.75, 7.5};
float PL_B_P_50 [] = {23.5, -6.75, 6.75};

//

float PL_B_P_1 [] = {26.25, 11, 9};
float PL_B_P_2 [] = {25.25, 11.25, 9};
float PL_B_P_3 [] = {24, 11.5, 8.75};
float PL_B_P_4 [] = {22.5, 11.5, 8};
float PL_B_P_5 [] = {21.75, 11.75, 8};

float PL_B_P_6 [] = {27, 9.25, 10.25};
float PL_B_P_7 [] = {25.5, 9.75, 9.5};
float PL_B_P_8 [] = {24.5, 10, 9.25};
float PL_B_P_9 [] = {23.5, 10, 8.75};
float PL_B_P_10 [] = {22, 10.25, 8.5};

float PL_B_P_11 [] = {27, 7.5, 10};
float PL_B_P_12 [] = {26.25, 8, 9.5};
float PL_B_P_13 [] = {25, 8, 9.25};
float PL_B_P_14 [] = {23.5, 8.25, 8.75};
float PL_B_P_15 [] = {22.5, 7.75, 8.5};

float PL_B_P_16 [] = {27.25, 5.75, 10};
float PL_B_P_17 [] = {26.5, 5.75, 9.5};

float PL_B_P_18 [] = {25.25, 6.25, 9.25};
float PL_B_P_19 [] = {23.75, 6, 9};

float PL_B_P_20 [] = {22, 6.25, 8.5};

float PL_B_P_21 [] = {27, 7.5, 10};
float PL_B_P_22 [] = {26.25, 8, 9.5};
float PL_B_P_23 [] = {25, 8, 9.25};
float PL_B_P_24 [] = {23.5, 8.25, 8.75};
float PL_B_P_25 [] = {22.5, 7.75, 8.5};



void setup() {

  INICIA();
  delay (2000);

  IR_A_INICIO();
  LIFT();
  PINZA_PLEASE();
 
  PICK(PL_B_P_34[0], PL_B_P_34[1], PL_B_P_34[2]);

//  LIFT();

}


void loop() {
  // put your main code here, to run repeatedly:

}


///////////////////////////////////////////////////////////////////////////////////

void PLACE(float P1, float P2, float P3){
  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
  
  ECU(P1, P2, P3);
  
  ARMWRITE();

  delay (100);
  
  PINZA_NO();
}

///////////////////////////////////////////////////////////////////////////////////

void PICK(float P1, float P2, float P3){
  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
  
  ECU(P1, P2, P3);
  
  Serial.println("POSICIONES INICIALES");
  Serial.print("Q1: "); Serial.println(Q1_0);
  Serial.print("Q2: "); Serial.println(Q2_0);
  Serial.print("Q3: "); Serial.println(Q3_0);

  Serial.println("POSICIONES FINALES");
  Serial.print("Q1: "); Serial.println(Q1_1);
  Serial.print("Q2: "); Serial.println(Q2_1);
  Serial.print("Q3: "); Serial.println(Q3_1);
  
  ARMWRITE();

  delay (100);
  
  PINZA_PLEASE();

}

///////////////////////////////////////////////////////////////////////////////////

void LIFT(){
  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
  
  Q1_1 = Q1_0;
  Q2_1 = 90;
  Q3_1 = 120;

  TRAY();
  
  UP = true;
  
  ARMWRITE();

  UP = false;
}

///////////////////////////////////////////////////////////////////////////////////

void IR_A_INICIO(){

  delay (100);
  
  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();
  
  ECU(POS_0[0], POS_0[1], POS_0[2]);

  ARMWRITE();
  PINZA_PLEASE();

}

//////////////////////////////////////////////////////////////////////////////////////

void INICIA() {
// ATTACH Y LIMITES

  // 0 ---> 180
  BASE.attach(S1);
  HOMBRO.attach(S2);
  CODO.attach(S3);
  
  // 0 ---> 110
  PINZA.attach(S4);

  // PRIMER ESCRITURA Y FUNCIONAMIENTO
  delay(500);
  
  PINZA.write(0); // CIERRA EN 110 ABRE CON 0
  delay(50);
  
  CODO.write(120); //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90 -- CERO ES DELANTE Y 90 ES DETRAS POR LO QUE FUNCIONA DETRAS HACIA ADELANTE
  delay(50);
  
  HOMBRO.write(90); // FUNCIONA NORMAL -- 0 ES DETRAS Y 180 ES DELANTE POR LO QUE VA DETRAS HACIA DELANTE
  delay(50);
  
  BASE.write(0);  //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90
  delay(50);
  
  Serial.begin(9600);
}

////////////////////////z////////////////////////////////////////////////////

void ECU(float X, float Y, float Z) {

  if (X > 0){
  
    X_SAVE = X;
    Y_SAVE = Y;
  
    X = -X;
    Y = -Y;
    Q1 = atan(Y/X) + PI;
    Q2 = atan((fabs(X)*(Z*-6.75E+2+sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)+2.025E+3))/(fabs(X)*-2.566E+3-Z*fabs(X)*1.5E+2+(X*X)*fabs(X)*2.5E+1+(Y*Y)*fabs(X)*2.5E+1+(Z*Z)*fabs(X)*2.5E+1+X*sqrt(X*X+Y*Y)*6.75E+2))*-2.0;
    Q3 = atan((sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)*2.0-1.1205E+4)/(Z*-3.0E+2+(X*X)*5.0E+1+(Y*Y)*5.0E+1+(Z*Z)*5.0E+1-3.107E+3))*-2.0;
    
    X = X_SAVE;
    Y = Y_SAVE;
  }
  
  else {
    
    Q1 = atan(Y/X);
    Q2 = atan((fabs(X)*(Z*-6.75E+2+sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)+2.025E+3))/(fabs(X)*-2.566E+3-Z*fabs(X)*1.5E+2+(X*X)*fabs(X)*2.5E+1+(Y*Y)*fabs(X)*2.5E+1+(Z*Z)*fabs(X)*2.5E+1+X*sqrt(X*X+Y*Y)*6.75E+2))*-2.0;
    Q3 = atan((sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)*2.0-1.1205E+4)/(Z*-3.0E+2+(X*X)*5.0E+1+(Y*Y)*5.0E+1+(Z*Z)*5.0E+1-3.107E+3))*-2.0;
  }

/*
  Serial.println("POSICIONES CALCULADAS");
  Serial.print("Q1: "); Serial.println(Q1);
  Serial.print("Q2: "); Serial.println(Q2);
  Serial.print("Q3: "); Serial.println(Q3);
*/

  Q1_G = (Q1)*180/PI;
  Q2_G = (Q2)*180/PI;
  Q3_G = (Q3)*180/PI;

/*
  Serial.println("POSICIONES CALCULADAS GRADOS");
  Serial.print("Q1: "); Serial.println(Q1_G);
  Serial.print("Q2: "); Serial.println(Q2_G);
  Serial.print("Q3: "); Serial.println(Q3_G);
*/

  Q1_WRI = Q1_G/CSTNT_GIRO;
  Q2_WRI = Q2_G;
  Q3_WRI = (Q3_G + 180)/CSTNT_GIRO;

/*
  Serial.println("POSICIONES ENVIADAS AL MOTOR");
  Serial.print("Q1: "); Serial.println(Q1_WRI);
  Serial.print("Q2: "); Serial.println(Q2_WRI);
  Serial.print("Q3: "); Serial.println(Q3_WRI);
*/

  Q1_1 = Q1_WRI;
  Q2_1 = Q2_WRI;
  Q3_1 = Q3_WRI;

  TRAY();
  
}

//////////////////////////////////////////////////////////////////////////////////

void TRAY(){
  
  R1[0] = Q1_0;
  R2[0] = Q2_0;
  R3[0] = Q3_0;
  
  CAM1 = (Q1_1 - Q1_0)/ PTS;
  CAM2 = (Q2_1 - Q2_0)/ PTS;
  CAM3 = (Q3_1 - Q3_0)/ PTS;
  
  for (j = 1; j <= PTS; j ++)
  {
    R1[j] = R1[j-1] + CAM1;
    R2[j] = R2[j-1] + CAM2;
    R3[j] = R3[j-1] + CAM3;
  }
}

//////////////////////////////////////////////////////////////////////////////////

void ARMWRITE(){
// TOMAR EN CUENTA QUE ESTAN RECIBIENDO DE UNO EN UNO

  if (UP){
    for(b = 0; b <= PTS; b++){
      HOMBRO.write(R2[b]);
      delay (50);
      CODO.write(R3[b]);
      delay (50);
    }
  }
  
  else{
    for(a = 0; a <= PTS; a++){
      BASE.write(R1[a]);
      delay (50);
    }
    for(b = 0; b <= PTS; b++){
      CODO.write(R3[b]);
      delay (50);
      HOMBRO.write(R2[b]);
      delay (50);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

void PINZA_PLEASE(){

  delay (500);
  PINZA.write(100);
  delay (500);      

}

///////////////////////////////////////////////////////////////////////////////////

void PINZA_NO(){

  delay (500);
  PINZA.write(0);
  delay (500);

}

//////////////////////////////////////////////////////////////////////////////////
