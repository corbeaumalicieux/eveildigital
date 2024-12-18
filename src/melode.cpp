#include <Arduino.h>

// Définition des fréquences des notes de musique de la 4ème octave
#define OCTAVE_4_DO 523
#define OCTAVE_4_RE 587
#define OCTAVE_4_MI 659
#define OCTAVE_4_FA 698
#define OCTAVE_4_SOL 784
#define OCTAVE_4_LA 880
#define OCTAVE_4_SI 988

// Définition de la durée d'un temps en millisecondes
#define DUREE_TEMPS 300
// Définition de la pause de fin de note en millisecondes
#define PAUSE_FIN_NOTE 90

// Déclaration de la fonction avant loop()
void JouerNote(unsigned int Note_P, unsigned int NombreTemps_P);

const int buzzerPin = 9;  // Pin du buzzer

void initSonnerie() {
  pinMode(buzzerPin, OUTPUT);  // Initialisation de la pin D9 comme sortie
}

void playSonnerie() {
  // Jeu des 11 premières notes de "Au clair de la lune" 2 fois
  for (int i = 0; i < 2; i++) {
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_RE, 1);
    JouerNote(OCTAVE_4_MI, 2);
    JouerNote(OCTAVE_4_RE, 2);
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_MI, 1);
    JouerNote(OCTAVE_4_RE, 1);
    JouerNote(OCTAVE_4_RE, 1);
    JouerNote(OCTAVE_4_DO, 4);
  }
}

void JouerNote(unsigned int Note_P, unsigned int NombreTemps_P) {
  // Lance l'émission de la note
  tone(buzzerPin, Note_P, NombreTemps_P * DUREE_TEMPS);
  // Attend que la note soit terminée de jouer
  delay(NombreTemps_P * DUREE_TEMPS);
  // Petit silence avant la note suivante
  noTone(buzzerPin);  // Arrête le son
  delay(PAUSE_FIN_NOTE);
}
