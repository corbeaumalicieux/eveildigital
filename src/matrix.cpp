#include <matrix.h>

// Inclusion de la librairie LedControl
#include <LedControl.h>

/* PROGRAMMES */

/* MISC */
#define PIN_CS  10       
#define PIN_DIN 11       
#define PIN_CLK 13       
#define NUM_MATRIX 4      

LedControl matriceLed = LedControl(PIN_DIN, PIN_CLK, PIN_CS, NUM_MATRIX);


const byte* getChiffre(int num) {
    switch (num) {
        case 0:
            return CHIFFRE_0;
        case 1:
            return CHIFFRE_1;
        case 2:
            return CHIFFRE_2;
        case 3:
            return CHIFFRE_3;
        case 4:
            return CHIFFRE_4;
        case 5:
            return CHIFFRE_5;
        case 6:
            return CHIFFRE_6;
        case 7:
            return CHIFFRE_7;
        case 8:
            return CHIFFRE_8;
        case 9:
            return CHIFFRE_9;
        default:
            return nullptr;  // Retourne nullptr si num n'est pas entre 0 et 9
    }
}

// Initialisation des matrices
void initMatrix() 
{
  for(int i = 0; i < NUM_MATRIX; i++)
  {
    // Initialisation de la matrice LED
    matriceLed.shutdown(i, false);       // shutdown     : "true" active le mode "sommeil", tandis que "false" active le mode "normal"
    matriceLed.setIntensity(i, 5);       // setIntensity : valeur pouvant aller de 0 à 15 (pour 16 niveaux de luminosité, donc)
    matriceLed.clearDisplay(i);          // clearDisplay : éteint toutes les LEDs de la matrice
  }
}

// Afficher Chiffre sur une matrice choisie par adresse
void afficherChiffre(const byte* pointeurVersChiffreOuSymbole, int adresse) 
{
  
  // Parcours des 8 lignes
  for (int ligne = 0; ligne < 8; ligne++){
    // Et affichage des 8 colonnes pour chacune de ces lignes, avec fonction :
    // setRow(numero_de_matrice, numero_de_ligne, valeur_pour_cette_ligne)
    matriceLed.setRow(adresse, ligne, pgm_read_byte_near(pointeurVersChiffreOuSymbole + ligne));
  }
  
}