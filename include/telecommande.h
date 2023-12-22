#ifndef TELECOMMANDE_H  // Vérification pour éviter les inclusions multiples
#define TELECOMMANDE_H

#include <stdint.h>
#include <Arduino.h>

class telecommande {
private:
    uint8_t  transmit[7] = {0, 0, 0, 0, 0, 0, 0};
    uint8_t  trame_decodee[6] = {0, 0, 0, 0, 0, 0};

public:
    void init();
    void get_transmission();
    void decode_trame();

    uint8_t get_X_joy_right();
    uint8_t get_Y_joy_right();
    uint8_t get_X_joy_left();
    uint8_t get_Y_joy_left();
    bool get_button_joy_right();
    bool get_button_joy_left();
};

#endif // TELECOMMANDE_H