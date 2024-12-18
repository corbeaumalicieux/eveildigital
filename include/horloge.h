#ifndef HORLOGE_H
#define HORLOGE_H

#include <RTClib.h>

typedef struct Horaire {
    int heure;
    int minute;
    int seconde;
} Horaire;

void initHorloge();
void initAlarm();
void updateHorloge();


void cutTime(int time, int* d, int* u);
Horaire dtToHoraire(DateTime dt);
void printDateTime(DateTime dt);

void afficherHorloge();

bool getToggleAlarm();
bool checkAlarm();

#endif