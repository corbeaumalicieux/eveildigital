#ifndef MENU_H
#define MENU_H

#define CODE_1 22
#define CODE_2 25
#define CODE_3 13
#define CODE_4 12
#define CODE_5 24
#define CODE_6 94
#define CODE_7 8
#define CODE_8 28
#define CODE_9 90
#define CODE_0 82

#define CODE_OK 64

#define CODE_UP 70
#define CODE_DOWN 21
#define CODE_LEFT 68
#define CODE_RIGHT 67

#define CODE_ASTERISK 66
#define CODE_HASHTAG 74

void initIR();
int getNumFromIR(int code);
int obtenirCode();

void selectionMenuPrincipal();
void selectionMenuHorloge();
void selectionMenuReveil();
void selectionHeureReveil();

#endif