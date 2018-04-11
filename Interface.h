#include "TelDir.h"

TelDir* init(void);
void welcome(void);

void mainLoop(TelDir *dir);

void menu(void);
void readChoise(TelDir *dir);

void addNewEntry(TelDir *dir);
void showEntryByName(TelDir *dir);
void delEntryByName(TelDir *dir);
void modifyEntryByName(TelDir *dir);
void showEntryByFirstChar(TelDir *dir);
void quitAndSave(TelDir *dir);
