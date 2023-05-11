#include "GO.h"

GO BINGOBOT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
 
  BINGOBOT.UP();
  delay(500);

  BINGOBOT.GO_0();
  delay(500);

  BINGOBOT.CLOSE();
  delay(500);

  BINGOBOT.OPEN();
  delay(500);

  BINGOBOT.CONV_MOV('C', 1);
  delay(500);

}
