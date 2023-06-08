//SmartStepper.cpp
#define DelayMicroseconds 1000
#include "SmartStepper.h"

SmartStepper::SmartStepper(int pul, int dir,double revsteps,int s_home, bool ccw ) {
  
  REVSTEPS= revsteps;
  PUL=pul;
  DIR=dir;

  S_HOME=s_home;
  CCW=ccw;
  i=1;
  Posicionada = false;
   
  pinMode(DIR, OUTPUT);
  pinMode(PUL, OUTPUT);

  pinMode(S_HOME, INPUT);
  Serial.begin(9600);
  
}

void SmartStepper::stepToHome(int DelayMicros = 1000 ) {
  int pasos=0;
  bool ccw=CCW;
  if((digitalRead(S_HOME)))
  {
    pasos= -1;
    }
  if((pasos != -1)){//!(digitalRead(S_HOME) &&
         //if(pasos <= (REVSTEPS/8))
            digitalWrite(DIR,ccw);
            digitalWrite(PUL,HIGH);  
            delayMicroseconds(DelayMicros);
            digitalWrite(PUL,LOW);
            delayMicroseconds(DelayMicros);
           // pasos=pasos+1;
          }
      
}

void SmartStepper::moveAngle(double Ang = 0 ,int DelayMicros = 1000 ) { // MOVE ANGLE MUEVE  1 SOLO MOTOR SEGUIDO NO SE USA EN EL CODIGO PRINCIPAL
     i= 1; // Es el paso que voy a incrementar para mover el angulo
     AngRequest = REVSTEPS/(360/Ang); // Rev stepper * (angulo) / 360
     double pos;
     bool ccwl = CCW;
    if((AngRequest-AngActual)<0){ccwl = !CCW; i=-1;}else{i=1;ccwl = CCW;} 
     
  for(AngActual = AngActual; (abs(AngRequest-AngActual) >= 1); AngActual += i) // goes from 0 degrees to 180 degrees 
  {    
     if((AngRequest > MAXP) || (AngRequest< MINP)){ break;} // IMPLEMENTAR MENSAJE DE ERROR SI SE SALE DE LOS ANGULOS MAXIMOS, agregar variable de nombre para saber que motor se salio de la dimension.
     // Y decirle que entre un valor dentro del espacio de trabajo
          digitalWrite(DIR,ccwl);
          
          digitalWrite(PUL,HIGH);  
          delayMicroseconds(DelayMicros);
          digitalWrite(PUL,LOW);
          delayMicroseconds(DelayMicros);
                           
   //   }else{} //
  } 

  //Serial.println((360*(AngActual / REVSTEPS)));
  //  Serial.println((360*(AngRequest / REVSTEPS))); 
}


void SmartStepper::stepAngle(float Ang = 0 ,int DelayMicros = 1000 ) {
     i= 1;
     AngRequest = REVSTEPS/(360/Ang);
     float pos;
     bool ccwl = CCW;
    if((AngRequest-AngActual)<0){ccwl = !CCW; i=-1;}else{i=1;ccwl = CCW;}
     
    if(abs(AngRequest-AngActual) >= 1)
    { // goes from 0 degrees to 180 degrees 
        
       if (((AngRequest <= MAXP) && (AngRequest >= MINP)))
       { 
            digitalWrite(DIR,ccwl);
            
            digitalWrite(PUL,HIGH);  
            delayMicroseconds(DelayMicros);
            digitalWrite(PUL,LOW);
            delayMicroseconds(DelayMicros);
            AngActual += i;
            
        
     
            }
          
    } 
     
}
boolean SmartStepper::OnPosition() { //QUITAR PORQUE NO LO VOY A USAR O MEJORAR
       if(AngActual == AngRequest){
          i=i; 
          return true;
        }else{
         // if( ((AngActual +i) < MINP) || ((AngActual +i) > MAXP) ){AngActual = AngActual; return true;}
          i=i; return false;
        }
         //   Serial.println((360*(AngActual / REVSTEPS)));
        //   Serial.println((360*(AngRequest / REVSTEPS)));  
}



void SmartStepper::setUp(double homep, double minp, double maxp ) {
    HOMEP = REVSTEPS/(360/homep); // posicion en paso del home
     MINP = REVSTEPS/(360/minp); // posicion en pasos minimo
     MAXP = REVSTEPS/(360/maxp); // posicion en pasos maximo
     AngActual= REVSTEPS/(360/homep); // Posicion en pasos del angulo, o posicion actual inicial. 
     
}
