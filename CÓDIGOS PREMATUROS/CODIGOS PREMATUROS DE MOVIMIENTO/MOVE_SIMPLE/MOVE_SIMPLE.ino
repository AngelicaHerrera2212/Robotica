#include <Servo.h>

float Q1, Q2, Q3, Q1_G, Q2_G, Q3_G, Q1_WRI, Q2_WRI, Q3_WRI, X, X_SAVE, Y_SAVE, Y, Z, CSTNT_GIRO = 1.5;

// BASE || HOMBRO || CODO || PINZA

int S1 = 10, S2 = 11, S3 = 6, S4 = 9;

Servo BASE;
Servo HOMBRO;
Servo CODO;
Servo PINZA;


void setup() {


// ATTACH Y LIMITES

// 0 ---> 180
BASE.attach(S1);
HOMBRO.attach(S2);
CODO.attach(S3);

// 0 ---> 110
PINZA.attach(S4);

/*
// PRIMER ESCRITURA Y FUNCIONAMIENTO

PINZA.write(110); // CIERRA EN 110 ABRE CON 0
CODO.write(120); //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90 -- CERO ES DELANTE Y 90 ES DETRAS POR LO QUE FUNCIONA DETRAS HACIA ADELANTE
HOMBRO.write(90); // FUNCIONA NORMAL -- 0 ES DETRAS Y 180 ES DELANTE POR LO QUE VA DETRAS HACIA DELANTE
BASE.write(0);  //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90
*/


Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

X = 18.0;
Y = -21.0;
Z = 5.0;

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


BASE.write(Q1_WRI);
delay (1000);

CODO.write(Q3_WRI);
delay (1000);

HOMBRO.write(Q2_WRI);
delay (1000);

PINZA.write(110);
delay (1000);


/*
PINZA.write(0);
delay (1000);

CODO.write(60);
delay (1000);

HOMBRO.write(90);
delay (1000);

BASE.write(120);
delay (1000);
*/

delay (2000);

}
