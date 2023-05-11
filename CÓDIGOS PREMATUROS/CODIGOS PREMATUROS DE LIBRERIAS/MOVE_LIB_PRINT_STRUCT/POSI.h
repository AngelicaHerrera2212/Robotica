#include "Arduino.h"

    typedef struct M1{ 
      //POSICION 0 DE MOVIMIENTO
      const float P0 [3] = {20, 0, 24};  
  
      // POSISION DEL BASO
      const float PB [3] = {19, -2, 16};

      // POSISION LECTURA
      const float PL [3] = {19, -2, 16};
      
    }MB;

    typedef struct M2{
      
      // POSIBLES POSICIONES DE LAS PIEZAS
      const float P1 [3] = {13, -26, 7};
      const float P2 [3] = {15.5, -23, 6.};
      const float P3 [3] = {17.5, -21.5, 7.5};
    
    }MPI;

    typedef struct M3{

       // POSIBLES POSICIONES DEL BINGO
      const float P1 [3] = {27.3, 2.5, 10.5};
      const float P2 [3] = {26.5, 2, 10.5};
      const float P3 [3] = {24.5, 2, 9};
      const float P4 [3] = {23.25, 2, 9};
      const float P5 [3] = {22, 2, 8};
      const float P6 [3] = {27.3, 2.5, 10.5};
      const float P7 [3] = {26.5, 2, 10.5};
      const float P8 [3] = {24.5, 2, 9};
      const float P9 [3] = {23.25, 2, 9};
      const float P10 [3] = {22, 2, 8};

      const float P11 [3] = {27.3, 2.5, 10.5};
      const float P12 [3] = {26.5, 2, 10.5};
      const float P13 [3] = {24.5, 2, 9};
      const float P14 [3] = {23.25, 2, 9};
      const float P15 [3] = {22, 2, 8};
      const float P16 [3] = {27.3, 2.5, 10.5};
      const float P17 [3] = {26.5, 2, 10.5};
      const float P18 [3] = {24.5, 2, 9};
      const float P19 [3] = {23.25, 2, 9};
      const float P20 [3] = {22, 2, 8};

      const float P21 [3] = {27.3, 2.5, 10.5};
      const float P22 [3] = {26.5, 2, 10.5};
      const float P23 [3] = {24.5, 2, 9};
      const float P24 [3] = {23.25, 2, 9};
      const float P25 [3] = {22, 2, 8};
      const float P26 [3] = {27.3, 2.5, 10.5};
      const float P27 [3] = {26.5, 2, 10.5};
      const float P28 [3] = {24.5, 2, 9};
      const float P29 [3] = {23.25, 2, 9};
      const float P30 [3] = {22, 2, 8};

      const float P31 [3] = {27.3, 2.5, 10.5};
      const float P32 [3] = {26.5, 2, 10.5};
      const float P33 [3] = {24.5, 2, 9};
      const float P34 [3] = {23.25, 2, 9};
      const float P35 [3] = {22, 2, 8};
      const float P36 [3] = {27.3, 2.5, 10.5};
      const float P37 [3] = {26.5, 2, 10.5};
      const float P38 [3] = {24.5, 2, 9};
      const float P39 [3] = {23.25, 2, 9};
      const float P40 [3] = {22, 2, 8};

      const float P41 [3] = {27.3, 2.5, 10.5};
      const float P42 [3] = {26.5, 2, 10.5};
      const float P43 [3] = {24.5, 2, 9};
      const float P44 [3] = {23.25, 2, 9};
      const float P45 [3] = {22, 2, 8};
      const float P46 [3] = {27.3, 2.5, 10.5};
      const float P47 [3] = {26.5, 2, 10.5};
      const float P48 [3] = {24.5, 2, 9};
      const float P49 [3] = {23.25, 2, 9};
      const float P50 [3] = {22, 2, 8};
                  
    }MTB;

    typedef struct M4{

       // POSIBLES POSICIONES DE LECTURA DE LA CAMARA
      const float P1 [3] = {27.3, 2.5, 10.5};
      const float P2 [3] = {26.5, 2, 10.5};
      const float P3 [3] = {24.5, 2, 9};
      const float P4 [3] = {23.25, 2, 9};
      const float P5 [3] = {22, 2, 8};
      const float P6 [3] = {27.3, 2.5, 10.5};
      const float P7 [3] = {26.5, 2, 10.5};
      const float P8 [3] = {24.5, 2, 9};
      const float P9 [3] = {23.25, 2, 9};
      const float P10 [3] = {22, 2, 8};

      const float P11 [3] = {27.3, 2.5, 10.5};
      const float P12 [3] = {26.5, 2, 10.5};
      const float P13 [3] = {24.5, 2, 9};
      const float P14 [3] = {23.25, 2, 9};
      const float P15 [3] = {22, 2, 8};
      const float P16 [3] = {27.3, 2.5, 10.5};
      const float P17 [3] = {26.5, 2, 10.5};
      const float P18 [3] = {24.5, 2, 9};
      const float P19 [3] = {23.25, 2, 9};
      const float P20 [3] = {22, 2, 8};

      const float P21 [3] = {27.3, 2.5, 10.5};
      const float P22 [3] = {26.5, 2, 10.5};
      const float P23 [3] = {24.5, 2, 9};
      const float P24 [3] = {23.25, 2, 9};
      const float P25 [3] = {22, 2, 8};
      const float P26 [3] = {27.3, 2.5, 10.5};
      const float P27 [3] = {26.5, 2, 10.5};
      const float P28 [3] = {24.5, 2, 9};
      const float P29 [3] = {23.25, 2, 9};
      const float P30 [3] = {22, 2, 8};

      const float P31 [3] = {27.3, 2.5, 10.5};
      const float P32 [3] = {26.5, 2, 10.5};
      const float P33 [3] = {24.5, 2, 9};
      const float P34 [3] = {23.25, 2, 9};
      const float P35 [3] = {22, 2, 8};
      const float P36 [3] = {27.3, 2.5, 10.5};
      const float P37 [3] = {26.5, 2, 10.5};
      const float P38 [3] = {24.5, 2, 9};
      const float P39 [3] = {23.25, 2, 9};
      const float P40 [3] = {22, 2, 8};

      const float P41 [3] = {27.3, 2.5, 10.5};
      const float P42 [3] = {26.5, 2, 10.5};
      const float P43 [3] = {24.5, 2, 9};
      const float P44 [3] = {23.25, 2, 9};
      const float P45 [3] = {22, 2, 8};
      const float P46 [3] = {27.3, 2.5, 10.5};
      const float P47 [3] = {26.5, 2, 10.5};
      const float P48 [3] = {24.5, 2, 9};
      const float P49 [3] = {23.25, 2, 9};
      const float P50 [3] = {22, 2, 8};
                  
    }MCAM;
