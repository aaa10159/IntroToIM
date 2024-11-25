// Define pins for each button
const int buttonPins[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
// Define pin for potentiometer
const int potentiometerPin = A0;

void setup() {
  Serial.begin(9600); // Start serial communication

  // Set button pins as input
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  int potValue = analogRead(potentiometerPin); // Read potentiometer value (0-1023)
  bool buttonPressed = false; // Track if a button is pressed

  // Check each button to see if it's pressed
  for (int i = 0; i < 9; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      // Send the button index and potentiometer value to p5.js
      Serial.print(i); // Button index
      Serial.print(","); // Separator
      Serial.println(potValue); // Potentiometer value
      buttonPressed = true;
      delay(100); // Debounce delay
      break; // Only send one button at a time
    }
  }

  // If no button is pressed, send a release signal
  if (!buttonPressed) {
    Serial.println("-1,0"); // -1 indicates no button is pressed
    delay(100); // Debounce delay
  }
}
