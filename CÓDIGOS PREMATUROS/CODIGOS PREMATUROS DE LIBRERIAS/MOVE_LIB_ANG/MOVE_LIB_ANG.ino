#include "MOVE_ANG.h"

MOVE_ANG SERV;

int S1 = 10, S2 = 11, S3 = 6, S4 = 9;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  SERV.INICIA(S1, S2, S3, S4);

  SERV.CLOSE();
  delay(500);
  
  SERV.OPEN();
  delay(500);
  
  SERV.JUST_GO(34, 67.8, 35); 
  delay(500);
  
  SERV.LLEVAR(35, 97, 87, 34, 67.8, 35);
  delay(500);
    
  SERV.LIFT();
    
  SERV.GO_TO_0 ();

}

void loop() {

}
