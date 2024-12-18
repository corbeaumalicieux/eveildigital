#ifndef RTC_H
#define RTC_H

#include <RTClib.h>

// Define the Horaire structure that holds hour, minute, and second
typedef struct Horaire {
    int heure;
    int minute;
    int seconde;
} Horaire;

// Function prototypes
void initRTC();  // Initialize the RTC
void afficherRTCNow();  // Display current RTC time
void cutTime(int time, int* d, int* u);  // Helper function to split time into tens and ones place
DateTime horaireToDt(Horaire horaire);  // Convert Horaire to DateTime
Horaire dtToHoraire(DateTime dt);  // Convert DateTime to Horaire
Horaire getCurrentHorloge();  // Get current Horaire (using RTC)
Horaire getCurrentAlarm();  // Get current Alarm Horaire

void afficherTime();  // Display current time
bool isToggleAlarm();  // Check if the alarm is toggled on or off
bool checkAlarm();  // Check if the alarm should be triggered
void toggleAlarm();  // Toggle alarm state (on/off)


#endif  // RTC_H
