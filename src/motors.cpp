#include <Arduino.h>
#include <Servo.h>
#include <motors.h>


motor& motor::operator+=(const uint16_t add) // redefinition d'operateur qui remplace la fonction increase_speed()
{
    if(add+this->speed > 1000)
        this->speed = 1000;
    else  
        this->speed += add;
    return *this;
}

void motor::init(uint8_t pin)
{
    ESC.attach(pin,1000,2000);
    motor_pin=pin;
    ESC.writeMicroseconds(1000+speed);
}

// methode pour arreter le moteur
void motor::stop() 
{
    ESC.writeMicroseconds(1000);
}

// methode pour demarrer le moteur
void motor::start()
{
    ESC.writeMicroseconds(speed);
}

void motor::set_speed(uint16_t value) 
{
    if(value>1000)
        value=1000;
    if(value<0)
        value=0;

    ESC.writeMicroseconds(1000+value);
    speed=value;
}

void motor::increase_speed(uint16_t value)
{
    if(value+speed>1000)
        speed=1000;
    if(value+speed<0)
        speed=0;
    speed=speed+value;
    ESC.writeMicroseconds(1000+speed);

}

void motor::decrease_speed(uint16_t value)
{
    if(speed-value>1000)
        speed=1000;
    if(speed-value<0)
        speed=0;
    speed=speed-value;
    ESC.writeMicroseconds(1000+speed);
}