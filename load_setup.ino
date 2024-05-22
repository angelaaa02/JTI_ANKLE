#include <Hx711.h>

// Hx711.DOUT - pin #A1
// Hx711.SCK - pin #A0
Hx711 scale(A1, A0);
const int buzzerPin = 8; // Buzzer connected to digital pin 8

void setup() {
  Serial.begin(9600); // Initialize serial communication with the computer and OpenLog Artemis
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void loop() {
  float weight = scale.getGram();

  if (weight < -20) {
    digitalWrite(buzzerPin, HIGH); // Turn buzzer on
  } else {
    digitalWrite(buzzerPin, LOW); // Turn buzzer off
  }

  Serial.print("Weight: ");
  Serial.print(weight, 1);
  Serial.println(" g");

  delay(10);
}
