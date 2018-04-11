#include "Interface.h"

using namespace std;

void welcome(void)
{
	cout << "Welcome to use etnAtker's telephone directory!\nInitializing..." << endl;
}

TelDir* init(void)
{
	cout << "Loading save file..." << endl;
	fstream sav("data.sav", ios::in);
	TelDir *dir;
	if (sav) {
		dir = new TelDir(sav);
		cout << "Success." << endl;
	} else {
		cout << "No save file." << endl;
		dir = new TelDir();
	}
	system("pause");
	return dir;
}

void mainLoop(TelDir *dir)
{
	menu();
	readChoise(dir);
}

void menu(void)
{
	system("cls");
	cout << "**************MENU**************" << endl;
	cout << "1. Add an entry to the directory." << endl;
	cout << "2. Show all entries." << endl;
	cout << "3. Search entries by name." << endl;
	cout << "4. Delete entries by name." << endl;
	cout << "5. Modify entries by name." << endl;
	cout << "6. Search entries intelligently(by the first character)." << endl;
	cout << "0. Save & exit.\n" << endl;

	cout << "Your choise:" << endl;
}

void readChoise(TelDir *dir)
{
	string ch;
	cin >> ch;
	cin.ignore();
	if (checkInput(ch, 0, 6)) {
		int op = ch[0] - '0';
		switch (op) {
		case 0:
			quitAndSave(dir);
		case 1:
			addNewEntry(dir);
			return;
		case 2:
			dir->showTelDir();
			system("pause");
			return;
		case 3:
			showEntryByName(dir);
			return;
		case 4:
			delEntryByName(dir);
			return;
		case 5:
			modifyEntryByName(dir);
			return;
		case 6:
			showEntryByFirstChar(dir);
			return;
		}
	} else {
		cout << "Input error! Please enter a correct number." << endl;
		system("pause");
	}
}

void addNewEntry(TelDir *dir)
{
	system("cls");
	string name, telNumber;
	cout << "Name:";
	inputLineFromCin(name);
	checkName(name);

	cout << "\nTelephone number:";
	inputLineFromCin(telNumber);
	checkName(telNumber);

	if (!dir->addNewEntry(name, telNumber)) {
		cout << "Failed to allocate memery." << endl;
	} else {
		cout << "Success" << endl;
	}
	system("pause");
}

void showEntryByName(TelDir *dir)
{
	string name;
	cout << "Name:";
	inputLineFromCin(name);
	dir->showEntryByName(name);
	system("pause");
}

void delEntryByName(TelDir *dir)
{
	string name;
	cout << "Name:";
	inputLineFromCin(name);
	dir->delEntryByName(name);
	system("pause");
}

void modifyEntryByName(TelDir *dir)
{
	string name;
	cout << "Name:";
	inputLineFromCin(name);
	dir->modifyEntryByName(name);
	system("pause");
}

void showEntryByFirstChar(TelDir *dir)
{}

void quitAndSave(TelDir *dir)
{
	fstream sav("data.sav", ios::out);
	dir->save(sav);
	delete dir;
	exit(0);
}
