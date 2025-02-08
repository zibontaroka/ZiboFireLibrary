#include "ZiboFire.h"

// Define pins
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5
#define ir_R A0
#define ir_F A1
#define ir_L A2
#define servo A4
#define pump A5

// Initialize the library
ZiboFire fireBot(enA, in1, in2, in3, in4, enB, ir_R, ir_F, ir_L, servo, pump);

void setup() {
    Serial.begin(9600);
    fireBot.begin(160);  // Set motor speed
}

void loop() {
    fireBot.checkFire();
    delay(50);
}
