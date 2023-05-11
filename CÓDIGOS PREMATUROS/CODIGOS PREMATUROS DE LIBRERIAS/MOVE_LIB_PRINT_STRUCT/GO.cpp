#include "GO.h"
#include "Arduino.h"

GO::GO()
{}

/////////////////////////////////////////////////////////////////////////////////

void GO::COPY(const float C[]){

  for(o = 0; o < 3; o++){
    IR[o] = C[o];
    Serial.println(IR[o]);
  }
}

////////////////////////////////////////////////////////////////////////////

void GO::UP(){

  LLEVAR.LIFT();

}

/////////////////////////////////////////////////////////////////////////////////

void GO::GO_0 (){

  LLEVAR.GO_TO_0();

}

/////////////////////////////////////////////////////////////////////////////////

void GO::SOLO_IR(float G1, float G2, float G3){
  
  LLEVAR.POSITION(G1, G2, G3);

}

/////////////////////////////////////////////////////////////////////////////////

void GO::CLOSE(){
  
  LLEVAR.PINZA_PLEASE();

}

/////////////////////////////////////////////////////////////////////////////////

void GO::OPEN(){
  
  LLEVAR.PINZA_NO();

}

///////////////////////////////////////////////////////////////////////////////////

void GO::TOMAR_PIEZA(int P){

  switch(P){
    case 1:
      GO::COPY(P_PZ.P1);
      break;
    case 2:
      GO::COPY(P_PZ.P2);
      break;
    case 3:
      GO::COPY(P_PZ.P3);
      break;
    default:
      GO::COPY(P_CEN.P0);
      break;
  }

  LLEVAR.PICK(IR[0], IR[1], IR[2]);
}

///////////////////////////////////////////////////////////////////////////////////

void GO::COLOCAR_PIEZA(int P){
  
  switch(P){
    case 1:
      GO::COPY(P_TB.P1);
      break;
    case 2:
      GO::COPY(P_TB.P2);
      break;
    case 3:
      GO::COPY(P_TB.P3);
      break;
    case 4:
      GO::COPY(P_TB.P4);
      break;
    case 5:
      GO::COPY(P_TB.P5);
      break;
    case 6:
      GO::COPY(P_TB.P6);
      break;
    case 7:
      GO::COPY(P_TB.P7);
      break;
    case 8:
      GO::COPY(P_TB.P8);
      break;
    case 9:
      GO::COPY(P_TB.P9);
      break;
    case 10:
      GO::COPY(P_TB.P10);
      break;

    case 11:
      GO::COPY(P_TB.P11);
      break;
    case 12:
      GO::COPY(P_TB.P12);
      break;
    case 13:
      GO::COPY(P_TB.P13);
      break;
    case 14:
      GO::COPY(P_TB.P14);
      break;
    case 15:
      GO::COPY(P_TB.P15);
      break;
    case 16:
      GO::COPY(P_TB.P16);
      break;
    case 17:
      GO::COPY(P_TB.P17);
      break;
    case 18:
      GO::COPY(P_TB.P18);
      break;
    case 19:
      GO::COPY(P_TB.P19);
      break;
    case 20:
      GO::COPY(P_TB.P20);
      break;

    case 21:
      GO::COPY(P_TB.P21);
      break;
    case 22:
      GO::COPY(P_TB.P22);
      break;
    case 23:
      GO::COPY(P_TB.P23);
      break;
    case 24:
      GO::COPY(P_TB.P24);
      break;
    case 25:
      GO::COPY(P_TB.P25);
      break;
    case 26:
      GO::COPY(P_TB.P26);
      break;
    case 27:
      GO::COPY(P_TB.P27);
      break;
    case 28:
      GO::COPY(P_TB.P28);
      break;
    case 29:
      GO::COPY(P_TB.P29);
      break;
    case 30:
      GO::COPY(P_TB.P30);
      break;

    case 31:
      GO::COPY(P_TB.P31);
      break;
    case 32:
      GO::COPY(P_TB.P32);
      break;
    case 33:
      GO::COPY(P_TB.P33);
      break;
    case 34:
      GO::COPY(P_TB.P34);
      break;
    case 35:
      GO::COPY(P_TB.P35);
      break;
    case 36:
      GO::COPY(P_TB.P36);
      break;
    case 37:
      GO::COPY(P_TB.P37);
      break;
    case 38:
      GO::COPY(P_TB.P38);
      break;
    case 39:
      GO::COPY(P_TB.P39);
      break;
    case 40:
      GO::COPY(P_TB.P40);
      break;

    case 41:
      GO::COPY(P_TB.P41);
      break;
    case 42:
      GO::COPY(P_TB.P42);
      break;
    case 43:
      GO::COPY(P_TB.P43);
      break;
    case 44:
      GO::COPY(P_TB.P44);
      break;
    case 45:
      GO::COPY(P_TB.P45);
      break;
    case 46:
      GO::COPY(P_TB.P46);
      break;
    case 47:
      GO::COPY(P_TB.P47);
      break;
    case 48:
      GO::COPY(P_TB.P48);
      break;
    case 49:
      GO::COPY(P_TB.P49);
      break;
    case 50:
      GO::COPY(P_TB.P50);
      break;
      
    default:
      GO::COPY(P_CEN.P0);
      break;
  }
  
  LLEVAR.PLACE(IR[0], IR[1], IR[2]);
}

