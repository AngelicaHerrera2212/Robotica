#include <Servo.h>

Servo servoMotor;  // Crea un objeto Servo

int anguloAbierto = 0;  // Ángulo para la posición "abierta" del servo
int anguloCerrado = 90;  // Ángulo para la posición "cerrada" del servo

//Base
int PUL1=8; //define Pulse pin
int DIR1=9; //define Direction pin
int ENA1=10; //define Enable Pin

//Hombro
int PUL2=5; //define Pulse pin
int DIR2=6; //define Direction pin
int ENA2=7; //define Enable Pin

//Codo
int PUL3=2; //define Pulse pin
int DIR3=3; //define Direction pin
int ENA3=4; //define Enable Pin

//int pasostotal = 5400; // 200 pasos * 27 que es la reduccion
//int pasostotal2 = 10200; // 200 pasos * 27 que es la reduccion
//float ppg1 = pasostotal/360; // ppg pasos por grado
//float ppg2 = pasostotal2/360; // ppg pasos por grado

float ang1=0;
float ang2=0;
float ang3=0;

void setup() {
  // put your setup code here, to run once:
  pinMode (PUL1, OUTPUT);
  pinMode (DIR1, OUTPUT);
  pinMode (ENA1, OUTPUT);

  pinMode (PUL2, OUTPUT);
  pinMode (DIR2, OUTPUT);
  pinMode (ENA2, OUTPUT);
  
  pinMode (PUL3, OUTPUT);
  pinMode (DIR3, OUTPUT);
  pinMode (ENA3, OUTPUT);

  servoMotor.attach(49);  // Especifica el pin del servo

  Serial.begin(9600);

   }

   void loop() {
    delay(2000);
//    inicio1 ();
//    delay(1000); 
//    inicio2 ();
//    delay(1000);
//    part1a ();
//    delay(1000); 
//    part1b ();
//    delay(1000);
    part2 ();
    delay(1000);
//    part3a ();
//    delay(1000);
//    part3b ();
//    delay(1000);
//  part4 ();
//  delay(1000);
//  part5 ();
//  delay(1000);    
//  matrix1_1 ();
//  delay(1000);
  //mov1CW ();
  //delay(1000); 
  //mov1CCW ();
  //delay(1000);
  //mov3CW ();
  //delay(1000);  
  //mov3CCW ();
  //delay(1000);
  //mov2CW(); 
  //delay(1000);
  //mov2CCW(); 
  delay(50000);
  
    }

void inicio1 (){
  ang1 = 90;
  mov1CW ();
  delay(1000);
  
  ang3 = 20;
  mov3CW ();
  delay(1000);

  ang2 = 0;
  mov2CW();
  delay(1000);
}

void inicio2 (){
  ang3 = 20;
  mov3CCW ();
  delay(1000);

  ang2 = 0;
  mov2CCW();
  delay(1000);

  ang1 = 90;
  mov1CCW ();
  delay(1000);
}
    
void part1a (){
  ang1=28.393;
  mov1CW ();
  delay(1000);

//  ang2= 16.9317;
//  ang3= 30.188;
//  mov23_IZ_DOWN ();
//  delay(1000);
  
  ang3 = 16.456;
  mov3CW ();
  delay(1000);

  ang2 = 3.2589;
  mov2CW();
  delay(1000);
}

void part1b (){
//  ang3 = 0;
//  mov3CCW ();
//  delay(1000);
//
//  ang2 = 0;
//  mov2CCW();
//  delay(1000);

  ang1 = 28.393;
  mov1CCW ();
  delay(1000);
}

