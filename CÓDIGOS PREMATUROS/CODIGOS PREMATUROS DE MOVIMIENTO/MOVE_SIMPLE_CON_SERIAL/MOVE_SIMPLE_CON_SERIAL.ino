#include <Servo.h>

float Q1, Q2, Q3, Q4, Q1_G[6], Q2_G[6], Q3_G[6];

int i = 0, j, l, n, IDX, CAMBIO = 0, CANT_POS;
String VAL = "";
bool FINISH = false;
const char SEP = ',';
const int CANT = 3;
double ANGULO[CANT];
const int DATO = 6;


// BASE || HOMBRO || CODO || PINZA

int S1 = 10, S2 = 11, S3 = 6, S4 = 9;

Servo BASE;
Servo HOMBRO;
Servo CODO;
Servo PINZA;

void ARMWRITE(void);
void SERIALRECIV(void);

void setup() {

// ATTACH Y LIMITES

// 0 ---> 180
BASE.attach(S1);
HOMBRO.attach(S2);
CODO.attach(S3);

// 0 ---> 110
PINZA.attach(S4);


// PRIMER ESCRITURA Y FUNCIONAMIENTO

PINZA.write(110); // CIERRA EN 110 ABRE CON 0
delay(50);

CODO.write(120); //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90 -- CERO ES DELANTE Y 90 ES DETRAS POR LO QUE FUNCIONA DETRAS HACIA ADELANTE
delay(50);

HOMBRO.write(90); // FUNCIONA NORMAL -- 0 ES DETRAS Y 180 ES DELANTE POR LO QUE VA DETRAS HACIA DELANTE
delay(50);

BASE.write(0);  //  FUNCIONA HASTA 270 PERO LA LIBRERIA ES DE 180 POR LO QUE 60 ES SU 90
delay(50);

Serial.begin(9600);

}


void loop() {
  
  SERIALRECIV();
  ARMWRITE();

//  SERVOWORK();
}

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


void SERIALRECIV(){
if(FINISH)
{
  for(i = 0; i < CANT ; i++)
  {
    IDX = VAL.indexOf(SEP);
    ANGULO[i] = VAL.substring(0,IDX).toFloat();
    VAL = VAL.substring(IDX + 1);
  }
  
  Q1 = ANGULO[0];
  Q2 = ANGULO[1];
  Q3 = ANGULO[2];
  
  Q1_G[i] = Q1;
  Q2_G[i] = Q2;
  Q3_G[i] = Q3;
  
  Serial.println(Q1);
  Serial.println(Q2);
  Serial.println(Q3);

  VAL = "";
  FINISH = false;
  CAMBIO++;
  
  }
}


void ARMWRITE(){
// TOMAR EN CUENTA QUE ESTAN RECIBIENDO DE UNO EN UNO

  if(CAMBIO == DATO){
  
    for (j = 0; j < DATO; j++){
      
      BASE.write(Q1_G[j]);
      delay (500);
    }

    for (l = 0; l < DATO; l++){
      
      HOMBRO.write(Q2_G[l]);
      delay (500);
    
    }
    
    for (n = 0; n < DATO; n++){
      
      CODO.write(Q3_G[n]);
      delay (500);
    }

      PINZA.write(50);
      delay (500);

      CAMBIO = 0;
    }
  }
