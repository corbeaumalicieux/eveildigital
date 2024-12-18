#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void initDisplay(void);
void updateDisplay(void);

void afficherMenuPrincipal();
void afficherMenuHorloge();
void afficherMenuReveil();
void afficherHeureReveil();

const bool isAlarmOn PROGMEM = true;
const bool isFirstMelody PROGMEM = true;

#endif