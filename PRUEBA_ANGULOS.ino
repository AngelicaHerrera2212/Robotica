#include <math.h>
#include <Servo.h>

#include "SmartStepper.h"
// Definiciones
//Pines Base
#define PulB 0
#define DirB 1

//Pines Hombro
#define PulH 4
#define DirH 5

//Pines codo
#define PulC 2
#define DirC 3

//Sensores Homing
#define s_base 29
#define s_hombro 27
#define s_codo 28

//factores de transmision PASOS POR REV REV COMPLETA
float TM_Base = (60 / 10) * 360; // Transmision * Microstepping * 360
float TM_Hombro = (26 + (103 / 121)) * (60 / 12) * 360;
float TM_Codo = (60 / 12) * 360;

/*/ Definiciones || SAMUEL EDITA
//Pines Base
#define PulB 8
#define DirB 9

//Pines Hombro
#define PulH 2
#define DirH 3

//Pines codo
#define PulC 5
#define DirC 6

//Sensores Homing
#define s_base 29
#define s_hombro 27
#define s_codo 28

//factores de transmision PASOS POR REV REV COMPLETA ||| SAMUEL LA CANTIDAD DE PASOS POR REVOLUCION
float TM_Base = 200; // Transmision * Microstepping 
float TM_Hombro = 200;//(26 + (103 / 121)) * (60 / 12) * 360;
float TM_Codo = 200;///(60 / 12) * 360;
*/
//Variables
float var_x, var_y, var_z; // Variables para indicar cinematica directa
float AngB, AngC, AngH; // Variables angulos de los motores
const float RAD2DEG = 180.0f / PI;
float q1_deg, q2a_deg, q3a_deg; // Variables de los angulos de cinematica inversa

int Etapa = 0;

bool CCWBase = HIGH;
bool CCWHombro = LOW;
bool CCWCodo = HIGH;
 
//  :SmartStepper(int pul, int dir,double revsteps,int s_home, bool ccw ) ccw default high o low ||| SAMUEK EDITA
SmartStepper BaseStepper(PulB, DirB, TM_Base, s_base, CCWBase);
SmartStepper HombroStepper(PulH, DirH, TM_Hombro, s_hombro, CCWHombro);
SmartStepper CodoStepper(PulC, DirC, TM_Codo, s_codo, CCWCodo);

// Funciones
void Desenfundar (void);
void homing (void);
void aimbot (void);

float B = 0;
float H = -90;
float C = 0;
Servo Muneca;
Servo Gatillo;
Servo Agarre;

int M_actual = 30;
int G_actual = 0;
int A_actual = 0;
int B_actual = 0;
int H_actual = 0;
int C_actual = 0;

int M_req = 95;
int G_req = 0;
int A_req = 0;
int B_req = 0;
int H_req = 0;
int C_req = 0;

bool control = true;
bool Hcontrol = true;

int ang, pos, angs;
int td = 20;
String cad,cad1,cad2,ant;

int B_Fundado[21] = {  0,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16};
int H_Fundado[21] = {-61, -61, -56, -51, -47, -43, -41, -36, -33, -31, -31, -31, -31, -31, -31, -31, -31, -31, -31, -31, -31};
int C_Fundado[21] = {-95, -95, -95, -95, -95, -95, -95, -95, -95, -95, -90, -86, -83, -80, -76, -73, -70, -67, -64, -60, -50};
int M_Fundado[21] = {133, 130, 127, 125, 122, 120, 118, 115, 112, 110, 108, 105, 102, 100,  97,  95,  92,  90,  87,  85,  90};
int A_Fundado[21] = {  0,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60};
int G_Fundado[21] = {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};


void setup() {
  //put your setup code here, to run once: ||| SAMUEL EDITA
  BaseStepper.setUp(0, -90, 90);//  home,min,max  :setUp(double homep, double minp, double maxp ) { angulo home/start, minimo y maximo
  HombroStepper.setUp(0, -90, 90);//
  CodoStepper.setUp(0, -95, 95);//
  Serial.begin(9600);

  Serial.println("Envie un comando Articulacion,Angulo Hombro,60 -> H,60");
  delay(2000);
   pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
   // Envía ambos pines a "low"
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
   // Envía ambos pines a "low"
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
}

