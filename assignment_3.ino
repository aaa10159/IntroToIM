const int ledPin = 9;  // Digital pin 9 connected to the LED
const int lightSensor = A0; // Analog input pin A0 for the light sensor

void setup() {
  Serial.begin(9600);      // Start serial communication
  pinMode(ledPin, OUTPUT); // Set LED pin as an output
}

void loop() {
  // Read the light sensor value
  int lightValue = analogRead(lightSensor);

  // Send the light value to p5.js
  Serial.println(lightValue);

  // Check for bounce signal (when ball touches the ground) from p5.js
  if (Serial.available() > 0) {
    int bounceSignal = Serial.parseInt();
    if (Serial.read() == '\n' && bounceSignal == 1) {
      // Turn on the LED briefly to indicate a bounce
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
    }
  }

  delay(50); // Small delay 
}
