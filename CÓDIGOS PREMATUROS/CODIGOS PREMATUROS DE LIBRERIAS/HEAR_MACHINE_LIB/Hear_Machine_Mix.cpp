#include "Arduino.h"
#include "Hear_Machine_Mix.h"

// -----------------| INICIALIZACON |-----------------

Hear_Machine_Mix::Hear_Machine_Mix()
{}


// ------------------| LEER SERIAL |------------------
void Hear_Machine_Mix::leer(){
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
      }
      // REINICIAR EL MODO LECTURA SI SE LEE EL FINAL
      else{
        leyendo = false;
        NEW = true;
      }
    }
    
    // SI NO SE ENCUENTRA EN MODO LECTURA Y SE ENCUENTRA EL INICIO SE INICIA EL MODO LECTURA
    else if (lei == ini){
      leyendo = true;
    }
  }
}


// -------------------| DATOS DE SERIAL |-------------------

void Hear_Machine_Mix::fases(){
  
  Hear_Machine_Mix::leer(); // GUARDAR DATA DESDE EL SERIAL
  
  if (NEW == true){ // SI SE INDICA QUE HAY DATA
    
    mensaje = caracteres_leidos;
    caracteres_leidos = "";
    Hear_Machine_Mix::imprimir();       // IMPRIMIR RESULTADO

    Hear_Machine_Mix::string_to_ban();
        
    Hear_Machine_Mix::actuar();

    count = 0;    // CONTADOR DE CARACTERES
    
    NEW = false;      // REINICIAR BANDERA
  }
}


// ------------------| CONVERTIR FRASE EN BANDERA |------------------

char Hear_Machine_Mix::string_to_ban(){

if (mensaje == "START"){Serial.println("LA BANDERA ES: S"); bandera = 'S';}
if (mensaje == "FASE_1"){Serial.println("LA BANDERA ES: 1"); bandera = '1';}
else if (mensaje == "LISTO"){Serial.println("LA BANDERA ES: L"); bandera = 'L';}
else if (mensaje == "RESET"){Serial.println("LA BANDERA ES: R"); bandera = 'R';}
else if (mensaje == "BACK"){Serial.println("LA BANDERA ES: B"); bandera = 'B';}
else if (mensaje == "FASE_2"){Serial.println("LA BANDERA ES: 2"); bandera = '2';}
else if (mensaje == "FASE_3"){Serial.println("LA BANDERA ES: 3"); bandera = '3';}
else if (mensaje == "FASE_4"){Serial.println("LA BANDERA ES: 4"); bandera = '4';}
else if (mensaje == "FASE_5"){Serial.println("LA BANDERA ES: 5"); bandera = '5';}
else {bandera = 'N';}
}

// INTERPRETACION DE DATOS EN PUERTOS SERIES
void Hear_Machine_Mix::actuar()
{
    viejo = cambio;
    
    switch(bandera)
    {
      // UNA COMILLA ES EL VALOR EN ASCI DE UN CARACTER, DOS COMILLAS LO CONVIERTE EN TIPO CHAR
      case 'S': cambio = GO::start; break;
      case 'L': cambio = GO::listo; break;
      case 'R': cambio = GO::reset; break;
      case 'B': cambio = GO::go_back; break;
      case '1': cambio = GO::to_1; break;
      case '2': cambio = GO::to_2; break;
      case '3': cambio = GO::to_3; break;
      case '4': cambio = GO::to_4; break;
      case '5': cambio = GO::to_5; break;
      case 'N': cambio = viejo; Serial.println("NO ES UNA ORDEN VALIDA"); break;
      default: break;
    }
  Hear_Machine_Mix::machine();
}


// -------------------| DATOS DE SERIAL |-------------------
void Hear_Machine_Mix::numero_fases(){

  Hear_Machine_Mix::leer();
  
  if (NEW == true){ // SI SE INDICA QUE HAY DATA
  
    ES = true;
          
    for(int i=0; i<count; i++)
    { 
      if(isdigit(caracteres_leidos[i]) == false)
      {
        ES = false;
      }
    }

    if (ES == true){
      
      num = caracteres_leidos.toInt();
      caracteres_leidos = "";
      movement.pos = num;

      Hear_Machine_Mix::impr_pos();   // IMPRIMIR RESULTADO
    
      ES = false;
    }
    
    else {

      mensaje = caracteres_leidos;
      caracteres_leidos = "";
      
      Hear_Machine_Mix::imprimir();       // IMPRIMIR RESULTADO
      
      Hear_Machine_Mix::go_other_fase();
    }
    
    // VARIABLE DE CONTEO DE CARACTERES LECTURA
    count = 0;

    NEW = false;      // REINICIAR UN NUEVO MENSAJE
  }
}


