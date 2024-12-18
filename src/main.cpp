/* BIBLIOTHEQUES */
#include <Arduino.h>
#include <Wire.h>

/* PROGRAMMES */
#include "display.h"
#include "menu.h"
#include "horloge.h"
#include "matrix.h"


void setup() 
{
  // Initialisation moniteur série
  Serial.begin(9600);

  // Initialisation des composants
  initDisplay();
  initIR();
  initMatrix();
  initHorloge(); initAlarm();

  selectionMenuPrincipal(); // Lancement du menu sur l'écran OLED
}

void loop() 
{
  updateHorloge();    // Met à jour l'horloge
  afficherHorloge();  // Affiche l'horloge sur matrice
  checkAlarm();       // Check si l'alarme est activée ou non
}