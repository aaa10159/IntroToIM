// Pin definitions for each button
const int buttonPins[7] = {2, 3, 4, 5, 6, 7, 8}; // Buttons for notes C, D, E, F, G, A, B
const int buzzerPin = 9;                         // Pin for the buzzer
const int potentiometerPin = A0;                 // Pin for the potentiometer

// Frequencies for notes C, D, E, F, G, A, B
const int noteFrequencies[7] = {261, 294, 329, 349, 392, 440, 493};

void setup() {
  // Set each button pin as input
  for (int i = 0; i < 7; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as output
  Serial.begin(9600);          // Start serial monitor for debugging
}

void loop() {
  int potValue = analogRead(potentiometerPin);    // Read the potentiometer value (0-1023)
  
  // Map potentiometer value to a "volume" level (duration)
  int volumeLevel = map(potValue, 0, 1023, 10, 200); // Larger value = longer tone duration

  bool notePlayed = false;      // Track if a note is being played

  // Check each button to see if it's pressed
  for (int i = 0; i < 7; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      int frequency = noteFrequencies[i];      // Get the note's frequency

      // Play the note with duration based on potentiometer setting
      tone(buzzerPin, frequency);
      delay(volumeLevel);
      noTone(buzzerPin);
      
      notePlayed = true;                       // Indicate that a note is played
      break;                                   // Play only one note at a time
    }
  }

  // Stop the tone if no button is pressed
  if (!notePlayed) {
    noTone(buzzerPin);
  }

  delay(10);                                   // Small delay for stability
}


