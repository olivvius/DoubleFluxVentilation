#include "DHT.h"
//CONNEXIONS DU DHT22
// Connexion de pin 1 (à gauche) au +5V
// Connexion de pin 2 (data) à la broche définie par DHTPIN
// Connexion de pin 4 (à droite) au GROUND
// Connexion d'un resistance 10K  entre pin 2 (data) et + 5V

#define DHTPIN 2     // definotion de la broche de la connection du DHT
#define DHTTYPE DHT22   // DHT 22  (AM2302) définition du type de capteur DHT
#define fan 11 // broche du moteur

int vitesse = 0; // definition d'une variable appellée vitesse, celle de rotatation du moteur du ventilateur

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino
 
void setup() {
  pinMode(fan, OUTPUT); // je declare fan comme etant une broche de sortie
 // Serial.begin(9600); // pas d'affichage serial pour le moment, je risque par contre de ne pas savoir s'il y a des erreurs
  dht.begin(); // initialisation du DHT
}

void loop() {
  // pas de temps de mesure, attente pour lire les capteur (normalement 250 ms, mais peut aller jusque 2s si capteurs "usés" a ce que j'ai compris
  delay(2000);
  
  float h = dht.readHumidity(),0,100; // definition d'une variable à virgule flottante apellée h, l'humidite
  // et qui lit sur le capteur l'humidité allant de 0 à 100.
 if (! isnan(h)) { // si c'est un nombre valide
    vitesse=constrain(map(h, 0, 100, 0, 255), 0 , 255);  //vitesse est la valeur proportionnelle à l'humidité, mais s'étale de 0 à 255
   }
   
  if(h<40){
  analogWrite(11,0); // si l'humidite est inferieure a 40%, le ventilo est à l'arrêt
  }
  else{
    if(h>42){
analogWrite(11,vitesse);
    }
  }
}
