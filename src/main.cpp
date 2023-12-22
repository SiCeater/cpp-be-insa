#include <Arduino.h>
//#include <ArduinoSTL.h> 

#include <motors.h>
#include <telecommande.h>

motor moteur_av_droit;
motor moteur_av_gauche;
motor moteur_arr_droit;
motor moteur_arr_gauche;
telecommande remote;


void setup() {

  std::vector<int> myVector; // création d'un vecteur a l'aide de STL
  myVector.push_back(10);


  moteur_arr_droit.init(15);
  moteur_arr_gauche.init(13);
  moteur_av_droit.init(12);
  moteur_av_gauche.init(14);
  remote.init();

  // Affichage des éléments du vecteur sur le moniteur série
  for (int i = 0; i < myVector.size(); ++i) {
    Serial.print("Element ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(myVector[i]);
  }
}

void loop() {
  remote.get_transmission();
  remote.decode_trame();

//une fois la trame decodée on recupere Y du joystick gauche pour appliquer une vitsse de moteur proportionnelle
  moteur_arr_droit.set_speed(((remote.get_Y_joy_left())-100)*10);
  moteur_arr_gauche.set_speed(((remote.get_Y_joy_left())-100)*10);
  moteur_av_droit.set_speed(((remote.get_Y_joy_left())-100)*10);
  moteur_av_gauche.set_speed(((remote.get_Y_joy_left())-100)*10);
}