#ifndef MATRIX_H
#define MATRIX_H

#include <Arduino.h>

const byte CHIFFRE_0[] PROGMEM = {
  0b00111100,   // 1ère ligne de leds pour ce chiffre
  0b01000010,   // 2ème ligne de leds pour ce chiffre
  0b01000010,   // 3ème ligne de leds pour ce chiffre
  0b01000010,   // 4ème ligne de leds pour ce chiffre
  0b01000010,   // 5ème ligne de leds pour ce chiffre
  0b01000010,   // 6ème ligne de leds pour ce chiffre
  0b01000010,   // 7ème ligne de leds pour ce chiffre
  0b00111100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_1[] PROGMEM = {
  0b00001000,   // 1ère ligne de leds pour ce chiffre
  0b00011000,   // 2ème ligne de leds pour ce chiffre
  0b00101000,   // 3ème ligne de leds pour ce chiffre
  0b00001000,   // 4ème ligne de leds pour ce chiffre
  0b00001000,   // 5ème ligne de leds pour ce chiffre
  0b00001000,   // 6ème ligne de leds pour ce chiffre
  0b00001000,   // 7ème ligne de leds pour ce chiffre
  0b00011100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_2[] PROGMEM = {
  0b00111100,   // 1ère ligne de leds pour ce chiffre
  0b01000010,   // 2ème ligne de leds pour ce chiffre
  0b01000010,   // 3ème ligne de leds pour ce chiffre
  0b00000100,   // 4ème ligne de leds pour ce chiffre
  0b00001000,   // 5ème ligne de leds pour ce chiffre
  0b00010000,   // 6ème ligne de leds pour ce chiffre
  0b00100000,   // 7ème ligne de leds pour ce chiffre
  0b01111110    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_3[] PROGMEM = {
  0b01111110,   // 1ère ligne de leds pour ce chiffre
  0b00000100,   // 2ème ligne de leds pour ce chiffre
  0b00001000,   // 3ème ligne de leds pour ce chiffre
  0b00011100,   // 4ème ligne de leds pour ce chiffre
  0b00000010,   // 5ème ligne de leds pour ce chiffre
  0b00000010,   // 6ème ligne de leds pour ce chiffre
  0b01000010,   // 7ème ligne de leds pour ce chiffre
  0b00111100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_4[] PROGMEM = {
  0b00000100,   // 1ère ligne de leds pour ce chiffre
  0b00001100,   // 2ème ligne de leds pour ce chiffre
  0b00010100,   // 3ème ligne de leds pour ce chiffre
  0b00100100,   // 4ème ligne de leds pour ce chiffre
  0b01111111,   // 5ème ligne de leds pour ce chiffre
  0b00000100,   // 6ème ligne de leds pour ce chiffre
  0b00000100,   // 7ème ligne de leds pour ce chiffre
  0b00000100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_5[] PROGMEM = {
  0b01111110,   // 1ère ligne de leds pour ce chiffre
  0b01000000,   // 2ème ligne de leds pour ce chiffre
  0b01000000,   // 3ème ligne de leds pour ce chiffre
  0b01111100,   // 4ème ligne de leds pour ce chiffre
  0b00000010,   // 5ème ligne de leds pour ce chiffre
  0b00000010,   // 6ème ligne de leds pour ce chiffre
  0b01000010,   // 7ème ligne de leds pour ce chiffre
  0b00111100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_6[] PROGMEM = {
  0b00111100,   // 1ère ligne de leds pour ce chiffre
  0b01000010,   // 2ème ligne de leds pour ce chiffre
  0b01000000,   // 3ème ligne de leds pour ce chiffre
  0b01111100,   // 4ème ligne de leds pour ce chiffre
  0b01000010,   // 5ème ligne de leds pour ce chiffre
  0b01000010,   // 6ème ligne de leds pour ce chiffre
  0b01000010,   // 7ème ligne de leds pour ce chiffre
  0b00111100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_7[] PROGMEM = {
  0b01111110,   // 1ère ligne de leds pour ce chiffre
  0b00000010,   // 2ème ligne de leds pour ce chiffre
  0b00000010,   // 3ème ligne de leds pour ce chiffre
  0b00000100,   // 4ème ligne de leds pour ce chiffre
  0b00001000,   // 5ème ligne de leds pour ce chiffre
  0b00010000,   // 6ème ligne de leds pour ce chiffre
  0b00100000,   // 7ème ligne de leds pour ce chiffre
  0b01000000    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_8[] PROGMEM = {
  0b00111100,   // 1ère ligne de leds pour ce chiffre
  0b01000010,   // 2ème ligne de leds pour ce chiffre
  0b01000010,   // 3ème ligne de leds pour ce chiffre
  0b00111100,   // 4ème ligne de leds pour ce chiffre
  0b01000010,   // 5ème ligne de leds pour ce chiffre
  0b01000010,   // 6ème ligne de leds pour ce chiffre
  0b01000010,   // 7ème ligne de leds pour ce chiffre
  0b00111100    // 8ème ligne de leds pour ce chiffre
};
const byte CHIFFRE_9[] PROGMEM = {
  0b00111100,   // 1ère ligne de leds pour ce chiffre
  0b01000010,   // 2ème ligne de leds pour ce chiffre
  0b01000010,   // 3ème ligne de leds pour ce chiffre
  0b01000010,   // 4ème ligne de leds pour ce chiffre
  0b00111110,   // 5ème ligne de leds pour ce chiffre
  0b00000010,   // 6ème ligne de leds pour ce chiffre
  0b01000010,   // 7ème ligne de leds pour ce chiffre
  0b00111100    // 8ème ligne de leds pour ce chiffre
};

const byte* getChiffre(int num);

void initMatrix();

void afficherChiffre(const byte* pointeurVersChiffreOuSymbole, int adresse);


#endif