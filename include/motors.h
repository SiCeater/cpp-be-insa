#ifndef MOTOR_H  // Vérification pour éviter les inclusions multiples
#define MOTOR_H

#include <Arduino.h>
#include <Servo.h>

class motor {
private:
    uint16_t speed = 0;
    Servo ESC;
    uint8_t motor_pin = 0;

public:
    motor& operator+=(const uint16_t add);
    void init(uint8_t pin);
    void stop();
    void start();
    void set_speed(uint16_t value);
    void increase_speed(uint16_t value);
    void decrease_speed(uint16_t value);
};

#endif // MOTOR_H