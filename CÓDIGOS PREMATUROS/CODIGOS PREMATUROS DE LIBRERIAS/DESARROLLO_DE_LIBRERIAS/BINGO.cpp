#include <MOVE_ANG.h>

#include "Arduino.h"
#include "BINGO.h"

#include <LIB_SING_REDUCE.h>
#include <notas.h>


// -----------------| INICIALIZACON |-----------------

BINGO::BINGO()
{
  
}

// ------------------| LEER SERIAL |------------------
void BINGO::leer(){
  static boolean leyendo = false;
  char ini = '<';
  char fin = '>';
  char lei;
  
  // SI HAY ALGO QUE NO SEA CERO
  while(Serial.available() > 0 && NEW == false){
  
    // CAPTURA EL CARACTER DEL SERIAL
    lei = (char)Serial.read();
    
    // SI ESTA EN MODO DE LECTURA
    if (leyendo == true){
      
      // SI NO SE LEE EL FINAL SE GUARDA EL VALOR EN LA MATRIZ Y AUMENTA EL ID
      if (lei != fin){
        caracteres_leidos += lei;
        count += 1;

        // SI TIENE UN SEPARADOR ES ANGULO
        if (lei == sep){
          ANG = true;
        }
      }

      // REINICIAR EL MODO LECTURA SI SE LEE EL FINAL
      else{
        leyendo = false;        
        NEW = true;
        
        mensaje = caracteres_leidos;
        caracteres_leidos = "";
        
      }
    }
    
    // SI NO SE ENCUENTRA EN MODO LECTURA Y SE ENCUENTRA EL INICIO SE INICIA EL MODO LECTURA
    else if (lei == ini){
      leyendo = true;
    }
  }
}


// -------------------| DATOS DE SERIAL |-------------------

void BINGO::accion(){
  
  BINGO::leer(); // GUARDAR DATA DESDE EL SERIAL
  
  if (NEW == true){ // SI SE INDICA QUE HAY DATA

    if(ANG == true){

      Serial.println("POSIBLE MOVIMIENTO");

      delay(500);

      BINGO::mover();

      ANG = false;
    }
    else{
      
      Serial.println("POSIBLE ORDEN");
      
      delay(500);

      BINGO::act();
      
    }

    // VARIABLE DE CONTEO DE CARACTERES LECTURA
    count = 0;

    NEW = false;      // REINICIAR BANDERA
  }
}


// -------------------| DATOS DE SERIAL |-------------------
void BINGO::mover(){

  int j = 0;
  
  ES = true;
         
  for(int i=0; i<count; i++)
  {
    
    if(mensaje[i] == sep)
    {
     
      j += 1;
      
    }
      
    else
    {

      // && (mensaje[i] != '-') SE LE QUITO PARA QUE NO PERMITA ANGULOS NEGATIVOS
      if(isdigit(mensaje[i]) == false && (mensaje[i] != '.'))
      {
        ES = false;
      }

      DIV[j] += mensaje[i];
    }
  }

  for(int i = 0; i <= j; i++)
  {
    SERV[i] = DIV[i].toFloat();   
    DIV[i] = "";  
  }
  
  // SERVOS PRINT

/*     
  Serial.println(ES);
  Serial.println(SERV[0]);
  Serial.println(SERV[1]);
  Serial.println(SERV[2]);
  Serial.println(SERV[3]);
  Serial.println(SERV[4]);
  Serial.println(SERV[5]);
*/
  if(ES == true){
    if (indicador == fase_2)
    {
      MOVE.JUST_GO(SERV[0], SERV[1], SERV[2]);
      Serial.print("POSICION ALCANZADA");
    }
    
    else if (indicador == fase_3)
    {
      MOVE.SIMPLE(SERV[0], SERV[1], SERV[2]);
      Serial.print("TOMBOLA DID");
    }
    
    else if (indicador == fase_4)
    {
      MOVE.LLEVAR(SERV[0], SERV[1], SERV[2], SERV[3], SERV[4], SERV[5]);
    
      Serial.print("PIEZA PUESTA");
    }
  }

  else
  {
    Serial.print("NO SON ANGULOS VALIDOS");
  }

}


// ------------------| CONVERTIR FRASE EN BANDERA |------------------

void BINGO::act(){

if (mensaje == "START"){cambio = GO::start; BINGO::machine();}
else if (mensaje == "LISTO"){cambio = GO::listo; BINGO::machine();}
else if (mensaje == "RESET"){cambio = GO::re_set; BINGO::machine();}
else if (mensaje == "FASE_1"){cambio = GO::to_1; BINGO::machine();}
else if (mensaje == "FASE_2"){cambio = GO::to_2; BINGO::machine();}
else if (mensaje == "FASE_3"){cambio = GO::to_3; BINGO::machine();}
else if (mensaje == "FASE_4"){cambio = GO::to_4; BINGO::machine();}
else if (mensaje == "LOSE"){BUZZ.play(0); delay(500); Serial.print("PERDI");}
else if (mensaje == "WIN"){BUZZ.play(4); delay(500); Serial.print("GANE");}
else if (mensaje == "NEXIS"){BUZZ.play(7); delay(500); Serial.print("NO_EXISTE");}
else if (mensaje == "LEIDO"){BUZZ.play(8); delay(500); Serial.print("LEI");}
else if (mensaje == "OPEN"){MOVE.OPEN(); delay(500); Serial.print("IS OPEN");}
else if (mensaje == "CLOSE"){MOVE.CLOSE(); delay(500); Serial.print("IS CLOSE");}
else if (mensaje == "CLOSE_TOM"){MOVE.CLOSE_TOM(); delay(500); Serial.print("IS TOM CLOSE");}
else if (mensaje == "GO_UP"){MOVE.LIFT(); delay(500); Serial.print("IT IS LIFT");}

else {Serial.print("NO ES UNA ORDEN VALIDA");}
}