// -------------------| DATOS DE SERIAL |-------------------

void Hear_Machine_Mix::go_other_fase(){

  NEW = false;  // REINICIAR BANDERA
  count = 0;    // CONTADOR DE CARACTERES

  Hear_Machine_Mix::imprimir();   // IMPRIMIR RESULTADO
  
  Hear_Machine_Mix::string_to_ban();
  
  viejo = cambio;
  
  switch(bandera)
  {
    // UNA COMILLA ES EL VALOR EN ASCI DE UN CARACTER, DOS COMILLAS LO CONVIERTE EN TIPO CHAR
    case 'S': cambio = GO::start; break;
    case 'L': cambio = GO::listo; break;
    case 'R': cambio = GO::reset; break;
    case 'B': cambio = GO::go_back; break;
    case '1': cambio = GO::to_1; break;
    case '2': cambio = GO::to_2; break;
    case '3': cambio = GO::to_3; break;
    case '4': cambio = GO::to_4; break;
    case '5': cambio = GO::to_5; break;
    case 'N': cambio = viejo; Serial.println("NO ES UNA ORDEN VALIDA"); break;
    default: break;
  }
  Hear_Machine_Mix::machine();
}


// ------------------| IMPRIMIR LO LEIDO |------------------

void Hear_Machine_Mix::imprimir(){ 
  Serial.print("ENTRADA: ");
  Serial.println(mensaje);
}

void Hear_Machine_Mix::impr_band(){
    // IMPRIMIR RESULTADO
    Serial.print("LA BANDERA ES: ");
    Serial.println(bandera);
}

void Hear_Machine_Mix::impr_mov(){
    Serial.print("EL MOVIMIENTO ES DE: ");
    Serial.println(movement.texto);
}

void Hear_Machine_Mix::impr_pos(){
    Serial.print("VA A LA POSICION: ");
    Serial.println(movement.pos);
}

void Hear_Machine_Mix::impr_angles(){
    Serial.print("LOS ANGULOS SERIAN: ");
    Serial.println(to_go);
}


// DECLARAR CONDICIONES DE CAMBIO
// :: SCOPE RESOLUTION OPERATOR

// ------------| CONDICIONES PARA FASE 0 |------------
void Hear_Machine_Mix::estado_f0()
{
  if (cambio == GO::listo || cambio == GO::go_back || cambio == GO::to_1 || cambio == GO::reset) Hear_Machine_Mix::transform(STATE::fase_1);
}

// ------------| CONDICIONES PARA FASE 1 |------------
void Hear_Machine_Mix::estado_f1()
{
  if (cambio == GO::to_2) Hear_Machine_Mix::transform(STATE::fase_2);
  else if (cambio == GO::to_3) Hear_Machine_Mix::transform(STATE::fase_3);
  else if (cambio == GO::to_4) Hear_Machine_Mix::transform(STATE::fase_4);
  else if (cambio == GO::to_5) Hear_Machine_Mix::transform(STATE::fase_5);
  else if (cambio == GO::start) Hear_Machine_Mix::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 2 |------------
void Hear_Machine_Mix::estado_f2()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) Hear_Machine_Mix::transform(STATE::fase_1);
  else if (cambio == GO::to_3) Hear_Machine_Mix::transform(STATE::fase_3);
  else if (cambio == GO::to_5) Hear_Machine_Mix::transform(STATE::fase_5);
  else if (cambio == GO::start) Hear_Machine_Mix::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 3 |------------
void Hear_Machine_Mix::estado_f3()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) Hear_Machine_Mix::transform(STATE::fase_1);
  else if (cambio == GO::to_4) Hear_Machine_Mix::transform(STATE::fase_4);
  else if (cambio == GO::to_5) Hear_Machine_Mix::transform(STATE::fase_5);
  else if (cambio == GO::start) Hear_Machine_Mix::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 4 |------------
