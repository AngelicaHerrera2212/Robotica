#include <MOVE_ANG.h>

#include <LIB_SING_REDUCE.h>
#include <notas.h>

#ifndef BINGO_h
#define BINGO_h
#include "Arduino.h"



class BINGO
{

  public:
      
      BINGO();

      // DIFERENCIACION ENTRE LECTURA DE ORDENES Y LECTURA DE ORDENES-NUMEROS
      void accion();
      
  private:

  
  // FUNCION DE LECTURA SIMPLE DEL MENSAJE
    void leer();
  
  // -------------------| DATOS DE SERIAL |-------------------
    void mover();
  
  // INTERPRETACION DE DATOS EN PUERTOS SERIES
    void act();
  
  // MAQUINA- FUNCION PARA DISPARAR LOS ESTADOS Y HACER EL CAMBIO
    void machine();
  
  // TRANSFORMAR LA FUNCION EN LA QUE SE ENCUENTRA A LA FASE
    void transform(int);
  
  // DECLARAR CONDICIONES DE CAMBIO
  // :: SCOPE RESOLUTION OPERATOR
    void estado_f0();
    void estado_f1();
    void estado_f2();
    void estado_f3();
    void estado_f4();
  
  // -----------------------------------------------------------------------
  // FUNCIONAMIENTO DE LA FASE O SALIDA QUE GENERA ENTRAR EN UNA FASE
  // -----------------------------------------------------------------------
    void funcion_f0();
    void funcion_f1();
    void funcion_f2();
    void funcion_f3();
    void funcion_f4();
  
  // ----------| VARIABLES DE TERMINADORES |----------
    
  // -------------------| ESTADOS |-------------------
  
    boolean NEW = false;        // CONTROL SOBRE LECTURA DE ALGUN VALOR 
    boolean ANG = false;        // LECTURA DE ANGULO
    boolean ES = false;         // ES UN NUMERO O NO
  
  
  // VARIABLE PARA ADQUIRIR CARACTERES DESDE EL SERIAL
    String caracteres_leidos = "";
    String mensaje = "";
    int count = 0;
    char sep = ',';

  // ENUM NOS AYUDA A DECLARAR UN TIPO DE VARIABLE STATE QUE TENGA 5 POSIBLES VALORES (FASES)
  //  The enumerator names are usually identifiers that behave as constants in the language.
  // POSIBLES ESTADOS
    enum STATE
    {
      fase_0,
      fase_1,
      fase_2,
      fase_3,
      fase_4,
    };
  
  // CONDICIONALES DE CAMBIO
    enum GO
    {
      start,
      listo,
      to_1,
      to_2,
      to_3,
      to_4,
      re_set
    };
  
  // DECLARACION DE UNA VARIABLE QUE INDICA EL ESTADO EN QUE SE ENCUENTRA
    STATE actual = fase_0, indicador = fase_4;
  
  // DECLARACION DE UNA VARIABLE QUE INDICA INSTRUCCIONES PARA DECIDIR A CUAL ESTADO IRA SIGUIENTE
    GO cambio = start;

 // VALOR DE ANGULOS RESCATADOS
 String DIV[6] = {"", "", "", "", "", ""};
 float SERV[6] = {0, 0, 0, 0, 0, 0};

 MOVE_ANG MOVE;
 LIB_SING_REDUCE BUZZ;

};

#endif
