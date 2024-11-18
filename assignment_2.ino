// Arduino Code to control LED brightness based on serial input

const int ledPin = 9; // Pin connected to the LED (PWM pin)

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
}

void loop() {
  if (Serial.available()) {
    int brightness = Serial.parseInt(); // Read the brightness value
    if (Serial.read() == '\n') {       // Wait for newline character
      brightness = constrain(brightness, 0, 255); // Ensure value is within 0-255
      analogWrite(ledPin, brightness); // Set LED brightness
    }
  }
}
