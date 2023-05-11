#ifndef banderas_h
#define banderas_h

#include "Arduino.h"

class banderas
{
  public:
    banderas();
    
    // FUNCION DE LECTURA SIMPLE DEL MENSAJE
    void lee_n();
    
    // ESCUCHANDO
    void escucho();

    // FUNCIONES DE IMPRESION
    void imprimir();    
    void impr_band();
    void impr_mov();
    void impr_pos();
    void impr_angles();
    
  private:

    // FUNCION LECTURA
    void leer();
      
    // FUNCION DE LECTURA DE BANDERA
    void que_hago();
  
    // FUNCION DE LECTURA DE POSICION
    void donde_voy();
  
    // FUNCION DE TIPO DE MOVIMIENTO
    void which_mov();
  
    // FUNCION DE LECTURA DE POSICIONES
    void filtro_posi();
  
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
    boolean NO = false;         // CONTROL SOBRE LECTURA DE ALGUN NUMERO PARA LOOP
    
    boolean ES = false;         // ES UN NUMERO O NO
    
    boolean DO_BAN = false;     // LECTURA O CAMBIO DE BANDERA
    boolean MOVE_TYPE = false;  // LECTURA DE CAMBIO DE POSICION
    boolean MOVE_POS = false;   // POSICION
    boolean STA = false;        // LECTURA DE FASE
    
    // -------------| VARIABLES DE LECTURA |-------------
  
    // VARIABLE PARA ADQUIRIR CARACTERES DESDE EL SERIAL
    String caracteres_leidos = "";

};

#endif