void Hear_Machine_Mix::estado_f4()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) Hear_Machine_Mix::transform(STATE::fase_1);
  else if (cambio == GO::to_3) Hear_Machine_Mix::transform(STATE::fase_3);
  else if (cambio == GO::to_5) Hear_Machine_Mix::transform(STATE::fase_5);
  else if (cambio == GO::start) Hear_Machine_Mix::transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 5 |------------
void Hear_Machine_Mix::estado_f5()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) Hear_Machine_Mix::transform(STATE::fase_1);
  else if (cambio == GO::start) Hear_Machine_Mix::transform(STATE::fase_0);
}


// -----------------------------------------------------------------------
// FUNCIONAMIENTO DE LA FASE O SALIDA QUE GENERA ENTRAR EN UNA FASE

// ---------------| FUNCION DE FASE 0 |---------------
void Hear_Machine_Mix::funcion_f0()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("    O                    \n");

  F0 = true; F1 = false; F2 = false; F3 = false; F4 = false; F5 = false; 
}

// ---------------| FUNCION DE FASE 1 |---------------
void Hear_Machine_Mix::funcion_f1()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("        O                \n");

  F0 = false; F1 = true; F2 = false; F3 = false; F4 = false; F5 = false; 
}

// ---------------| FUNCION DE FASE 2 |---------------
void Hear_Machine_Mix::funcion_f2()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("            O            \n");

  F0 = false; F1 = false; F2 = true; F3 = false; F4 = false; F5 = false; 
  
  movement.move_type = 'C'; 
  movement.texto = "CAMARA"; 
  movement.step_limit = 50;

  Hear_Machine_Mix::impr_mov();      // IMPRIMIR RESULTADO
  
}

// ---------------| FUNCION DE FASE 3 |---------------
void Hear_Machine_Mix::funcion_f3()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                O        \n");

  F0 = false; F1 = false; F2 = false; F3 = true; F4 = false; F5 = false; 

  movement.move_type = 'V';
  movement.texto = "VUELTA EN TOMBOLA";
  movement.step_limit = 50;

 Hear_Machine_Mix::impr_mov();      // IMPRIMIR RESULTADO

}

// ---------------| FUNCION DE FASE 4 |---------------
void Hear_Machine_Mix::funcion_f4()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                    O    \n");

  F0 = false; F1 = false; F2 = false; F3 = false; F4 = true; F5 = false; 
  
  movement.move_type = 'P'; 
  movement.texto = "PIEZA";  
  movement.step_limit = 3;

  Hear_Machine_Mix::impr_mov();      // IMPRIMIR RESULTADO

  movement.move_type = 'T'; 
  movement.texto = "TABLA DE BINGO";  
  movement.step_limit = 50;

  Hear_Machine_Mix::impr_mov();      // IMPRIMIR RESULTADO
}

// ---------------| FUNCION DE FASE 5 |---------------
void Hear_Machine_Mix::funcion_f5()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                        O\n");
  F0 = false; F1 = false; F2 = false; F3 = false; F4 = false; F5 = true; 
}

// MAQUINA- FUNCION PARA DISPARAR LOS ESTADOS Y HACER EL CAMBIO
void Hear_Machine_Mix::machine()
{
  switch(actual)
  {
    case fase_0: estado_f0(); break;
    case fase_1: estado_f1(); break;
    case fase_2: estado_f2(); break;
    case fase_3: estado_f3(); break;
    case fase_4: estado_f4(); break;
    case fase_5: estado_f5(); break;
  }
}

// TRANSFORMAR LA FUNCION EN LA QUE SE ENCUENTRA A LA FASE
void Hear_Machine_Mix::transform(int ir_a)
{
  actual = ir_a;

  switch(actual)
  {
    case STATE::fase_0:funcion_f0(); break;
    case STATE::fase_1:funcion_f1(); break;
    case STATE::fase_2:funcion_f2(); break;
    case STATE::fase_3:funcion_f3(); break;
    case STATE::fase_4:funcion_f4(); break;
    case STATE::fase_5:funcion_f5(); break;
    default: break; 
  }
}

// LECTURA DE UNA VARIABLE
void Hear_Machine_Mix::lectura()
{
  if(F0 == true || F1 == true || F5 == true || F3 == true)
  {
    Hear_Machine_Mix::fases();
  }
  else if(F4 == true || F2 == true)
  {
    Hear_Machine_Mix::numero_fases();
  }
}
