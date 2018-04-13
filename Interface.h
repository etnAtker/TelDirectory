#include "TelDir.h"

TelDir* init(void);	//Load save file or creative a empty directory
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
