// ZiboFire.h - Header File
#ifndef ZIBOFIRE_H
#define ZIBOFIRE_H

#include <Arduino.h>

class ZiboFire {
public:
    ZiboFire(int enA, int IN1, int IN2, int IN3, int IN4, int enB, int IR_Right, int IR_Front, int IR_Left, int servo, int pump);
    void begin(int speed);
    void checkFire();
    void forward();
    void backward();
    void turnRight();
    void turnLeft();
    void stop();
    void activatePump();
    void deactivatePump();
    void sweepServo(int startAngle, int endAngle, int step);
    
private:
    int _enA, _IN1, _IN2, _IN3, _IN4, _enB;
    int _IR_Right, _IR_Front, _IR_Left, _servo, _pump;
    int _speed;
    void servoPulse(int angle);
};

#endif
