// ZiboFire.h - Header File
#ifndef ZIBOFIRE_H
#define ZIBOFIRE_H

#include <Arduino.h>

class ZiboFire {
public:
    ZiboFire(int enA, int in1, int in2, int in3, int in4, int enB, int ir_R, int ir_F, int ir_L, int servo, int pump);
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
    int _enA, _in1, _in2, _in3, _in4, _enB;
    int _ir_R, _ir_F, _ir_L, _servo, _pump;
    int _speed;
    void servoPulse(int angle);
};

#endif
