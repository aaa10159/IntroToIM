void setup() {
  Serial.begin(9600); //  serial communication
}

void loop() {
  int potValue = analogRead(A0); // potentiometer value
  Serial.println(potValue);     // send the value to the serial port
  delay(10);                   
}