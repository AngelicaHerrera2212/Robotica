#include "BINGO.h"

BINGO BOT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  BOT.accion();

}
