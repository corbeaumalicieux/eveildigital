#include "menu.h"

/* BIBLIOTHEQUES */
#include "IRremote.hpp"

/* PROGRAMMES */
#include "display.h"

/* MISC */
#define PIN_IR 2

// Initialiser capteur infrarouge
void initIR()
{
  Serial.println(F("### Initialisation du capteur infrarouge ###"));
  IrReceiver.begin(PIN_IR, true);
  Serial.println(F("[SUCCES] Initialisation du capteur infrarouge réussie"));
}
// Retourne commande IR en code numéro
int getNumFromIR(int code)  
{ 
  /*
  OK = 101
  HAUT = 102
  BAS = 103
  GAUCHE = 104
  DROITE = 105
  * = 106
  # = 107
  */
  switch(code)
  {
    case CODE_1:
      return 1;
    case CODE_2:
      return 2;
    case CODE_3:
      return 3;   
    case CODE_4:
      return 4;
    case CODE_5:
      return 5;
    case CODE_6:
      return 6;
    case CODE_7:
      return 7;
    case CODE_8:
      return 8;
    case CODE_9:
      return 9;
    case CODE_0:
      return 0;

    case CODE_OK:
      return 101;   

    case CODE_UP:
      return 102;
    case CODE_DOWN:
      return 103;
    case CODE_LEFT:
      return 104;
    case CODE_RIGHT:
      return 105;

    case CODE_ASTERISK:
      return 106;
    case CODE_HASHTAG:
      return 107;

    default:
      return -1;               
  }
}  
// Retourne commande IR captée en code
int obtenirCode() 
{
    int code = -1;
    if (IrReceiver.decode()) 
    {
        if (IrReceiver.decodedIRData.protocol != UNKNOWN) 
        {
            code = getNumFromIR(IrReceiver.decodedIRData.command);

            Serial.print(F("Code IR Reçu: "));
            Serial.print(IrReceiver.decodedIRData.command);
            Serial.print(F(" / Nombre associé: "));
            Serial.println(code);
        }

        delay(500);
    }
    IrReceiver.resume();

    return code;    
}

// 1   : 
void selectionMenuPrincipal()
{
    afficherMenuPrincipal();
    bool isValid = false;
    int commande = -1;
    
    while(!isValid)
    {
      commande = obtenirCode();
      switch (commande)
      {
      case 1:
        IrReceiver.resume();  // Vide le buffer IR
        selectionMenuHorloge();
        isValid = true;
        break;   
      case 2:
        IrReceiver.resume();
        selectionMenuReveil();
        isValid = true;
        break;    
      case 3:
        // Bascule format 12/24
        IrReceiver.resume();
        isValid = true;
        break;     
        
      default:
        IrReceiver.resume();
        isValid = false;
        break;
      }
      delay(500);
    } 
    
}
// 1.0 : Modifier valeur "Horloge"
void selectionMenuHorloge()
{
    afficherMenuHorloge();
    bool isValid = false;
    int commande = -1;
    
    while(!isValid)
    {
      commande = obtenirCode();
      switch (commande)
      {
        
      // Modifer avec flèches  

      case 101:
        IrReceiver.resume();  // Vide le buffer IR
        selectionMenuPrincipal();
        isValid = true;
        break;
        
      default:
        IrReceiver.resume();
        isValid = false;
        break;
      }
      delay(500);
    } 
    
}

// 2  :
void selectionMenuReveil()
{
    afficherMenuReveil();
    bool isValid = false;
    int commande = -1;
    
    while(!isValid)
    {
      commande = obtenirCode();
      switch (commande)
      {
      case 1:
        IrReceiver.resume();  // Vide le buffer IR
        selectionHeureReveil();
        isValid = true;
        break;
      case 2:
        IrReceiver.resume();  // Vide le buffer IR
        // Bascule activer/désactiver réveil
        isValid = false;
        break;
      case 3:
        IrReceiver.resume();  // Vide le buffer IR
        // Bascule mélodie
        isValid = false;
        break;
      case 4:
        IrReceiver.resume();  // Vide le buffer IR
        // Modifier snooze
        isValid = false;
        break;

      case 0:
        IrReceiver.resume();  // Vide le buffer IR
        selectionMenuPrincipal();
        isValid = true;
        break;
        
      default:
        IrReceiver.resume();
        // Commande Invalide
        isValid = false;
        break;
      }
      delay(500);
    } 
    
}
// 2.1 : Modifier valeur "Reveil"
void selectionHeureReveil()
{
    afficherHeureReveil();
    bool isValid = false;
    int commande = -1;
    
    while(!isValid)
    {
      commande = obtenirCode();
      switch (commande)
      { 

      // Modifer avec flèches

      case 101:
        IrReceiver.resume();  // Vide le buffer IR
        selectionMenuPrincipal();
        isValid = true;
        break;
        
      default:
        IrReceiver.resume();
        isValid = false;
        break;
      }
      delay(500);
    } 
    
}
// 2.2 : Toggle "Réveil" 
// 2.3 : Toggle "Mélodie"
// 2.4 : Modifer valeur "Snooze"