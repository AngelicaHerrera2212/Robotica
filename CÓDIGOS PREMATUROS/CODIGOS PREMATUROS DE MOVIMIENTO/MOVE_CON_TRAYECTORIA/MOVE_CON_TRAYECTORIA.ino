#include <Servo.h>

float Q1, Q2, Q3, Q1_G, Q2_G, Q3_G, Q1_WRI, Q2_WRI, Q3_WRI;
float Q1_0, Q2_0, Q3_0, Q1_1, Q2_1, Q3_1, CAM1, CAM2, CAM3;
float X, X_SAVE, X_R, Y_SAVE, Y, Y_R, Z, Z_R, K_R, CSTNT_GIRO = 1.5;

int i, j, a, b, c, IDX;
String VAL = "";
bool FINISH = false, CAMBIO = false, RECORRIDO = false, MOVEIT = false;
const char SEP = ',';
const int CANT = 4, PTS = 9, SIZE = PTS + 1;
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
void SERIALRECIV(void);
void TRAY(void);
void PINZA_PLEASE(void);

void setup() {

INICIA();

delay (2000);
}


void loop() {
  // put your main code here, to run repeatedly:

  SERIALRECIV();
  ECU(X_R, Y_R, Z_R);
  TRAY();
  ARMWRITE();
 
}

///////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////

void serialEvent(){
while(Serial.available()){
    char inChar = (char)Serial.read();
    VAL += inChar;
    if (inChar == '\n')
    {
      FINISH = true;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////

void SERIALRECIV(){
if(FINISH)
{
  for(i = 0; i < CANT ; i++)
  {
    IDX = VAL.indexOf(SEP);
    POSI[i] = VAL.substring(0,IDX).toFloat();
    VAL = VAL.substring(IDX + 1);
  }

  K_R = POSI[0];
  X_R = POSI[1];
  Y_R = POSI[2];
  Z_R = POSI[3];

 
  Serial.println("\nVALORES DE ENTRADA\n");
  Serial.println(K_R);
  Serial.println(X_R);
  Serial.println(Y_R);
  Serial.println(Z_R);


  VAL = "";
  FINISH = false;
  CAMBIO = true;
  
  }
}

////////////////////////z////////////////////////////////////////////////////

void ECU(float X, float Y, float Z) {

  if(CAMBIO)
  {
    X_SAVE = X;
    Y_SAVE = Y;
    
    if (X > 0){
      
      X = -X;
      Y = -Y;
    
      Q1 = atan(Y/X) + PI;
      Q2 = atan((fabs(X)*(Z*-6.75E+2+sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)+2.025E+3))/(fabs(X)*-2.566E+3-Z*fabs(X)*1.5E+2+(X*X)*fabs(X)*2.5E+1+(Y*Y)*fabs(X)*2.5E+1+(Z*Z)*fabs(X)*2.5E+1+X*sqrt(X*X+Y*Y)*6.75E+2))*-2.0;
      Q3 = atan((sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)*2.0-1.1205E+4)/(Z*-3.0E+2+(X*X)*5.0E+1+(Y*Y)*5.0E+1+(Z*Z)*5.0E+1-3.107E+3))*-2.0;
    
      }
    
    else {
    
      Q1 = atan(Y/X);
      Q2 = atan((fabs(X)*(Z*-6.75E+2+sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)+2.025E+3))/(fabs(X)*-2.566E+3-Z*fabs(X)*1.5E+2+(X*X)*fabs(X)*2.5E+1+(Y*Y)*fabs(X)*2.5E+1+(Z*Z)*fabs(X)*2.5E+1+X*sqrt(X*X+Y*Y)*6.75E+2))*-2.0;
      Q3 = atan((sqrt(Z*-3.50355E+6+(X*X)*Z*7.5E+3+(Y*Y)*Z*7.5E+3+(X*X)*5.83925E+5-(X*X*X*X)*6.25E+2+(Y*Y)*5.83925E+5-(Y*Y*Y*Y)*6.25E+2+(Z*Z)*5.61425E+5+(Z*Z*Z)*7.5E+3-(Z*Z*Z*Z)*6.25E+2-(X*X)*(Y*Y)*1.25E+3-(X*X)*(Z*Z)*1.25E+3-(Y*Y)*(Z*Z)*1.25E+3-2.483731E+6)*2.0-1.1205E+4)/(Z*-3.0E+2+(X*X)*5.0E+1+(Y*Y)*5.0E+1+(Z*Z)*5.0E+1-3.107E+3))*-2.0;
     
     }
    
    Q1_G = (Q1)*180/PI;
    Q2_G = (Q2)*180/PI;
    Q3_G = (Q3)*180/PI;
    
    Q1_WRI = Q1_G/CSTNT_GIRO;
    Q2_WRI = Q2_G;
    Q3_WRI = (Q3_G + 180)/CSTNT_GIRO;

    if (K_R == 1)
    {
      Q1_0 = Q1_WRI;
      Q2_0 = Q2_WRI;
      Q3_0 = Q3_WRI;

      Serial.println("\nVALORES DE POSICION 0\n");
      Serial.println(Q1_0);
      Serial.println(Q2_0);
      Serial.println(Q3_0);

      }
    else if (K_R == 2)
    {
      Q1_1 = Q1_WRI;
      Q2_1 = Q2_WRI;
      Q3_1 = Q3_WRI;

      Serial.println("\nVALORES DE POSICION 1\n");
      Serial.println(Q1_1);
      Serial.println(Q2_1);
      Serial.println(Q3_1);

      RECORRIDO = true;
      
      }
    
    CAMBIO = false;
  }
}

