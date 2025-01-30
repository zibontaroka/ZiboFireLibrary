# ZiboFireLibrary

## Overview
**ZiboFireLibrary** is an Arduino library designed for fire detection and automated response using IR sensors and an L298 motor driver. It enables a robot to detect fire, activate a water pump, and move accordingly using servo motors and wheels.

## Features
- Fire detection using IR sensors
- Motorized response (forward, backward, left, right, stop)
- Automatic water pump activation
- Servo motor-controlled scanning
- Configurable speed and pin assignments

## Installation
1. Download the **ZiboFireLibrary** from GitHub.
2. Copy the `ZiboFireLibrary/` folder to your Arduino `libraries/` directory:
   - Windows: `Documents\Arduino\libraries\`
   - macOS/Linux: `~/Arduino/libraries/`
3. Restart the Arduino IDE.
4. Open the example sketch from `File -> Examples -> ZiboFire`.

## Usage
### Include the Library
```cpp
#include <ZiboFire.h>
```

### Initialize the Library
```cpp
ZiboFire fireRobot(10, 9, 8, 7, 6, 5, A0, A1, A2, A4, A5);
```

### Begin Operation
```cpp
void setup() {
    fireRobot.begin(160); // Set motor speed
}
```

### Detect Fire and Act Accordingly
```cpp
void loop() {
    fireRobot.checkFire();
    delay(100);
}
```

## API Reference
### `ZiboFire(int enA, int in1, int in2, int in3, int in4, int enB, int ir_R, int ir_F, int ir_L, int servo, int pump)`
Constructor to initialize pin configurations.

### `void begin(int speed)`
Initializes pins and sets motor speed.

### `void checkFire()`
Reads IR sensors and triggers actions based on fire detection.

### `void forward()`, `void backward()`, `void turnLeft()`, `void turnRight()`, `void stop()`
Motor control functions for movement.

### `void activatePump()`, `void deactivatePump()`
Controls the water pump.

### `void sweepServo(int startAngle, int endAngle, int step)`
Moves the servo in a range of angles.

## Repository
Find the latest version on GitHub: [ZiboFireLibrary](https://github.com/zibontaroka/ZiboFireLibrary)

## Author
**Md Shaifulla Zibon**  
Email: mdshaifullazibon11@gmail.com  
Website: [zibon.top](https://zibon.top)

## License
This project is licensed under the MIT License.

