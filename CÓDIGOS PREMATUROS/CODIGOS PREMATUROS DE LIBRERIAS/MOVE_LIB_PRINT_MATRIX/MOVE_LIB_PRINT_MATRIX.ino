
#include "bingo_move_print.h"

bingo_move_print BOT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  
 BOT.LIFT();
 delay(500);

 BOT.POSITION(20, 0, 10);
 delay(500);
   
 BOT.GO_0();
 delay(500);
    
 BOT.OPEN();
 delay(500);
 
 BOT.CLOSE();
 delay(500);

 BOT.MOV('C', 2);
 delay(500);
 
}
