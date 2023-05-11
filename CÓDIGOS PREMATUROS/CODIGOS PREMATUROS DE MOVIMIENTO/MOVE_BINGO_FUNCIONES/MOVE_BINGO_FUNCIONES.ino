#include <Servo.h>

float Q1, Q2, Q3, Q1_G, Q2_G, Q3_G, Q1_WRI, Q2_WRI, Q3_WRI;
float Q1_0, Q2_0, Q3_0, Q1_1, Q2_1, Q3_1, CAM1, CAM2, CAM3;
float X, X_SAVE, X_R, Y_SAVE, Y, Y_R, Z, Z_R, K_R, CSTNT_GIRO = 1.5;

int i, j, a, b, c, IDX;
String VAL = "";
bool FINISH = false, CAMBIO = false, RECORRIDO = false, MOVEIT = false, UP = false;
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

void INICIA(void);
void ECU(float, float, float);
void ARMWRITE(void);
void TRAY(void);
void PINZA_PLEASE(void);
void PINZA_NO(void);

void PICK(float, float, float);
void PLACE(float, float, float);
void LIFT();


void GO_TO_0 ();



//POSICION 0 DE MOVIMIENTO
float P_0 [] = {20, 0, 24};

// POSISION DEL BASO
float P_6 [] = {19, -2, 16};

// POSIBLES POSICIONES DE LAS PIEZAS
float P_1 [] = {13, -26, 7};
float P_2 [] = {15.5, -23, 6.};
float P_3 [] = {17.5, -21.5, 7.5};
float P_4 [] = {20, -19.5, 6};
float P_5 [] = {21.5, -18, 7.5};



// POSIBLES POSICIONES DEL BINGO

float P_BINGO_1 [] = {27.3, 2.5, 10.5};
float P_BINGO_2 [] = {26.5, 2, 10.5};
float P_BINGO_3 [] = {24.5, 2, 9};
float P_BINGO_4 [] = {23.25, 2, 9};
float P_BINGO_5 [] = {22, 2, 8};

float P_BINGO_6 [] = {28.3, -0.5, 11};
float P_BINGO_7 [] = {26, -0.5, 10};
float P_BINGO_8 [] = {24.75, -0.5, 9};
float P_BINGO_9 [] = {24, -0.5, 8};
float P_BINGO_10 [] = {22, -0.5, 7};

float P_BINGO_11 [] = {27.8, -2, 11};
float P_BINGO_12 [] = {26.25, -2, 11};
float P_BINGO_13 [] = {25.25, -2, 11};
float P_BINGO_14 [] = {24, -2, 11};
float P_BINGO_15 [] = {22, -2, 11};

float P_BINGO_16 [] = {27.3, -3.5, 11};
float P_BINGO_17 [] = {26.5, -3.5, 11};
float P_BINGO_18 [] = {25, -3.5, 11};
float P_BINGO_19 [] = {24, -3.5, 11};
float P_BINGO_20 [] = {22.3, -3.5, 11};

float P_BINGO_21 [] = {27.8, -5.25, 11};
float P_BINGO_22 [] = {26.5, -5.25, 11};
float P_BINGO_23 [] = {25.25, -5.25, 11};
float P_BINGO_24 [] = {23.5, -5.25, 11};
float P_BINGO_25 [] = {22.5, -5.25, 11};