///////////////////////////////////////////////////////////////////////////////////

void GO::POSICIONAR_CAM(int P){
  switch(P){
    case 1:
      GO::COPY(P_CAM.P1);
      break;
    case 2:
      GO::COPY(P_CAM.P2);
      break;
    case 3:
      GO::COPY(P_CAM.P3);
      break;
    case 4:
      GO::COPY(P_CAM.P4);
      break;
    case 5:
      GO::COPY(P_CAM.P5);
      break;
    case 6:
      GO::COPY(P_CAM.P6);
      break;
    case 7:
      GO::COPY(P_CAM.P7);
      break;
    case 8:
      GO::COPY(P_CAM.P8);
      break;
    case 9:
      GO::COPY(P_CAM.P9);
      break;
    case 10:
      GO::COPY(P_CAM.P10);
      break;

    case 11:
      GO::COPY(P_CAM.P11);
      break;
    case 12:
      GO::COPY(P_CAM.P12);
      break;
    case 13:
      GO::COPY(P_CAM.P13);
      break;
    case 14:
      GO::COPY(P_CAM.P14);
      break;
    case 15:
      GO::COPY(P_CAM.P15);
      break;
    case 16:
      GO::COPY(P_CAM.P16);
      break;
    case 17:
      GO::COPY(P_CAM.P17);
      break;
    case 18:
      GO::COPY(P_CAM.P18);
      break;
    case 19:
      GO::COPY(P_CAM.P19);
      break;
    case 20:
      GO::COPY(P_CAM.P20);
      break;

    case 21:
      GO::COPY(P_CAM.P21);
      break;
    case 22:
      GO::COPY(P_CAM.P22);
      break;
    case 23:
      GO::COPY(P_CAM.P23);
      break;
    case 24:
      GO::COPY(P_CAM.P24);
      break;
    case 25:
      GO::COPY(P_CAM.P25);
      break;
    case 26:
      GO::COPY(P_CAM.P26);
      break;
    case 27:
      GO::COPY(P_CAM.P27);
      break;
    case 28:
      GO::COPY(P_CAM.P28);
      break;
    case 29:
      GO::COPY(P_CAM.P29);
      break;
    case 30:
      GO::COPY(P_CAM.P30);
      break;

    case 31:
      GO::COPY(P_CAM.P31);
      break;
    case 32:
      GO::COPY(P_CAM.P32);
      break;
    case 33:
      GO::COPY(P_CAM.P33);
      break;
    case 34:
      GO::COPY(P_CAM.P34);
      break;
    case 35:
      GO::COPY(P_CAM.P35);
      break;
    case 36:
      GO::COPY(P_CAM.P36);
      break;
    case 37:
      GO::COPY(P_CAM.P37);
      break;
    case 38:
      GO::COPY(P_CAM.P38);
      break;
    case 39:
      GO::COPY(P_CAM.P39);
      break;
    case 40:
      GO::COPY(P_CAM.P40);
      break;

    case 41:
      GO::COPY(P_CAM.P41);
      break;
    case 42:
      GO::COPY(P_CAM.P42);
      break;
    case 43:
      GO::COPY(P_CAM.P43);
      break;
    case 44:
      GO::COPY(P_CAM.P44);
      break;
    case 45:
      GO::COPY(P_CAM.P45);
      break;
    case 46:
      GO::COPY(P_CAM.P46);
      break;
    case 47:
      GO::COPY(P_CAM.P47);
      break;
    case 48:
      GO::COPY(P_CAM.P48);
      break;
    case 49:
      GO::COPY(P_CAM.P49);
      break;
    case 50:
      GO::COPY(P_CAM.P50);
      break;
      
    default:
      GO::COPY(P_CEN.P0);
      break;
  }
  
  LLEVAR.POSITION(IR[0], IR[1], IR[2]);
}

///////////////////////////////////////////////////////////////////////////////////

void GO::CONV_MOV(char MV, int PS){
    switch(MV)
    {
      case 'C':
        GO::POSICIONAR_CAM(PS);
        break;
      case 'V':
        // FALTA ESTE TIPO DE MOVIMIENTO
        break;
      case 'L':
        GO::COPY(P_CEN.PL);
        LLEVAR.POSITION(IR[0], IR[1], IR[2]);
        break;
              
      case 'P':
        GO::TOMAR_PIEZA(PS);
        break;
        
      case 'T':
        GO::COLOCAR_PIEZA(PS);
        break;        
      
      default:
        Serial.println("NO ES UN TIPO DE MOVIMIENTO ADMITIDO");
        break;
    }
}