void part2 (){
  //M2 abajo - M3 arriba
  
  ang2= 0.86072;
  ang3= 5.44424;
  mov23_IZ_DOWN_P1 ();  
  delay(100);

  ang2= 1.16072;
  ang3= 3.84424;
  mov23_IZ_DOWN_P2 ();  
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_IZ_DOWN ();
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_IZ_DOWN ();
  delay(100);

  ang2= 1.094;
  ang3= 2.024;
  mov23_IZ_DOWN ();
  delay(100);

  ang2= 1.094;
  ang3= 1.824;
  mov23_IZ_DOWN ();
  delay(100);

  ang2= 1.094;
  ang3= 1.024;
  mov23_IZ_DOWN_P3 ();
  delay(100);

  ang2= 1.294;
  ang3= 1.324;
  mov23_IZ_DOWN_P3 ();
  delay(100);

  //M2 abajo - M3 abajo

  ang2= 1.294;
  ang3= 1.324;
  mov23_IZ_UP_P3 ();
  delay(100);

  ang2= 1.094;
  ang3= 1.024;
  mov23_IZ_UP_P3 ();
  delay(100);

  ang2= 1.094;
  ang3= 1.824;
  mov23_IZ_UP ();
  delay(100);

  ang2= 1.094;
  ang3= 2.024;
  mov23_IZ_UP ();
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_IZ_UP ();
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_IZ_UP ();
  delay(100);

  ang2= 1.16072;
  ang3= 3.84424;
  mov23_IZ_UP_P2 ();  
  delay(100);

  ang2= 0.86072;
  ang3= 5.44424;
  mov23_IZ_UP_P1 ();  
  delay(100);

  //M2 arriba - M3 arriba
  
  ang2= 0.86072;
  ang3= 5.44424;
  mov23_DER_UP_P1 ();  
  delay(100);

  ang2= 1.16072;
  ang3= 3.84424;
  mov23_DER_UP_P2 ();  
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_DER_UP ();
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_DER_UP ();
  delay(100);

  ang2= 1.094;
  ang3= 2.024;
  mov23_DER_UP ();
  delay(100);

  ang2= 1.094;
  ang3= 1.824;
  mov23_DER_UP ();
  delay(100);

  ang2= 1.094;
  ang3= 1.024;
  mov23_DER_UP_P3 ();
  delay(100);

  ang2= 1.294;
  ang3= 1.324;
  mov23_DER_UP_P3 ();
  delay(100);

    //M2 abajo - M3 abajo

  ang2= 1.294;
  ang3= 1.324;
  mov23_DER_DOWN_P3 ();
  delay(100);

  ang2= 1.094;
  ang3= 1.024;
  mov23_DER_DOWN_P3 ();
  delay(100);

  ang2= 1.094;
  ang3= 1.824;
  mov23_DER_DOWN ();
  delay(100);

  ang2= 1.094;
  ang3= 2.024;
  mov23_DER_DOWN ();
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_DER_DOWN ();
  delay(100);

  ang2= 2.016144;
  ang3= 3.808272;
  mov23_DER_DOWN ();
  delay(100);

  ang2= 1.16072;
  ang3= 3.84424;
  mov23_DER_DOWN_P2 ();  
  delay(100);

  ang2= 0.86072;
  ang3= 5.44424;
  mov23_DER_DOWN_P1 ();  
  delay(100);


}

void part3a (){
  ang1 = 28.393;
  mov1CW ();
  delay(1000);
  
//  ang3 = 0;
//  mov3CW ();
//  delay(1000);
//
//  ang2 = 0;
//  mov2CW();
//  delay(1000);
}

void part3b (){
//  ang2= 16.9317;
//  ang3= 30.188;
//  mov23_DER_UP ();
//  delay(1000);
  
  ang3 = 16.456;
  mov3CCW ();
  delay(1000);

  ang2 = 3.2589;
  mov2CCW();
  delay(1000);

  ang1 = 28.393;
  mov1CCW ();
  delay(1000);
}

void part4 (){
  ang1= 10.0702;
  mov1CW ();
  delay(1000);

  ang2= 52.4835;
  ang3= 44.3655;
  mov23_IZ_DOWN ();
  delay(1000);
  
//  ang3 = 44.3655;
//  mov3CW ();
//  delay(1000);
//
//  ang2 = 52.4835;
//  mov2CW();
//  delay(1000);

  closeservo();
}

void part5 (){
  ang2 = 52.4835;
  mov2CCW();
  delay(1000);
}  