void setup() {

  INICIA();
  
  delay (2000);
/*
  GO_TO_0();

  PLACE(P_BINGO_1[0], P_BINGO_1[1], P_BINGO_1[2]);
  LIFT();
  PLACE(P_BINGO_2[0], P_BINGO_2[1], P_BINGO_2[2]);
  LIFT();
  PLACE(P_BINGO_3[0], P_BINGO_3[1], P_BINGO_3[2]);
  LIFT();
  PLACE(P_BINGO_4[0], P_BINGO_4[1], P_BINGO_4[2]);
  LIFT();
  PLACE(P_BINGO_5[0], P_BINGO_5[1], P_BINGO_5[2]);
  LIFT();

  PLACE(P_BINGO_6[0], P_BINGO_6[1], P_BINGO_6[2]);
  LIFT();
  PLACE(P_BINGO_7[0], P_BINGO_7[1], P_BINGO_7[2]);
  LIFT();
  PLACE(P_BINGO_8[0], P_BINGO_8[1], P_BINGO_8[2]);
  LIFT();
  PLACE(P_BINGO_9[0], P_BINGO_9[1], P_BINGO_9[2]);
  LIFT();
  PLACE(P_BINGO_10[0], P_BINGO_10[1], P_BINGO_10[2]);
  LIFT();
  
  PLACE(P_BINGO_11[0], P_BINGO_11[1], P_BINGO_11[2]);
  LIFT();
  PLACE(P_BINGO_12[0], P_BINGO_12[1], P_BINGO_12[2]);
  LIFT();
  PLACE(P_BINGO_13[0], P_BINGO_13[1], P_BINGO_13[2]);
  LIFT();
  PLACE(P_BINGO_14[0], P_BINGO_14[1], P_BINGO_14[2]);
  LIFT();
  PLACE(P_BINGO_15[0], P_BINGO_15[1], P_BINGO_15[2]);
  LIFT();

  PLACE(P_BINGO_16[0], P_BINGO_16[1], P_BINGO_16[2]);
  LIFT();
  PLACE(P_BINGO_17[0], P_BINGO_17[1], P_BINGO_17[2]);
  LIFT();
  PLACE(P_BINGO_18[0], P_BINGO_18[1], P_BINGO_18[2]);
  LIFT();
  PLACE(P_BINGO_19[0], P_BINGO_19[1], P_BINGO_19[2]);
  LIFT();
  PLACE(P_BINGO_20[0], P_BINGO_20[1], P_BINGO_20[2]);
  LIFT();
  
  PLACE(P_BINGO_21[0], P_BINGO_21[1], P_BINGO_21[2]);
  LIFT();
  PLACE(P_BINGO_22[0], P_BINGO_22[1], P_BINGO_22[2]);
  LIFT();
  PLACE(P_BINGO_23[0], P_BINGO_23[1], P_BINGO_23[2]);
  LIFT();
  PLACE(P_BINGO_24[0], P_BINGO_24[1], P_BINGO_24[2]);
  LIFT();
  PLACE(P_BINGO_25[0], P_BINGO_25[1], P_BINGO_25[2]);
  LIFT();
*/
}


void loop() {
  // put your main code here, to run repeatedly:
  

}


////////////////////////////////////////////////////////////////////////////

