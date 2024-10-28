void setup() {
    // Set LED pins as outputs
    pinMode(5, OUTPUT); // Red LED
    pinMode(3, OUTPUT); // Blue LED
    pinMode(4, OUTPUT); // Yellow LED

    // Set button pins as inputs
    pinMode(A0, INPUT); // Red button
    pinMode(A2, INPUT); // Blue button
    pinMode(A1, INPUT); // Yellow button
}

void loop() {
    // Read the state of each button
    int redButtonState = digitalRead(A0);
    int blueButtonState = digitalRead(A2);
    int yellowButtonState = digitalRead(A1);

    // Control the red LED based on red button state
    if (redButtonState == HIGH) {
        digitalWrite(5, HIGH);   // Turn on red LED
    } else {
        digitalWrite(5, LOW);    // Turn off red LED
    }

    // Control the blue LED based on blue button state
    if (blueButtonState == HIGH) {
        digitalWrite(3, HIGH);   // Turn on blue LED
    } else {
        digitalWrite(3, LOW);    // Turn off blue LED
    }

    // Control the yellow LED based on yellow button state
    if (yellowButtonState == HIGH) {
        digitalWrite(4, HIGH);   // Turn on yellow LED
    } else {
        digitalWrite(4, LOW);    // Turn off yellow LED
    }
}
