#include "ZiboFire.h"

// Define pins
#define enA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define enB 5
#define IR_Right A0
#define IR_Front A1
#define IR_Left A2
#define servo 3
#define pump 2

// Initialize the library
ZiboFire fireBot(enA, IN1, IN2, IN3, IN4, enB, IR_Right, IR_Front, IR_Left, servo, pump);

void setup() {
    Serial.begin(9600);
    fireBot.begin(160);  // Set motor speed
}

void loop() {
    fireBot.checkFire();
    delay(50);
}