// MAQUINA- FUNCION PARA DISPARAR LOS ESTADOS Y HACER EL CAMBIO
void BINGO::machine()
{
  switch(actual)
  {
    case fase_0: estado_f0(); break;
    case fase_1: estado_f1(); break;
    case fase_2: estado_f2(); break;
    case fase_3: estado_f3(); break;
    case fase_4: estado_f4(); break;
  }
}

// TRANSFORMAR LA FUNCION EN LA QUE SE ENCUENTRA A LA FASE
void BINGO::transform(int ir_a)
{
  actual = ir_a;

  switch(actual)
  {
    case STATE::fase_0:funcion_f0(); break;
    case STATE::fase_1:funcion_f1(); break;
    case STATE::fase_2:funcion_f2(); break;
    case STATE::fase_3:funcion_f3(); break;
    case STATE::fase_4:funcion_f4(); break;
    default: break; 
  }
}

// DECLARAR CONDICIONES DE CAMBIO
// :: SCOPE RESOLUTION OPERATOR

// ------------| CONDICIONES PARA FASE 0 |------------
void BINGO::estado_f0()
{
  if (cambio == GO::start) BINGO::transform(STATE::fase_0);
  else if ((cambio == GO::listo || cambio == GO::to_1 || cambio == GO::re_set) && (indicador == fase_0)) BINGO::transform(STATE::fase_1);

}

// ------------| CONDICIONES PARA FASE 1 |------------
void BINGO::estado_f1()
{
  if (cambio == GO::to_2) BINGO::transform(STATE::fase_2);
  else if (cambio == GO::to_3) BINGO::transform(STATE::fase_3);
  else if (cambio == GO::to_4) BINGO::transform(STATE::fase_4);
  else if (cambio == GO::start) BINGO::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 2 |------------
void BINGO::estado_f2()
{
  if (cambio == GO::re_set || cambio == GO::to_1) BINGO::transform(STATE::fase_1);
  else if (cambio == GO::to_2) BINGO::transform(STATE::fase_2);
  else if (cambio == GO::to_3) BINGO::transform(STATE::fase_3);
  else if (cambio == GO::to_4) BINGO::transform(STATE::fase_4);
  else if (cambio == GO::start) BINGO::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 3 |------------
void BINGO::estado_f3()
{
  if (cambio == GO::re_set || cambio == GO::to_1) BINGO::transform(STATE::fase_1);
  else if (cambio == GO::to_4) BINGO::transform(STATE::fase_4);
  else if (cambio == GO::to_2) BINGO::transform(STATE::fase_2);
  else if (cambio == GO::start) BINGO::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 4 |------------
void BINGO::estado_f4()
{
  if (cambio == GO::re_set || cambio == GO::to_1) BINGO::transform(STATE::fase_1);
  else if (cambio == GO::to_3) BINGO::transform(STATE::fase_3);
  else if (cambio == GO::to_2) BINGO::transform(STATE::fase_2);
  else if (cambio == GO::to_4) BINGO::transform(STATE::fase_4);
  else if (cambio == GO::start) BINGO::transform(STATE::fase_0);
}


// -----------------------------------------------------------------------
// FUNCIONAMIENTO DE LA FASE O SALIDA QUE GENERA ENTRAR EN UNA FASE

// ---------------| FUNCION DE FASE 0 |---------------
void BINGO::funcion_f0()
{
  //Serial.println("F:  0   1   2   3   4   5");
  //Serial.println("    O                    \n");

  indicador = fase_0;

  MOVE.INICIA(10,11,6,9);

  BUZZ.play(1);
  
  delay(200);

  Serial.print("READY");
  
}

// ---------------| FUNCION DE FASE 1 |---------------
void BINGO::funcion_f1()
{
  //Serial.println("F:  0   1   2   3   4   5");
  //Serial.println("        O                \n");

  indicador = fase_1;

  BUZZ.play(2);

  MOVE.OPEN();

  MOVE.LIFT();
  
  MOVE.GO_TO_0();

  delay(200);

  Serial.print("FASE_1");
  
}

// ---------------| FUNCION DE FASE 2 |---------------
void BINGO::funcion_f2()
{
  //Serial.println("F:  0   1   2   3   4   5");
  //Serial.println("            O            \n");

  indicador = fase_2;
  
  BUZZ.play(3);

  delay(200);
 
  Serial.print("FASE_2");
  
}

// ---------------| FUNCION DE FASE 3 |---------------
void BINGO::funcion_f3()
{
  //Serial.println("F:  0   1   2   3   4   5");
  //Serial.println("                O        \n");

  indicador = fase_3;

  BUZZ.play(4);
  
// ACCION
  delay(200);

  Serial.print("FASE_3");
}

// ---------------| FUNCION DE FASE 4 |---------------
void BINGO::funcion_f4()
{
  //Serial.println("F:  0   1   2   3   4   5");
  //Serial.println("                    O    \n");

  indicador = fase_4;

  BUZZ.play(5);

  delay(200);
  
  Serial.print("FASE_4");
  
}

/////////////////////////////////////////////////////////////////
