#include "rtc.h"

/* BIBLIOTHEQUES*/
#include <Arduino.h>

#include <RTClib.h>


/* PROGRAMMES */
#include "matrix.h"
#include "melode.h"

#define PIN_LED 4

/* MISC */
RTC_DS1307 rtc;

bool alarmToggle = true; // Alarme activé ou non
DateTime alarmDateTime = DateTime(__DATE__, "17:03:00"); // Temps de l'alarme
bool isAlarmOn = false;
const int alarmLength = 10; // Durée de l'alarme en secondes

// 
// INITIALISATION du RTC
//
void initRTC() 
{
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}
// Afficher RTC Now
void afficherRTCNow() {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.println();
    delay(1000);
}

//
// CONFIGURATION
//

/*
RUN_MODE
*/
void afficherTime()
{   
  DateTime now = rtc.now();

  Horaire t = dtToHoraire(now);
  int heure_d, heure_u, minute_d, minute_u;

  cutTime(t.heure, &heure_d, &heure_u);
  cutTime(t.minute, &minute_d, &minute_u);

  afficherChiffre(getChiffre(heure_d), 3);
  afficherChiffre(getChiffre(heure_u), 2);
  afficherChiffre(getChiffre(minute_d), 1);
  afficherChiffre(getChiffre(minute_u), 0);
}
bool checkAlarm() {
    // Si l'alarme est désactivée par l'utilisateur
    if (!alarmToggle) return false;

    // Obtenir l'heure actuelle depuis le RTC
    DateTime now = rtc.now();

    // Si l'alarme n'est pas encore activée et que l'heure actuelle est égale ou après l'heure de l'alarme
    if (!isAlarmOn && now >= alarmDateTime && now < alarmDateTime + TimeSpan(alarmLength)) {
        isAlarmOn = true; // Activer l'alarme
        Serial.println(F("(!) ALARME EN COURS (!)"));
        playSonnerie();
    }

    // Vérifier si l'heure dépasse la fin de l'alarme et désactiver l'alarme
    if (isAlarmOn && now >= alarmDateTime + TimeSpan(alarmLength)) {
        isAlarmOn = false; // Désactiver l'alarme
        Serial.println(F("(!) FIN ALARME (!)"));
    }

    return isAlarmOn;
}
/*
*/

// Renvoie un Horaire depuis DateTime
DateTime horaireToDt(Horaire horaire)
{
    DateTime dt;

    char horaireString[9]; // "HH/MM\0"
    snprintf(horaireString, sizeof(horaireString), "%02d:%02d:%02d",horaire.heure, horaire.minute, horaire.seconde);
    dt = DateTime(__DATE__, horaireString);

    return dt;
}
Horaire dtToHoraire(DateTime dt)
{
  Horaire horaire;
  horaire.heure = dt.hour();
  horaire.minute = dt.minute();
  horaire.seconde = dt.second();

  return horaire;
}
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
bool isToggleAlarm()
{
  return alarmToggle;
}

Horaire getCurrentAlarm()
{
  return dtToHoraire(alarmDateTime);
}

/*
CONFIG_MODE
*/

void toggleAlarm()
{
    isAlarmOn ? isAlarmOn = false : isAlarmOn = true;
}
