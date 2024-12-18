#include "horloge.h"

/* BIBLIOTHEQUES */
#include <Arduino.h>

#include <RTClib.h>

/* PROGRAMMES */
#include "matrix.h"

/* MISC */
unsigned long startMillis;  // Variable pour stocker l'heure de démarrage (en millisecondes)
unsigned long elapsedMillis;  // Variable pour calculer le temps écoulé
int hours = 0, minutes = 0, seconds = 0;

DateTime compileTime;  // Pour stocker l'heure de compilation
unsigned long previousMillis = 0;  // Pour la mise à jour du temps écoulé toutes les secondes
const long interval = 1000;  // Intervalle de 1 seconde (1000 millisecondes)
DateTime simulatedTime; // Temps simulé

bool toggleAlarm = true; // Alarme activé ou non
DateTime alarmTime; // Temps de l'alarme
bool isAlarmOn = false;
const int alarmLength = 15; // Durée de l'alarme en secondes

// Initialise l'horloge
void initHorloge() {
  
  // Récupère l'heure du téléversement (compile time)
  compileTime = DateTime(F(__DATE__), F(__TIME__));

  // Affichage initial
  Serial.print("Temps de compilation : ");
  printDateTime(compileTime);
  Serial.println();

  // Enregistre le moment où le programme a commencé
  startMillis = millis();
}
// Initialise l'alarme
void initAlarm()
{
  alarmTime = DateTime(F(__DATE__), F("09:51:00"));
}
// Met à jour l'horloge (et l'affiche dans le moniteur série)
void updateHorloge() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    // C'est le moment d'ajouter 1 seconde à l'heure simulée
    previousMillis = currentMillis;
    
    // Calcule le temps écoulé en millisecondes
    elapsedMillis = millis() - startMillis;
    
    // Convertit en secondes
    seconds = (elapsedMillis / 1000) % 60;
    minutes = (elapsedMillis / 60000) % 60;
    hours = (elapsedMillis / 3600000) % 24;

    // Ajoute le temps écoulé à l'heure initiale du téléversement
    simulatedTime = compileTime + (elapsedMillis / 1000);  // + (elapsedMillis / 1000) pour ajouter les secondes

    // Affiche l'heure simulée
    Serial.print(F("Horloge : "));
    printDateTime(simulatedTime);
    Serial.println();
  }
}

// Coupe un temps sur deux chiffres en deux chiffres séparés
void cutTime(int time, int* d, int* u)
{
  if(time >= 10)
  {
      *u = time % 10;         // Troncature unité d'heure
      *d = time / 10;    // Troncature dizaine d'heure
  }
  else
  {
      *u = time;              
      *d = 0;
  }
}
// Convertit une classe 'DateTime' en structure 'Horaire'
Horaire dtToHoraire(DateTime dt)
{
  Horaire horaire;
  horaire.heure = dt.hour();
  horaire.minute = dt.minute();
  horaire.seconde = dt.second();

  return horaire;
}
// Print une date formatée dans la console
void printDateTime(DateTime dt) 
{
  Serial.print(dt.year(), DEC);
  Serial.print('/');
  Serial.print(dt.month(), DEC);
  Serial.print('/');
  Serial.print(dt.day(), DEC);
  Serial.print(" ");
  Serial.print(dt.hour(), DEC);
  Serial.print(':');
  Serial.print(dt.minute(), DEC);
  Serial.print(':');
  Serial.print(dt.second(), DEC);
}

// Affiche une horloge sur les 4 matrices
void afficherHorloge()
{   
    Horaire t = dtToHoraire(simulatedTime);
    int heure_d, heure_u, minute_d, minute_u;

    cutTime(t.heure, &heure_d, &heure_u);
    cutTime(t.minute, &minute_d, &minute_u);

    afficherChiffre(getChiffre(heure_d), 3);
    afficherChiffre(getChiffre(heure_u), 2);
    afficherChiffre(getChiffre(minute_d), 1);
    afficherChiffre(getChiffre(minute_u), 0);
}
// Renvoie si l'alarme est activée ou non
bool getToggleAlarm()
{
  return toggleAlarm;
}
// Check l'alarme (et renvoie si elle est actuellement entrain de sonner)
bool checkAlarm()
{

  if(!toggleAlarm) return false;

  // Vérifier si le temps actuel atteint l'heure de l'alarme et activer l'alarme
  if (!isAlarmOn && simulatedTime >= alarmTime && simulatedTime < alarmTime + alarmLength)
  {
    isAlarmOn = true;
    Serial.println(F("(!) ALARME EN COURS (!)"));
  }

  // Vérifier si l'heure dépasse la fin de l'alarme et désactiver l'alarme
  if (isAlarmOn && simulatedTime >= alarmTime + alarmLength)
  {
    isAlarmOn = false;
    Serial.println(F("(!) FIN ALARME (!)"));
  }

  return isAlarmOn;
}