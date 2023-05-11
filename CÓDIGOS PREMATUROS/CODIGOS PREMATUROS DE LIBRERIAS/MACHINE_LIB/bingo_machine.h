#ifndef bingo_machine_h
#define bingo_machine_h

#include "Arduino.h"

class bingo_machine
{
  public:
  
    bingo_machine();

    // CONVERTIR LA ENTRADA EN UNA BANDERA
    void robot_fase(String mensaje);

  private:

    // ------------| VARIABLES DE LECTURA |------------

    char bandera;
    
    // ===============| MAQUINA DE ESTADO |===============

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
      fase_5
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
      to_5,
      reset,
      go_back
    };
    
    // DECLARACION DE UNA VARIABLE QUE INDICA EL ESTADO EN QUE SE ENCUENTRA
    STATE actual = fase_0;
    
    // DECLARACION DE UNA VARIABLE QUE INDICA INSTRUCCIONES PARA DECIDIR A CUAL ESTADO IRA SIGUIENTE
    GO cambio = start;
    
    // DECLARAR CONDICIONES DE CAMBIO
    // :: SCOPE RESOLUTION OPERATOR
    
    // ------------| CONDICIONES PARA FASE 0 |------------
    void estado_f0();

    // ------------| CONDICIONES PARA FASE 1 |------------
    void estado_f1();

    // ------------| CONDICIONES PARA FASE 2 |------------
    void estado_f2();

    // ------------| CONDICIONES PARA FASE 3 |------------
    void estado_f3();

    // ------------| CONDICIONES PARA FASE 4 |------------
    void estado_f4();

    // ------------| CONDICIONES PARA FASE 5 |------------
    void estado_f5();


    // FUNCIONAMIENTO DE LA FASE O SALIDA QUE GENERA ENTRAR EN UNA FASE
    
    // ---------------| FUNCION DE FASE 0 |---------------
    void funcion_f0();

    // ---------------| FUNCION DE FASE 1 |---------------
    void funcion_f1();

    // ---------------| FUNCION DE FASE 2 |---------------
    void funcion_f2();

    // ---------------| FUNCION DE FASE 3 |---------------
    void funcion_f3();
    
    // ---------------| FUNCION DE FASE 4 |---------------
    void funcion_f4();

    // ---------------| FUNCION DE FASE 5 |---------------
    void funcion_f5();    
    
    
    // MAQUINA- FUNCION PARA DISPARAR LOS ESTADOS Y HACER EL CAMBIO
    void machine();

    // INTERPRETACION DE DATO DE ENTRADA
    void cual_fase();

    // TRANSFORMAR LA FUNCION EN LA QUE SE ENCUENTRA A LA FASE
    void transform(int ir_a);

    // JUNTA EL LLAMADO A LAS FASES Y SU ACCION
    void DO();

};

#endif
