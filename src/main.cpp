/* BIBLIOTHEQUES */
#include <Arduino.h>
#include <Wire.h>

/* PROGRAMMES */
#include "display.h"
#include "menu.h"
#include "matrix.h"
#include "rtc.h"
#include "melode.h"

void setup() 
{
  // Initialisation moniteur série
  Serial.begin(9600);

  // Initialisation des composants
  bool run_mode = true;
  bool config_mode = !run_mode;
 

  if(config_mode)
  {
    initRTC(); 

    initDisplay();
    initIR();

    selectionMenuPrincipal();
  }

  if(run_mode)
  {
    initSonnerie();
    initRTC();
    initMatrix();
  }
  
}

void loop() 
{
  afficherRTCNow();
  afficherTime();
  checkAlarm();
}