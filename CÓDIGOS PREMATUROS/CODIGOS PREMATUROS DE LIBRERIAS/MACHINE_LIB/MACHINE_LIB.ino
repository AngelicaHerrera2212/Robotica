#include "bingo_machine.h"

bingo_machine BOT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  
  delay(5000);
  
  BOT.robot_fase("START");
  delay(1000);

  BOT.robot_fase("FASE_1");
  delay(1000);

  BOT.robot_fase("FASE_2");
  delay(1000);

  BOT.robot_fase("BACK");
  delay(1000);

  BOT.robot_fase("FASE_3");
  delay(1000);

  BOT.robot_fase("BACK");
  delay(1000);
  
  BOT.robot_fase("FASE_4");
  delay(1000);

  BOT.robot_fase("BACK");
  delay(1000);
  
  BOT.robot_fase("FASE_5");
  delay(1000);
  
}