//////////////////////////////////////////////////////////////////////////////////

void TRAY(){
  if(RECORRIDO){
    
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
      
      RECORRIDO = false;
    }

  Serial.println("\nVALORES DE CAMBIO\n");
  Serial.println(CAM1);
  Serial.println(CAM2);
  Serial.println(CAM3);

  Serial.println("\nVALORES DE Q1\n");
  Serial.println(R1[0]);
  Serial.println(R1[1]);
  Serial.println(R1[2]);
  Serial.println(R1[3]);
  Serial.println(R1[4]);
  Serial.println(R1[5]);  
  Serial.println(R1[6]);
  Serial.println(R1[7]);
  Serial.println(R1[8]);  
  Serial.println(R1[9]);
      
  Serial.println("\nVALORES DE Q2\n");
  Serial.println(R2[0]);
  Serial.println(R2[1]);
  Serial.println(R2[2]);
  Serial.println(R2[3]);
  Serial.println(R2[4]);
  Serial.println(R2[5]);  
  Serial.println(R2[6]);
  Serial.println(R2[7]);
  Serial.println(R2[8]);  
  Serial.println(R2[9]);
  
  Serial.println("\nVALORES DE Q3\n");
  Serial.println(R3[0]);
  Serial.println(R3[1]);
  Serial.println(R3[2]);
  Serial.println(R3[3]);
  Serial.println(R3[4]);
  Serial.println(R3[5]);  
  Serial.println(R3[6]);
  Serial.println(R3[7]);
  Serial.println(R3[8]);  
  Serial.println(R3[9]);


  MOVEIT = true;
  }
}

//////////////////////////////////////////////////////////////////////////////////


void ARMWRITE(){
// TOMAR EN CUENTA QUE ESTAN RECIBIENDO DE UNO EN UNO
  if(MOVEIT){  
    
    for(a = 0; a <= PTS; a++){
      BASE.write(R1[a]);
      delay (250);
//      Serial.println("BASE");
    }

    for(b = 0; b <= PTS; b++){

      HOMBRO.write(R2[b]);
      delay (500);

//      Serial.println("CODO");
      CODO.write(R3[b]);
      delay (250);

//      Serial.println("HOMBRO");
    }
    
    MOVEIT = false;
  }
}

///////////////////////////////////////////////////////////////////////////////


void PINZA_PLEASE(){
      
      delay (500);
      PINZA.write(0);
      delay (500);
      PINZA.write(100);
      delay (500);      
  }

///////////////////////////////////////////////////////////////////////////////////
