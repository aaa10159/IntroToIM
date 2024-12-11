// Define pins for each button
const int buttonPins[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
// Define pins for each LED
const int ledPins[9] = {A5, A4, A3, A2, A1, A0, 11, 12, 13};

void setup() {
  Serial.begin(9600); // Start serial communication

  // Set button pins as input
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT); // Set LED pins as output
    digitalWrite(ledPins[i], LOW); // Turn off all LEDs at the start
  }
}

void loop() {
  bool buttonPressed = false; // Track if a button is pressed

  // Check each button to see if it's pressed
  for (int i = 0; i < 9; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      // Send the button index to p5.js
      Serial.println(i); // Button index

      // Light up the corresponding LED
      digitalWrite(ledPins[i], HIGH); // Turn on the LED
      buttonPressed = true;
      delay(100); 
      break; // Only send one button at a time
    } else {
      // Turn off the LED when the button is not pressed
      digitalWrite(ledPins[i], LOW);
    }
  }

  // If no button is pressed, send a release signal
  if (!buttonPressed) {
    Serial.println("-1"); // -1 indicates no button is pressed
    delay(100);
  }
}
