// ZiboFire.cpp - Implementation File
#include "ZiboFire.h"

ZiboFire::ZiboFire(int enA, int IN1, int IN2, int IN3, int IN4, int enB, int IR_Right, int IR_Front, int IR_Left, int servo, int pump) {
    _enA = enA; _IN1 = IN1; _IN2 = IN2; _IN3 = IN3; _IN4 = IN4; _enB = enB;
    _IR_Right = IR_Right; _IR_Front = IR_Front; _IR_Left = IR_Left; _servo = servo; _pump = pump;
}

void ZiboFire::begin(int speed) {
    _speed = speed;
    pinMode(_enA, OUTPUT); pinMode(_IN1, OUTPUT); pinMode(_IN2, OUTPUT);
    pinMode(_IN3, OUTPUT); pinMode(_IN4, OUTPUT); pinMode(_enB, OUTPUT);
    pinMode(_IR_Right, INPUT); pinMode(_IR_Front, INPUT); pinMode(_IR_Left, INPUT);
    pinMode(_servo, OUTPUT); pinMode(_pump, OUTPUT);
    analogWrite(_enA, _speed);
    analogWrite(_enB, _speed);
}

void ZiboFire::checkFire() {
    int s1 = analogRead(_IR_Right);
    int s2 = analogRead(_IR_Front);
    int s3 = analogRead(_IR_Left);
    
    if (s1 < 250 || s2 < 350 || s3 < 250) {
        stop();
        activatePump();
        sweepServo(90, 40, -3);
        sweepServo(40, 90, 3);
    } else {
        deactivatePump();
    }
}

void ZiboFire::forward() {
    digitalWrite(_IN1, HIGH); digitalWrite(_IN2, LOW);
    digitalWrite(_IN3, LOW); digitalWrite(_IN4, HIGH);
}

void ZiboFire::backward() {
    digitalWrite(_IN1, LOW); digitalWrite(_IN2, HIGH);
    digitalWrite(_IN3, HIGH); digitalWrite(_IN4, LOW);
}

void ZiboFire::turnRight() {
    digitalWrite(_IN1, LOW); digitalWrite(_IN2, HIGH);
    digitalWrite(_IN3, LOW); digitalWrite(_IN4, HIGH);
}

void ZiboFire::turnLeft() {
    digitalWrite(_IN1, HIGH); digitalWrite(_IN2, LOW);
    digitalWrite(_IN3, HIGH); digitalWrite(_IN4, LOW);
}

void ZiboFire::stop() {
    digitalWrite(_IN1, LOW); digitalWrite(_IN2, LOW);
    digitalWrite(_IN3, LOW); digitalWrite(_IN4, LOW);
}

void ZiboFire::activatePump() {
    digitalWrite(_pump, HIGH);
}

void ZiboFire::deactivatePump() {
    digitalWrite(_pump, LOW);
}

void ZiboFire::sweepServo(int startAngle, int endAngle, int step) {
    for (int angle = startAngle; angle != endAngle; angle += step) {
        servoPulse(angle);
    }
}

void ZiboFire::servoPulse(int angle) {
    int pwm = (angle * 11) + 500;
    digitalWrite(_servo, HIGH);
    delayMicroseconds(pwm);
    digitalWrite(_servo, LOW);
    delay(50);
}
