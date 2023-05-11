#include "Arduino.h"
#include "bingo_machine.h"

bingo_machine::bingo_machine()
{}

// ---------------------------------------- LECTURA DE LA BANDERA

void bingo_machine::robot_fase(String mensaje)
{
  if (mensaje == "START"){Serial.println("LA BANDERA ES: S"); bandera = 'S';}
  else if (mensaje == "FASE_1"){Serial.println("LA BANDERA ES: 1"); bandera = '1';}
  else if (mensaje == "LISTO"){Serial.println("LA BANDERA ES: L"); bandera = 'L';}
  else if (mensaje == "RESET"){Serial.println("LA BANDERA ES: R"); bandera = 'R';}
  else if (mensaje == "BACK"){Serial.println("LA BANDERA ES: B"); bandera = 'B';}
  else if (mensaje == "FASE_2"){Serial.println("LA BANDERA ES: 2"); bandera = '2';}
  else if (mensaje == "FASE_3"){Serial.println("LA BANDERA ES: 3"); bandera = '3';}
  else if (mensaje == "FASE_4"){Serial.println("LA BANDERA ES: 4"); bandera = '4';}
  else if (mensaje == "FASE_5"){Serial.println("LA BANDERA ES: 5"); bandera = '5';}
  else {bandera = 'N';}

  bingo_machine::DO();
  
}


// ---------------------------------------- FUNCIONAMIENTO DE LA MAQUINA
void bingo_machine::machine()
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

void bingo_machine::transform(int ir_a)
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

void bingo_machine::cual_fase()
{
  cambio = GO::start;
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
    case 'N': Serial.println("NO ES UNA ORDEN VALIDA"); break;
    default: break;
    }
}

void bingo_machine::DO()
{
  bingo_machine::cual_fase();
  bingo_machine::machine();
}


// ---------------------------------------- CONDICIONES DE CAMBIO DE FASE
void bingo_machine::estado_f0()
{
  if (cambio == GO::listo || cambio == GO::go_back || cambio == GO::to_1 || cambio == GO::reset) transform(STATE::fase_1);
}

void bingo_machine::estado_f1()
{
  if (cambio == GO::to_2) transform(STATE::fase_2);
  else if (cambio == GO::to_3) transform(STATE::fase_3);
  else if (cambio == GO::to_4) transform(STATE::fase_4);
  else if (cambio == GO::to_5) transform(STATE::fase_5);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

void bingo_machine::estado_f2()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

void bingo_machine::estado_f3()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

void bingo_machine::estado_f4()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
  else if (cambio == GO::to_5) transform(STATE::fase_5);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

void bingo_machine::estado_f5()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

// ---------------------------------------- FUNCION DE LAS FASES
void bingo_machine::funcion_f0()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("    O                    \n");
}

void bingo_machine::funcion_f1()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("        O                \n");
}

void bingo_machine::funcion_f2()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("            O            \n");
}

void bingo_machine::funcion_f3()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                O        \n");
}

void bingo_machine::funcion_f4()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                    O    \n");
}

void bingo_machine::funcion_f5()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                        O\n");
}
