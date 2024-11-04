int led = 11;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop(){
  int sensorValue = analogRead(A2);
  Serial.println(sensorValue);
  analogWrite(led,sensorValue/4);
  delay(50);
}