void ECU(float X, float Y, float Z) {
  
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
    
    Q1 = atan(Y/X);
    Q2 = atan((fabs(X)*(Z*-1.08E+2+sqrt(Z*-9.2016E+4+(X*X)*Z*1.92E+2+(Y*Y)*Z*1.92E+2+(X*X)*1.5336E+4-(X*X*X*X)*1.6E+1+(Y*Y)*1.5336E+4-(Y*Y*Y*Y)*1.6E+1+(Z*Z)*1.476E+4+(Z*Z*Z)*1.92E+2-(Z*Z*Z*Z)*1.6E+1-(X*X)*(Y*Y)*3.2E+1-(X*X)*(Z*Z)*3.2E+1-(Y*Y)*(Z*Z)*3.2E+1-1.05705E+5)+3.24E+2))/(fabs(X)*-4.59E+2-Z*fabs(X)*2.4E+1+(X*X)*fabs(X)*4.0+(Y*Y)*fabs(X)*4.0+(Z*Z)*fabs(X)*4.0+X*sqrt(X*X+Y*Y)*1.08E+2))*-2.0;
    Q3 = atan((sqrt(Z*-9.2016E+4+(X*X)*Z*1.92E+2+(Y*Y)*Z*1.92E+2+(X*X)*1.5336E+4-(X*X*X*X)*1.6E+1+(Y*Y)*1.5336E+4-(Y*Y*Y*Y)*1.6E+1+(Z*Z)*1.476E+4+(Z*Z*Z)*1.92E+2-(Z*Z*Z*Z)*1.6E+1-(X*X)*(Y*Y)*3.2E+1-(X*X)*(Z*Z)*3.2E+1-(Y*Y)*(Z*Z)*3.2E+1-1.05705E+5)-9.72E+2)/(Z*-2.4E+1+(X*X)*4.0+(Y*Y)*4.0+(Z*Z)*4.0-2.97E+2))*-2.0;
     
  }
  
  Q1_G = (Q1)*180/PI;
  Q2_G = (Q2)*180/PI;
  Q3_G = (Q3)*180/PI;
    
  Q1_1 = Q1_G/CSTNT_GIRO;
  Q2_1 = Q2_G;
  Q3_1 = (Q3_G + 180)/CSTNT_GIRO;

  Serial.println("\nVALORES DE POSICION 1\n");
  Serial.println(Q1_1);
  Serial.println(Q2_1);
  Serial.println(Q3_1);
    
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
      //Serial.println("HOMBRO");
      HOMBRO.write(R2[b]);
      delay (50);
      //Serial.println("CODO");
      CODO.write(R3[b]);
      delay (50);
    }
  }
    
  else {
    for(a = 0; a <= PTS; a++){
      BASE.write(R1[a]);
      delay (50);
      //Serial.println("BASE");
    }
      
    for(b = 0; b <= PTS; b++){
      //Serial.println("CODO");
      CODO.write(R3[b]);
      delay (50);
      //Serial.println("HOMBRO");
      HOMBRO.write(R2[b]);
      delay (50);
    }
  }
  
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
  
  PINZA.write(180); // CIERRA EN 110 ABRE CON 0
  delay(50);
  
  CODO.write(120); //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90 -- CERO ES DELANTE Y 90 ES DETRAS POR LO QUE FUNCIONA DETRAS HACIA ADELANTE
  delay(50);
  
  HOMBRO.write(90); // FUNCIONA NORMAL -- 0 ES DETRAS Y 180 ES DELANTE POR LO QUE VA DETRAS HACIA DELANTE
  delay(500);
  
  BASE.write(0);  //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90
  delay(50);
  
  Serial.begin(9600);

}

///////////////////////////////////////////////////////////////////////////////

void PINZA_PLEASE(){
  
  delay (500);
  PINZA.write(0);
  delay (500);
  PINZA.write(120);
  delay (500);      

}

///////////////////////////////////////////////////////////////////////////////////

void PINZA_NO(){

  delay (500);
  PINZA.write(0);
  delay (500);

}

/////////////////////////////////////////////////////////////////////////////////

void GO_TO_0 (){

  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();

  X_R = 20;
  Y_R = -1;
  Z_R = 24;

  ECU(X_R, Y_R, Z_R);
  TRAY();
  
  ARMWRITE();  

}

///////////////////////////////////////////////////////////////////////////////////

void PLACE(float P1, float P2, float P3){

  delay(1000);

  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();

  delay(100);
  
  X_R = P1;
  Y_R = P2;
  Z_R = P3;
    
  ECU(X_R, Y_R, Z_R);
  TRAY();

  Serial.println("\nVALORES DE POSICION 0\n");   
  Serial.println(Q1_0);
  Serial.println(Q2_0);
  Serial.println(Q3_0);
  
  ARMWRITE();  
//  PINZA_NO();
  
}

///////////////////////////////////////////////////////////////////////////////////

void PICK(float P1, float P2, float P3){

  delay(1000);

  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();

  delay(100);
  
  X_R = P1;
  Y_R = P2;
  Z_R = P3;
    
  ECU(X_R, Y_R, Z_R);
  TRAY();

    Serial.println("\nVALORES DE POSICION 0\n");   
  Serial.println(Q1_0);
  Serial.println(Q2_0);
  Serial.println(Q3_0);
  
  ARMWRITE();  
  PINZA_PLEASE();
}

////////////////////////////////////////////////////////////////////////////

void LIFT(){
  
  delay(100);

  Q1_0 = BASE.read();
  Q2_0 = HOMBRO.read();
  Q3_0 = CODO.read();

  delay(100);

  Q1_1 = Q1_0;
  Q2_1 = 80;
  Q3_1 = 100;

  TRAY();

  UP = true;

  ARMWRITE();

  UP = false;
}

//////////////////////////////////////////////////////////////////////////////////
