#include <stdint.h>
#include <Arduino.h>
#include <telecommande.h>


void telecommande::init()
{
    // activer la liaison série
    Serial.begin(38400); // Initialisation du port série par défaut pour la communication avec le moniteur série
    while (Serial.available() < 7)
    {
        //on attend de recevoir la premiere transmission de la telecommande 
    }
    Serial.readBytes(transmit, 7);
};

void telecommande::get_transmission()
{
    if (Serial.available() >= 7) 
    { 
        // Vérifie si au moins 7 octets ont ete reu par l'UART (que la transmission soit complete)
        // Lit les 7 octets du port série et les stocke dans le tableau
        Serial.readBytes(transmit, 7);
        decode_trame();
    }
}

void telecommande::decode_trame() // fonction perrmettant de reordonner le tableau recu lors de desyncronisation entre la telecommande et le drone
{
    uint8_t trame_ordonnee[7]={0,0,0,0,0,0,0};
    uint8_t debut_trame=0;

    for (uint8_t i = 0; i < 7; i++)
    {
        if (transmit[i]==250)
        debut_trame=i;
    }

    if (debut_trame!=0)
        for (uint8_t i = 0; i < 7; i++)
        {
        if((debut_trame+i)>=7)
            trame_ordonnee[i]=transmit[i-(7-debut_trame)];
        else
            trame_ordonnee[i]=transmit[i+debut_trame];
        }
    else
        for (uint8_t i = 0; i < 7; i++)
        {
        trame_ordonnee[i]=transmit[i];
        }

    for (uint8_t i = 0; i < 6; i++)
    {
        trame_decodee[i]=trame_ordonnee[i+1];
    }
}

uint8_t telecommande::get_X_joy_right() //indice 0
{
    return transmit[0];
}

uint8_t telecommande::get_Y_joy_right() //indice 1
{
    return transmit[1];
}

uint8_t telecommande::get_X_joy_left() // indice 2
{
    return transmit[2];
}

uint8_t telecommande::get_Y_joy_left() // indice 3
{
    return transmit[3];
}

bool telecommande::get_button_joy_right() // indice 4
{
    return transmit[4];
}

bool telecommande::get_button_joy_left() // indice 5
{
    return transmit[5];
}
