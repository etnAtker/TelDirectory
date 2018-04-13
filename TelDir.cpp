#include "TelDir.h"

using namespace std;

TelDir::TelDir()
{
	head = nullptr;
	tail = nullptr;
}

TelDir::TelDir(fstream &file)
{
	head = nullptr;
	tail = nullptr;
	string entry;
	while (getline(file, entry)) {
		vector<string> list;
		split(list, entry);
		addNewEntry(list);
	}
}

TelDir::~TelDir()
{
	EntryNode *entry = head, *next;
	while (entry) {
		next = entry->next;
		delete entry;
		entry = next;
	}
}

bool TelDir::addNewEntry(string &name, string &telNumber)
{
	EntryNode *newEntry = new EntryNode(name, telNumber);
	if (!newEntry) {
		return false;
	}

	if (!head) {
		head = newEntry;
		tail = newEntry;
	} else {
		EntryNode *position = findInsertPosition(newEntry);
		insertEntry(position, newEntry);
	}
	return true;
}

bool TelDir::addNewEntry(const vector<string> &list)
{
	EntryNode *newEntry = new EntryNode(list);
	if (!newEntry) {
		return false;
	}

	if (!head) {
		head = newEntry;
		tail = newEntry;
	} else {
		insertEntry(nullptr, newEntry);
	}
	return true;
}

EntryNode* TelDir::selectEntry(const vector<EntryNode*>& list)
{
	cout << "Result includes more than one entry. Please select the entry you want to modify:" << endl;
	cout << "\t";
	showTitle();
	for (vector<EntryNode*>::const_iterator entry = list.begin(); entry != list.end(); entry++) {
		cout << entry - list.begin() + 1 << "\t" << *entry << endl;
	}
	cout << "Your choise:";
	int choise = getNumber(1, list.size());
	return *(list.begin() + choise - 1);
}

EntryNode* TelDir::findInsertPosition(EntryNode *newEntry)
{
	EntryNode *entry = head;
	bool biggest = true;
	while (entry) {
		if ((entry->name) > (newEntry->name)) {
			biggest = false;
			break;
		}
		entry = entry->next;
	}
	if (biggest) {
		return nullptr;
	} else {
		return entry;
	}
}

void TelDir::insertEntry(EntryNode * position, EntryNode * newEntry)
{
	if (position) {
		if (position == head) {
			position->prev = newEntry;
			newEntry->next = position;
			head = newEntry;
		} else {
			newEntry->prev = position->prev;
			position->prev->next = newEntry;
			position->prev = newEntry;
			newEntry->next = position;
		}
	} else {
		tail->next = newEntry;
		newEntry->prev = tail;
		tail = newEntry;
	}
}

void TelDir::showTitle(void)
{
	//system("cls");
	cout << setiosflags(ios::left)
		<< setw(30) << "Name"
		<< setw(30) << "Telephone Number"
		<< "Save Time" << endl;
}

void TelDir::findEntry(string name, vector<EntryNode*> &list)
{
	EntryNode *entry = head;
	EntryNode *result = nullptr;
	while (entry) {
		if (entry->name == name) {
			list.push_back(entry);
		}
		entry = entry->next;
	}
}

void TelDir::findEntry(char c, vector<EntryNode*>& list)
{
	EntryNode *entry = head;
	EntryNode *result = nullptr;
	while (entry) {
		if (entry->name[0] == c) {
			list.push_back(entry);
		}
		entry = entry->next;
	}
}

void TelDir::showTelDir(void)
{
	if (!head) {
		cout << "No record.";
		return;
	}
	showTitle();
	EntryNode *entry = head;
	while (entry) {
		cout << entry << endl;
		entry = entry->next;
	}
}

void TelDir::showEntryByName(string name)
{
	vector<EntryNode*> list;
	findEntry(name, list);
	if (list.size() != 0) {
		showTitle();
		for (vector<EntryNode*>::iterator entry = list.begin(); entry != list.end(); entry++) {
			cout << *entry << endl;
		}
	} else {
		cout << "No such entry.";
	}
}

void TelDir::showEntryByName(char c)
{
	vector<EntryNode*> list;
	findEntry(c, list);
	if (list.size() != 0) {
		showTitle();
		for (vector<EntryNode*>::iterator entry = list.begin(); entry != list.end(); entry++) {
			cout << *entry << endl;
		}
	} else {
		cout << "No such entry.";
	}
}

void TelDir::delEntry(const EntryNode *entry)
{
	if (head == entry && tail == entry) {
		head = nullptr;
		tail = nullptr;
		delete entry;
	} else if (head == entry) {
		head = entry->next;
		entry->next->prev = nullptr;
		delete entry;
	} else if (tail == entry) {
		tail = entry->prev;
		entry->prev->next = nullptr;
		delete entry;
	} else {
		entry->next->prev = entry->prev;
		entry->prev->next = entry->next;
		delete entry;
	}
}

void TelDir::modifyEntry(EntryNode *entry)
{
	int method = askModifyMethod();
	switch (method) {
	case 1:
		modifyName(entry);
		break;
	case 2:
		modifyTelNumber(entry);
		break;
	case 3:
		break;
	default:
		break;
	}
}

void TelDir::modifyTelNumber(EntryNode *entry)
{
	cout << "Input telephone number:";
	string name = entry->name;
	string telNumber;
	inputLineFromCin(telNumber);
	checkName(telNumber);

	if (confirm()) {
		if (addNewEntry(name, telNumber)) {
			delEntry(entry);
			cout << "Success." << endl;
		} else {
			cout << "Failed to allocate memory." << endl;
		}
	}
}

void TelDir::modifyName(EntryNode *entry)
{
	cout << "Input name:";
	string name;
	string telNumber = entry->telNumber;
	inputLineFromCin(name);
	checkName(name);

	if (confirm()) {
		if (addNewEntry(name, telNumber)) {
			delEntry(entry);
			cout << "Success." << endl;
		} else {
			cout << "Failed to allocate memory." << endl;
		}
	}
}

void TelDir::delEntryByName(string name)
{
	vector<EntryNode*> list;
	findEntry(name, list);
	if (list.size() == 1) {
		showTitle();
		cout << list[0] << endl;
		if (confirm()) {
			delEntry(list[0]);
			cout << "Success." << endl;
		}
	} else if(list.size() > 1) {
		EntryNode* entry = selectEntry(list);
		if (confirm()) {
			delEntry(entry);
			cout << "Success." << endl;
		}
	} else {
		cout << "No such entry.";
	}
}

void TelDir::modifyEntryByName(string name)
{
	vector<EntryNode*> list;
	findEntry(name, list);
	if (list.size() == 1) {
		cout << list[0] << endl;
		modifyEntry(list[0]);
	} else if(list.size() > 1) {
		modifyEntry(selectEntry(list));
	} else {
		cout << "No such entry.";
	}
}

void TelDir::save(fstream &file)
{
	EntryNode *entry = head;
	while (entry) {
		file << entry << endl;
		entry = entry->next;
	}
}