//// SAMUEL A ESTE PROGRAMA LE VAS A INGRESAR UNA LETRA,ANGUlO para mover ese motor a ese angulo. C,50 es mover el codo a 50 grados
void loop() 
{
  if (Serial.available())
  {
    cad = Serial.readString();
    Serial.println(cad);

    if ( cad.charAt(1) == ',') // Verifica que la cadena tenga el formato correcto
    {
      char letra = cad.charAt(0);
      letra = toupper(letra);
      int numero = cad.substring(2).toInt();
       Serial.println(numero);
      switch(letra)
      {
        case 'B':
          BaseStepper.moveAngle(numero, 6000);
          Serial.println(letra);
          break;

        case 'H':
          HombroStepper.moveAngle(numero, 6000);
          Serial.println(letra);
          break;

        case 'C':
          CodoStepper.moveAngle(numero, 6000);
          Serial.println(letra);
          break;

        case 'Q':
          homing();
          Serial.println(letra);
          break;

        default:
          Serial.println("Comando no reconocido.");
          Serial.println(letra);
          Serial.println(numero);
          Serial.println(cad);
          break;
      }
    }
    else
    {
      Serial.println("Formato de comando incorrecto.");
    }
  }
}


void Desenfundar()
{ 
  for (int i = 0; i<21; i++)
  {
    control = true;
    M_req = M_Fundado [i];
    G_req = G_Fundado [i];
    A_req = A_Fundado [i];
    B_req = B_Fundado [i];
    H_req = H_Fundado [i];
    C_req = C_Fundado [i];
  
    while (control)
    {
      if (M_actual != M_req)
      {
        if (M_actual < M_req)
        {
          M_actual = M_actual + 1;
          Muneca.write (M_actual);
          //delay (td);
        }
        else if (M_actual > M_req)
        {
          M_actual = M_actual - 1;
          Muneca.write (M_actual);
          //delay (td);
        }
        Serial.print ("M = ");
        Serial.println (M_actual);
      }
  
      if (G_actual != G_req)
      {
        if (G_actual < G_req)
        {
          G_actual = G_actual + 1;
          Gatillo.write (G_actual);
          //delay (td);
        }
        else if (G_actual > G_req)
        {
          G_actual = G_actual - 1;
          Gatillo.write (G_actual);
          //delay (td);
        }
        Serial.print ("G = ");
        Serial.println (G_actual);
      }
  
      if (A_actual != A_req)
      {
        if (A_actual < A_req)
        {
          A_actual = A_actual + 1;
          Agarre.write (A_actual);
          //delay (td);
        }
        else if (A_actual > A_req)
        {
          A_actual = A_actual - 1;
          Agarre.write (A_actual);
          //delay (td);
        }
        Serial.print ("A = ");
        Serial.println (A_actual);
      }
  
      if (B_actual != B_req)
      {
        if (B_actual < B_req)
        {
          B_actual = B_actual + 1;
          BaseStepper.moveAngle (B_actual,6000);
        }
        else if (B_actual > B_req)
        {
          B_actual = B_actual - 1;
          BaseStepper.moveAngle (B_actual,6000);
        }
        Serial.print ("B = ");
        Serial.println (B_actual);
      }
  
      if (H_actual != H_req)
      {
        if (H_actual < H_req)
        {
          H_actual = H_actual + 1;
          HombroStepper.moveAngle (H_actual);
        }
        else if (H_actual > H_req)
        {
          H_actual = H_actual - 1;
          HombroStepper.moveAngle (H_actual);
        }
        Serial.print ("H = ");
        Serial.println (H_actual);
      }
      
      if (C_actual != C_req)
      {
        if (C_actual < C_req)
        {
          C_actual = C_actual + 1;
          CodoStepper.moveAngle (C_actual,6000);
        }
        else if (C_actual > C_req)
        {
          C_actual = C_actual - 1;
          CodoStepper.moveAngle (C_actual,6000);
        }
        Serial.print ("C = ");
        Serial.println (C_actual);
      }
  
      if ((M_actual == M_req) && (G_actual == G_req) && (A_actual == A_req) &&
          (B_actual == B_req) && (H_actual == H_req) && (C_actual == C_req))
      {
        control = false;
      }
      
    }
    Serial.println ("--------------------");
    delay (100);
    
  }
  Serial.println ("Sali del for"); 
}

