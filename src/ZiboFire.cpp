// ZiboFire.cpp - Implementation File
#include "ZiboFire.h"

ZiboFire::ZiboFire(int enA, int in1, int in2, int in3, int in4, int enB, int ir_R, int ir_F, int ir_L, int servo, int pump) {
    _enA = enA; _in1 = in1; _in2 = in2; _in3 = in3; _in4 = in4; _enB = enB;
    _ir_R = ir_R; _ir_F = ir_F; _ir_L = ir_L; _servo = servo; _pump = pump;
}

void ZiboFire::begin(int speed) {
    _speed = speed;
    pinMode(_enA, OUTPUT); pinMode(_in1, OUTPUT); pinMode(_in2, OUTPUT);
    pinMode(_in3, OUTPUT); pinMode(_in4, OUTPUT); pinMode(_enB, OUTPUT);
    pinMode(_ir_R, INPUT); pinMode(_ir_F, INPUT); pinMode(_ir_L, INPUT);
    pinMode(_servo, OUTPUT); pinMode(_pump, OUTPUT);
    analogWrite(_enA, _speed);
    analogWrite(_enB, _speed);
}

void ZiboFire::checkFire() {
    int s1 = analogRead(_ir_R);
    int s2 = analogRead(_ir_F);
    int s3 = analogRead(_ir_L);
    
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
    digitalWrite(_in1, HIGH); digitalWrite(_in2, LOW);
    digitalWrite(_in3, LOW); digitalWrite(_in4, HIGH);
}

void ZiboFire::backward() {
    digitalWrite(_in1, LOW); digitalWrite(_in2, HIGH);
    digitalWrite(_in3, HIGH); digitalWrite(_in4, LOW);
}

void ZiboFire::turnRight() {
    digitalWrite(_in1, LOW); digitalWrite(_in2, HIGH);
    digitalWrite(_in3, LOW); digitalWrite(_in4, HIGH);
}

void ZiboFire::turnLeft() {
    digitalWrite(_in1, HIGH); digitalWrite(_in2, LOW);
    digitalWrite(_in3, HIGH); digitalWrite(_in4, LOW);
}

void ZiboFire::stop() {
    digitalWrite(_in1, LOW); digitalWrite(_in2, LOW);
    digitalWrite(_in3, LOW); digitalWrite(_in4, LOW);
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
