int LED = 13;

void setup() {

  pinMode(LED, OUTPUT);
  Serial.begin(9600);      // abre el puerto serie a 9600 bps:    
}

void loop() {
}


void serialEvent(){
while(Serial.available()){
    char data = (char)Serial.read();
    if (data == 'a')
    {
      digitalWrite(LED, HIGH);
      Serial.println("SE LOGRO, SE LOGRO, SE LOGRO");
    }
    if (data == 'b')
    {
      digitalWrite(LED, LOW);
      Serial.println("SI, SI, SI");
    }
  }
}
