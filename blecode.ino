/**
 * This code reads the weight from the HX711 load cell and sends it to the OpenLog Artemis over UART.
 * Author: Fei Xue， Yi Ou
 * date: 2024-05-17
*/

#include <Hx711.h>

char data[50];

Hx711 scale(A1, A0);
const int buzzerPin = 8; // Buzzer connected to digital pin 8

void setup() {
  Serial.begin(9600); // Initialize serial communication with the computer
  Serial1.begin(115200); // Initialize serial communication with OpenLog Artemis
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void loop() {
    float weight = scale.getGram();
    snprintf(data, sizeof(data), "Weight: %.2f g\n", weight);
    Serial1.print(data);

    if (weight < 20) {
        digitalWrite(buzzerPin, HIGH); // Turn buzzer on
    } else {
        digitalWrite(buzzerPin, LOW); // Turn buzzer off
    }

  delay(100);
}
