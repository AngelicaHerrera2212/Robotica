#ifndef Hear_Machine_Mix_h
#define Hear_Machine_Mix_h

#include "Arduino.h"

class Hear_Machine_Mix
{

  public:
      
      Hear_Machine_Mix();

      // DIFERENCIACION ENTRE LECTURA DE ORDENES Y LECTURA DE ORDENES-NUMEROS
      void lectura();
      
  private:
  // FUNCION DE LECTURA SIMPLE DEL MENSAJE
    void leer();
  
  // -------------------| DATOS DE SERIAL |-------------------
    void fases();
    void numero_fases();
  
  // BANDERAS
    char string_to_ban();
    void go_other_fase();
  
  // INTERPRETACION DE DATOS EN PUERTOS SERIES
    void actuar();
  
  // MAQUINA- FUNCION PARA DISPARAR LOS ESTADOS Y HACER EL CAMBIO
    void machine();
  
  // TRANSFORMAR LA FUNCION EN LA QUE SE ENCUENTRA A LA FASE
    void transform(int);
  
  // ------------------| IMPRIMIR LO LEIDO |------------------
    void imprimir();
    void impr_band();
    void impr_mov();
    void impr_pos();
    void impr_angles();
  
  // DECLARAR CONDICIONES DE CAMBIO
  // :: SCOPE RESOLUTION OPERATOR
    void estado_f0();
    void estado_f1();
    void estado_f2();
    void estado_f3();
    void estado_f4();
    void estado_f5();
  
  // -----------------------------------------------------------------------
  // FUNCIONAMIENTO DE LA FASE O SALIDA QUE GENERA ENTRAR EN UNA FASE
  // -----------------------------------------------------------------------
    void funcion_f0();
    void funcion_f1();
    void funcion_f2();
    void funcion_f3();
    void funcion_f4();
    void funcion_f5();
  
  // ESTRUCTURA DE POSICIONES
    typedef struct ir {
      int pos;          // POSICION LEIDA
      char move_type;   // BANDERA CAMARA O PIEZA
      String texto;     // BANDERA ESCRITA
      int step_limit;   // LIMITE DE POSICIONES
    } point;
  
    point movement;
  
  // ANGULOS DE POSIONAMIENTO
    int PIE[3]={1, 2, 3}, TABE[3]={4, 5, 6}, CAME[3]={7, 8, 9}, to_go;
  
  // BANDERAS DE FASE
    boolean F0 = true, F1 = false, F2 = false, F3 = false, F4 = false, F5 = false;
  
  // ----------| VARIABLES DE TERMINADORES |----------
  
  // CARACTERES DE BANDERA DE ACCIONES
    char ini = '<';
    char fin = '>';
  
  // -------------------| ENTRADAS |-------------------  
  
    int num;                // POSICION DE BRAZO
    String mensaje = "";    // MENSAJE LEIDO DESDE EL SERIAL
    char bandera = 'S';     // BANDERAS DE FASES
    int count = 0;          // CONTADOR DE CARACTERES
  
  // -------------------| ESTADOS |-------------------
  
    boolean NEW = false;        // CONTROL SOBRE LECTURA DE ALGUN VALOR 
    boolean STA = false;        // LECTURA DE FASE
    boolean ES = false;         // ES UN NUMERO O NO
  
  
  // VARIABLE PARA ADQUIRIR CARACTERES DESDE EL SERIAL
    String caracteres_leidos = "";
  
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
    GO cambio = start, viejo = start;  

};

#endif
