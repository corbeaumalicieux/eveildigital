/* BIBLIOTHEQUES */
#include <Arduino.h>
#include <Wire.h>

#include <TaskScheduler.h>

/* PROGRAMMES */
#include "display.h"
#include "menu.h"
#include "horloge.h"
#include "matrix.h"

/* MISC */
Scheduler runner;

Task t_afficherHorloge(100, TASK_FOREVER, &afficherHorloge);

void setup() 
{
  // Initialisation moniteur série
  Serial.begin(9600);

  // Initialisation des composants
  initMatrix();
  initHorloge(); initAlarm();
  initDisplay();
  initIR();
  

  // Ajouter les tâches au scheduler
  runner.addTask(t_afficherHorloge); // Ajoute la tâche d'affichage de l'horloge
  // Démarrer les tâches
  t_afficherHorloge.enable(); // Démarre la tâche d'affichage de l'horloge

}

void loop() 
{
  runner.execute();
  //afficherHorloge();  // Affiche l'horloge sur matrice
  // checkAlarm();       // Check si l'alarme est activée ou non
}