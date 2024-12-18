#include <display.h>

/* BIBLIOTHEQUES */
#include <Arduino.h>

#include <U8x8lib.h>

/* PROGRAMMES */
#include "horloge.h"

/* MISC */
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ 4/*U8X8_PIN_NONE*/);

void initDisplay(void)
{
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
}

/* AFFICHAGE DES MENUS DE SELECTION */      
// 1
void afficherMenuPrincipal()
{
  u8x8.drawString(0,0,"1: HORLOGE      ");     
  u8x8.drawString(0,1,"2: REVEIL       ");     
  u8x8.drawString(0,2,"3: FORMAT       ");   
  u8x8.drawString(0,3,"                "); 

  u8x8.refreshDisplay();    // Affiche les changements
  delay(1000);            // Délai de 2s    
}
// 1.0
void afficherMenuHorloge()
{
  u8x8.drawString(0,0,"OK: CONFIRMER   ");
  u8x8.drawString(0,1,"                "); 
  u8x8.drawString(0,2,"                "); 
  u8x8.drawString(0,3,"                ");     

  u8x8.refreshDisplay();    // Affiche les changements
  delay(1000);            // Délai de 2s    
}

// 2
void afficherMenuReveil()
{
  u8x8.drawString(0,0,"1: HEURE        ");
  u8x8.drawString(0,1,getToggleAlarm() ? "2: DESACTIVER   " : "2: ACTIVER      "); 
  u8x8.drawString(0,2,isFirstMelody    ? "3: MELODIE 1    " : "3: MELODIE 2    "); 
  u8x8.drawString(0,3,"0: RETOUR       ");     

  u8x8.refreshDisplay();    // Affiche les changements
  delay(1000);            // Délai de 2s    
}
// 2.1
void afficherHeureReveil()
{
  u8x8.drawString(0,0,"                ");  
  u8x8.drawString(0,1,"OK: CONFIRMER   ");
  u8x8.drawString(0,2,"                "); 
  u8x8.drawString(0,3,"                ");     

  u8x8.refreshDisplay();    // Affiche les changements
  delay(1000);            // Délai de 2s   
}


