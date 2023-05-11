#include "Hear_Machine_Mix.h"

Hear_Machine_Mix BINGO;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  BINGO.lectura();
}
