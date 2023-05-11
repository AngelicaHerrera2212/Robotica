#include "Arduino.h"
#include "banderas.h"

banderas::banderas(){
}

void banderas::imprimir(){
  Serial.print("ENTRADA: ");
  Serial.println(mensaje);
}

void banderas::impr_band(){
  Serial.print("LA BANDERA ES: ");
  Serial.println(bandera);
}

void banderas::impr_mov(){ 
  Serial.print("EL MOVIMIENTO ES DE: ");
  Serial.println(movement.texto);
}

void banderas::impr_pos(){  
  Serial.print("VA A LA POSICION: ");
  Serial.println(movement.pos);
}

void banderas::impr_angles(){  
  Serial.print("LOS ANGULOS SERIAN: ");
  Serial.println(to_go);
}

void banderas::leer(){

// -------------| VARIABLES DE LECTURA |-------------

// LEYENDO LA FRASE
  static boolean leyendo = false;
    
// VARIABLE DE LECTURA DE LOS CARACTERES INDIVIDUAL
  char lei;

// --------------| FUNCION DE LECTURA |--------------

  // SI HAY ALGO QUE NO SEA CERO
  while(Serial.available() > 0 && NEW == false){
  
    // CAPTURA EL CARACTER DEL SERIAL
    lei = (char)Serial.read();

    // SI ESTA EN MODO DE LECTURA
    if (leyendo == true){
      
      // SI NO SE LEE EL FINAL SE GUARDA EL VALOR EN LA MATRIZ Y AUMENTA EL ID
      if (lei != fin){
        caracteres_leidos += lei;
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

void banderas::lee_n(){

// -------------| VARIABLES DE LECTURA |-------------

// LEYENDO LA FRASE
  static boolean leyendo = false;
    
// VARIABLE DE LECTURA DE LOS CARACTERES INDIVIDUAL
  char lei;
 
// --------------| FUNCION DE LECTURA |--------------
        
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
  banderas::filtro_posi();  // PARA CHEQUEAR SI LO QUE SE LEYO ERA UN NUMERO
}

void banderas::filtro_posi(){
  
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
      
      NO = true;    // HAY UN NUMERO AHI
      banderas::impr_pos();   // IMPRIMIR RESULTADO
    
      ES = false; 
    }
    
    else {
      mensaje = caracteres_leidos;
      caracteres_leidos = "";

      banderas::imprimir();       // IMPRIMIR RESULTADO
            
      // BANDERAS Y CAMBIAR
      if (mensaje == "CAM"){movement.move_type = 'C'; movement.texto = "CAMARA"; movement.step_limit = 50;}
      else if (mensaje == "PIZ"){movement.move_type = 'P'; movement.texto = "PIEZA";  movement.step_limit = 3;}
      else if (mensaje == "TAB"){movement.move_type = 'T'; movement.texto = "TABLA DE BINGO";  movement.step_limit = 50;}
      else if (mensaje == "TOMB"){movement.move_type = 'V'; movement.texto = "VUELTA EN TOMBOLA";  movement.step_limit = 45;}
      else {movement.move_type = 'N'; movement.texto = "TIPO NO VIABLE";}
  
      banderas::impr_mov();      // IMPRIMIR RESULTADO     
    }
    
    // VARIABLE DE CONTEO DE CARACTERES LECTURA
    count = 0;

    NEW = false;      // REINICIAR UN NUEVO MENSAJE
  }
}

void banderas::escucho(){

  banderas::leer(); // GUARDAR DATA DESDE EL SERIAL
  
  if (NEW == true){ // SI SE INDICA QUE HAY DATA
    
    mensaje = caracteres_leidos;
    caracteres_leidos = "";
    
    banderas::imprimir();       // IMPRIMIR RESULTADO
    
    DO_BAN = true;    // HAY CAMBIO DE BANDERA PARA TIPO
    NEW = false;      // REINICIAR UN NUEVO MENSAJE
  }
}

void banderas::que_hago(){

  banderas::escucho(); // GUARDAR DATA DESDE EL SERIAL
  
  // LEER EL SERIAL Y TRANSFORMAR EN BANDERA
  if (DO_BAN == true){   // SI SE INDICA QUE HAY DATA
            
    // BANDERAS Y CAMBIAR
    if (mensaje == "START"){bandera = 'S';}
    else if (mensaje == "FASE_1"){bandera = '1';}
    else if (mensaje == "LISTO"){bandera = 'L';}
    else if (mensaje == "RESET"){bandera = 'R';}
    else if (mensaje == "BACK"){bandera = 'B';}
    else if (mensaje == "FASE_2"){bandera = '2';}
    else if (mensaje == "FASE_3"){bandera = '3';}
    else if (mensaje == "FASE_4"){bandera = '4';}
    else if (mensaje == "FASE_5"){bandera = '5';}
    else {bandera = 'N';}

    banderas::impr_band();      // IMPRIMIR RESULTADO

    DO_BAN = false;      // REINICIAR BAND
    STA = true;       // REINICIAR BANDERA
  }
}

/*
void banderas::which_mov(){

  escucho(); // GUARDAR DATA DESDE EL SERIAL
  
  // LEER EL SERIAL Y TRANSFORMAR EN BANDERA
  if (MOVE_TYPE == true){   // SI SE INDICA QUE HAY DATA
            
    // BANDERAS Y CAMBIAR
    if (mensaje == "CAM"){movement.move_type = 'C'; movement.texto = "CAMARA"; movement.step_limit = 50;}
    else if (mensaje == "PIZ"){movement.move_type = 'P'; movement.texto = "PIEZA";  movement.step_limit = 3;}
    else if (mensaje == "TAB"){movement.move_type = 'T'; movement.texto = "TABLA DE BINGO";  movement.step_limit = 50;}
    else if (mensaje == "TOMB"){movement.move_type = 'V'; movement.texto = "VUELTA EN TOMBOLA";  movement.step_limit = 45;}
    else {movement.move_type = 'N'; movement.texto = "TIPO NO VIABLE";}

    impr_mov();      // IMPRIMIR RESULTADO

    MOVE_TYPE = false;
    DO_BAN = false;      // REINICIAR BAND
    MOVE_POS = true;       // REINICIAR BANDERA
  }
}

void banderas::donde_voy(){

  which_mov();

  // LEER EL SERIAL Y TRANSFORMAR EN BANDERA
  if (MOVE_POS == true){   // SI SE INDICA QUE HAY DATA

    lee_n();
    
    switch(movement.move_type){
      case 'C': {to_go = PIE[movement.pos-1]; break;}
      case 'P': {to_go = TABE[movement.pos-1]; break;}
      case 'T': {to_go = CAME[movement.pos-1]; break;}      
      case 'N': Serial.println("NO ES UNA ORDEN VALIDA"); break;
      default: break;
    }
    
    impr_angles();

    NO = false;
    MOVE_POS = false;   // REINICIAR BANDERA
  
  }
}
*/