void homing() 
{ 
  if (Hcontrol)
  {
    while ((!digitalRead(CodoStepper.S_HOME)) ) 
    {
      CodoStepper.moveAngle (C_actual,8000);
      C_actual = C_actual + 1;
      Serial.println (C_actual);
    }
    
    Serial.println("------- Codo Hommed--------");
    
    while ((!(digitalRead(HombroStepper.S_HOME)))) 
    {
      HombroStepper.moveAngle (H_actual,500);
      H_actual = H_actual + 1;
      Serial.println (H_actual);
    }
  
    Serial.println("------- Hombro Hommed--------");
    
    while ((!(digitalRead(BaseStepper.S_HOME))) ) 
    {
      BaseStepper.moveAngle (B_actual,8000);
      B_actual = B_actual + 1;
      Serial.println (B_actual);
    }
    
    Serial.println("------- Base Hommed--------");
    BaseStepper.AngActual = 0;
    HombroStepper.AngActual = 0;
    CodoStepper.AngActual = 0;
  
    BaseStepper.moveAngle (-60,6000);
    HombroStepper.moveAngle (9, 500);
    CodoStepper.moveAngle (4, 6000);
    
    BaseStepper.AngActual = 0;
    HombroStepper.AngActual = 0;
    CodoStepper.AngActual = 0;
  
    B_actual = 0;
    H_actual = 0;
    C_actual = 0;
    
    Serial.println("------- Done Homing --------");
    Hcontrol = false;
  }
  else
  {
    BaseStepper.moveAngle (0,6000);
    HombroStepper.moveAngle (0, 500);
    CodoStepper.moveAngle (0, 6000);
    Agarre.write (0);
    Gatillo.write (0);
    Muneca.write (95);
  }
}

void aimbot ()
{
  if (ang == 1)
  {
    BaseStepper.moveAngle (-32,6000);
    CodoStepper.moveAngle  (-50,6000);
    angs = 125;
    if (M_actual < angs)
    {
      for (int i = M_actual; i < angs; i++)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    else
    {
      for (int i = M_actual; i > angs; i--)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    Gatillo.write (60);
    delay (500);
    Gatillo.write (0);
  }
  
  else if (ang == 2)
  {
    BaseStepper.moveAngle  (-2,6000);
    CodoStepper.moveAngle  (-50,6000);
    angs = 125;
    if (M_actual < angs)
    {
      for (int i = M_actual; i < angs; i++)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    else
    {
      for (int i = M_actual; i > angs; i--)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    Gatillo.write (60);
    delay (500);
    Gatillo.write (0);
  }

  else if (ang == 3)
  {
    BaseStepper.moveAngle  (-30,6000);
    CodoStepper.moveAngle  (-50,6000);
    angs = 112;
    if (M_actual < angs)
    {
      for (int i = M_actual; i < angs; i++)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    else
    {
      for (int i = M_actual; i > angs; i--)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    Gatillo.write (60);
    delay (500);
    Gatillo.write (0);
  }

  else if (ang == 4)
  {
    BaseStepper.moveAngle  (-2,6000);
    CodoStepper.moveAngle  (-50,6000);
    angs = 112;
    if (M_actual < angs)
    {
      for (int i = M_actual; i < angs; i++)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    else
    {
      for (int i = M_actual; i > angs; i--)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    Gatillo.write (60);
    delay (500);
    Gatillo.write (0);
  }

  else if (ang == 5)
  {
    BaseStepper.moveAngle  (-28,6000);
    CodoStepper.moveAngle  (-50,6000);
    angs = 95;
    if (M_actual < angs)
    {
      for (int i = M_actual; i < angs; i++)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    else
    {
      for (int i = M_actual; i > angs; i--)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    Gatillo.write (60);
    delay (500);
    Gatillo.write (0);
  }

  else if (ang == 6)
  {
    BaseStepper.moveAngle  (-2,6000);
    CodoStepper.moveAngle  (-50,6000);
    angs = 100;
    if (M_actual < angs)
    {
      for (int i = M_actual; i < angs; i++)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }
    else
    {
      for (int i = M_actual; i > angs; i--)
      {
        Muneca.write (i);
        delay(td);
      }
      M_actual = angs;
    }

    Gatillo.write (60);
    delay (500);
    Gatillo.write (0);
  }
  /////////////
}
