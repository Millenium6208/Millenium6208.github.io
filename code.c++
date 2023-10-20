// OpenDay ITT BLAISE PASCAL ELETTRONICA
//
// Circuito di Benvenuto

// Librerie del Kit Elegoo
#include <Servo.h>
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 Ultrasonic = SR04(ECHO_PIN, TRIG_PIN);
long distance;

// Crea un nuovo oggetto Servo
Servo Hand;
int maxAngle = 80;
int minAngle = 30;

void setup() {
  // Connetti il Servo al Pin 9
  Hand.attach(9);
}

// La mano saluta per un numero n di volte
// Alla fine riporta a metà la sua posizione
int greet(int repeat) {
  for (int i = 0; i < repeat; i++) {
    for (int j = minAngle; j < maxAngle; j++) {
      Hand.write(j);
      delay(2);
    }

    for (int k = maxAngle; k > minAngle; k--) {
      Hand.write(k);
      delay(2);
    }
  }
  Hand.write(55);
}

void loop() {
  Hand.write(55);
  distance = Ultrasonic.Distance();
  if (distance < 150) {
    greet(20);
  }
}