void matrix1_1 (){
  ang1= 70.1474;
  mov1CW ();
  delay(1000);

  ang2= 79.7439;
  ang3= 49.7545;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix2_1 (){
  ang1= 69.2449;
  mov1CW ();
  delay(1000);

  ang2= 63.4729;
  ang3= 22.6061;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix3_1 (){
  ang1= 68.1615;
  mov1CW ();
  delay(1000);

  ang2= 52.4793;
  ang3= 24.4696;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix4_1 (){
  ang1= 66.8379;
  mov1CW ();
  delay(1000);

  ang2= 43.2586;
  ang3= 10.4294;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix5_1 (){
  ang1= 65.1862;
  mov1CW ();
  delay(1000);

  ang2= 34.8781;
  ang3= 23.5622;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix1_2 (){
  ang1= 75.0027;
  mov1CW ();
  delay(1000);

  ang2= 76.8924;
  ang3= 44.9907;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix2_2 (){
  ang1= 74.5405;
  mov1CW ();
  delay(1000);

  ang2= 61.7305;
  ang3= 19.7137;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix3_2 (){
  ang1= 73.9829;
  mov1CW ();
  delay(1000);

  ang2= 50.9429;
  ang3= 1.9623;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix4_2 (){
  ang1= 73.2973;
  mov1CW ();
  delay(1000);

  ang2= 41.7372;
  ang3= 12.8475;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix5_2 (){
  ang1= 72.4339;
  mov1CW ();
  delay(1000);

  ang2= 33.258;
  ang3= 26.0407;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix1_3 (){
  ang1= 79.9298;
  mov1CW ();
  delay(1000);

  ang2= 76.0226;
  ang3= 43.5373;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix2_3 (){
  ang1= 79.9298;
  mov1CW ();
  delay(1000);

  ang2= 61.1622;
  ang3= 18.7714;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix3_3 (){
  ang1= 79.9298;
  mov1CW ();
  delay(1000);

  ang2= 50.4342;
  ang3= 1.1341;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix4_3 (){
  ang1= 79.9298;
  mov1CW ();
  delay(1000);

  ang2= 41.2289;
  ang3= 13.6524;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix5_3 (){
  ang1= 79.9298;
  mov1CW ();
  delay(1000);

  ang2= 32.7118;
  ang3= 26.8713;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix1_4 (){
  ang1= 87.4257;
  mov1CW ();
  delay(1000);

  ang2= 76.8924;
  ang3= 44.9907;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix2_4 (){
  ang1= 86.5623;
  mov1CW ();
  delay(1000);

  ang2= 61.7305;
  ang3= 19.7137;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix3_4 (){
  ang1= 85.8767;
  mov1CW ();
  delay(1000);

  ang2= 50.9429;
  ang3= 1.9623;
  mov23_IZ_DOWN ();
  delay(1000);
}

void matrix4_4 (){
  ang1= 85.3191;
  mov1CW ();
  delay(1000);

  ang2= 41.7372;
  ang3= 12.8475;
  mov23_IZ_UP ();
  delay(1000);
}

void matrix5_4 (){
  ang1= 84.8569;
  mov1CW ();
  delay(1000);

  ang2= 33.258;
  ang3= 26.0407;
  mov23_IZ_UP ();
  delay(1000);
}

void mov1CW (){
  int pasostotal = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal/360; // ppg pasos por grado
  //float ang1 = 45; // ángulo cintura
  float pasos1 = ang1*ppg1*16; // pasos a dar cintura

  for (int i=0; i<pasos1; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR1,LOW);//derecha cw
    digitalWrite(ENA1,LOW);
    digitalWrite(PUL1,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL1,LOW);
    delayMicroseconds(500);
  }
//delay(10000); 
  } 
  
void mov1CCW (){
  int pasostotal = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal/360; // ppg pasos por grado
  //float ang1 = 45; // ángulo cintura
  float pasos1 = ang1*ppg1*16; // pasos a dar cintura

for (int i=0; i<pasos1; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR1,HIGH);//izquierda ccw
    digitalWrite(ENA1,LOW);
    digitalWrite(PUL1,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL1,LOW);
    delayMicroseconds(500);
  }
//delay(10000);  
  }

void mov2CW() {
  mov2CWuno();
  delay(10);
  mov2CWuno();
  delay(10);
  mov2CWuno();
  delay(10);
  mov2CWuno();
  delay(10);
  mov2CWuno();
  //delay(10000); // One second delay
}

void mov2CWuno() {  
  //float q2e = 21.7718;
  //float ang2 = 68.2282;
  int ppv2 = 3200;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  
  // Makes 200 pulses for making one full cycle rotation
  for (int i=0; i<pasos2; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR2,LOW);// baja
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
  } 
}

void mov2CCW() {
  mov2CCWuno();
  delay(10);
  mov2CCWuno();
  delay(10);
  mov2CCWuno();
  delay(10);
  mov2CCWuno();
  delay(10);
  mov2CCWuno();
  //delay(10000); // One second delay
}

void mov2CCWuno() {  
  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  
  // Makes 200 pulses for making one full cycle rotation
  for (int i=0; i<pasos2; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR2,HIGH); //sube
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
  }
}

void mov3CW (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  for (int i=0; i<pasos3; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR3,LOW);// sube derecha cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(1000);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(1000);
  }
//delay(10000); 
  } 
  
void mov3CCW (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

for (int i=0; i<pasos3; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(1000);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(1000);
  }
//delay(10000);  
  }

void mov23_DER_UP (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array1[] = {pasos2, pasos3};

  int size1 = sizeof(counter_array1) / sizeof(counter_array1[0]);
  int mayor1 = counter_array1[0];

  for (int i = 1; i < size1; i++) {
    if (counter_array1[i] > mayor1) {
      mayor1 = counter_array1[i];
    }
  }
  
 for (int i=0; i<mayor1; i++)
  {
    if(counter_array1[0] > 0){
    digitalWrite(DIR2,HIGH); //sube CCW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array1[0]--;
    }
    if(counter_array1[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array1[1]--;
    }
  }
}

void mov23_DER_DOWN (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array2[] = {pasos2, pasos3};

  int size2 = sizeof(counter_array2) / sizeof(counter_array2[0]);
  int mayor2 = counter_array2[0];

  for (int i = 1; i < size2; i++) {
    if (counter_array2[i] > mayor2) {
      mayor2 = counter_array2[i];
    }
  }
  
 for (int i=0; i<mayor2; i++)
  {
    if(counter_array2[0] > 0){
    digitalWrite(DIR2,HIGH);
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array2[0]--;
    }
    if(counter_array2[1] > 0){
    digitalWrite(DIR3,LOW);//
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array2[1]--;
    }
  }
}

void mov23_IZ_DOWN (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_IZ_UP (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array4[] = {pasos2, pasos3};

  int size4 = sizeof(counter_array4) / sizeof(counter_array4[0]);
  int mayor4 = counter_array4[0];

  for (int i = 1; i < size4; i++) {
    if (counter_array4[i] > mayor4) {
      mayor4 = counter_array4[i];
    }
  }
  
 for (int i=0; i<mayor4; i++)
  {
    if(counter_array4[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array4[0]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
  } 
}

void mov23_IZ_DOWN_P1 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
        if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
        if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_IZ_DOWN_P2 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
        if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_IZ_DOWN_P3 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }   
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    } 
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_IZ_UP_P1 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array4[] = {pasos2, pasos3};

  int size4 = sizeof(counter_array4) / sizeof(counter_array4[0]);
  int mayor4 = counter_array4[0];

  for (int i = 1; i < size4; i++) {
    if (counter_array4[i] > mayor4) {
      mayor4 = counter_array4[i];
    }
  }
  
 for (int i=0; i<mayor4; i++)
  {
    if(counter_array4[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array4[0]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
  } 
}

void mov23_IZ_UP_P2 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,HIGH);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
        if(counter_array3[1] > 0){
    digitalWrite(DIR3,HIGH);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_IZ_UP_P3 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }   
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,LOW); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    } 
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,HIGH);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_DER_UP_P1 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array4[] = {pasos2, pasos3};

  int size4 = sizeof(counter_array4) / sizeof(counter_array4[0]);
  int mayor4 = counter_array4[0];

  for (int i = 1; i < size4; i++) {
    if (counter_array4[i] > mayor4) {
      mayor4 = counter_array4[i];
    }
  }
  
 for (int i=0; i<mayor4; i++)
  {
    if(counter_array4[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array4[0]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,HIGH);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
  } 
}

void mov23_DER_UP_P2 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,HIGH);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
        if(counter_array3[1] > 0){
    digitalWrite(DIR3,HIGH);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_DER_UP_P3 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }   
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    } 
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,HIGH);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_DER_DOWN_P1 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array4[] = {pasos2, pasos3};

  int size4 = sizeof(counter_array4) / sizeof(counter_array4[0]);
  int mayor4 = counter_array4[0];

  for (int i = 1; i < size4; i++) {
    if (counter_array4[i] > mayor4) {
      mayor4 = counter_array4[i];
    }
  }
  
 for (int i=0; i<mayor4; i++)
  {
    if(counter_array4[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array4[0]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,LOW);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,LOW);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
    if(counter_array4[1] > 0){
    digitalWrite(DIR3,LOW);// baja izquierda ccw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array4[1]--;
    }
  } 
}

void mov23_DER_DOWN_P2 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
        if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void mov23_DER_DOWN_P3 (){
  int pasostotal3 = 5400; // 200 pasos * 27 que es la reduccion
  float ppg1 = pasostotal3/360; // ppg pasos por grado
  //float ang3 = 78.2734; // ángulo cintura
  float pasos3 = ang3*ppg1*16; // pasos a dar cintura

  //float q2e = 21.7718;
  //float ang2 =  68.2282;
  int ppv2 = 3200*5;
  float mult2 = (ang2*10.2)/360;
  float pasos2 = mult2*ppv2;//90 para 51:1
  float counter_array3[] = {pasos2, pasos3};

  int size3 = sizeof(counter_array3) / sizeof(counter_array3[0]);
  int mayor3 = counter_array3[0];

  for (int i = 1; i < size3; i++) {
    if (counter_array3[i] > mayor3) {
      mayor3 = counter_array3[i];
    }
  }
  
 for (int i=0; i<mayor3; i++)
  {
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    }   
    if(counter_array3[0] > 0){
    digitalWrite(DIR2,HIGH); //baja CW
    digitalWrite(ENA2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
    counter_array3[0]--;
    } 
    if(counter_array3[1] > 0){
    digitalWrite(DIR3,LOW);// sube cw
    digitalWrite(ENA3,LOW);
    digitalWrite(PUL3,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL3,LOW);
    delayMicroseconds(500);
    counter_array3[1]--;
    }
  }
}

void openservo() {
  // Abre el servo
  servoMotor.write(anguloAbierto);
  delay(3000);  // Espera 1 segundo
}
void closeservo() {
  // Cierra el servo
  servoMotor.write(anguloCerrado);
  delay(3000);  // Espera 1 segundo
}
