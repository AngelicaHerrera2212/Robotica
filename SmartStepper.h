
#ifndef SmartStepper_h
#define SmartStepper_h

#include <Arduino.h>
#include <math.h>

class SmartStepper {
  private:
    
    int PUL;
    int DIR;
    
    
    bool CCW;
   

    double HOMEP;
   
    int i;
    bool Posicionada;

  public:
   double MINP; // POSICION MINIMA
    double MAXP; // POSICION MAXIMA
   double REVSTEPS; // PASOS POR REVOLUCION
    double AngActual; // ANGULO ACTUAL
    double AngRequest; // ANGULO REQUERIDO
    int S_HOME; // PIN DEL SENSOR DE HOMING
    SmartStepper(int pul, int dir ,double revsteps,int s_home, bool ccw ); // Funcion para crear el objeto
    void stepToHome(int DelayMicros = 1000); // No se usa hasta que homing te en home. Da pasos hacia un lado hasta encontrar el home
    void moveAngle(double Ang = 0 ,int DelayMicros = 1000 ); // Hasta terminar se mueva ese angulo, se mueva usando eso delay
    void setUp(double homep, double minp, double maxp ); // setup es meterle la informacion de la posicion de home (Angulo minimo y maximo segun la posicion de home) 
    void stepAngle(float Ang = 0 ,int DelayMicros = 1000 ); // Mover un paso a la posicion que yo quiero, llegar a 100 cuando este en 0, esconder los pasos
    void stepPosition(double Ang,int DelayMicros = 1000 ); // No se esta usando
    bool OnPosition(); // Me dice que estoy en la posicion deseada
    
};

#endif
