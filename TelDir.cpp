#include "TelDir.h"

using namespace std;

TelDir::TelDir()
{
	head = nullptr;
	tail = nullptr;
}

bool TelDir::addNewEntry(string name, string telNumber)
{
	EntryNode *newEntry = new EntryNode(name, telNumber);
	if (!newEntry) {
		return false;
	}

	if (head) {
		head = newEntry;
		tail = newEntry;
	} else {
		EntryNode *position = findInsertPosition(newEntry);
		insertEntry(position, newEntry);
	}
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
	cout << setiosflags(ios::left)
		<< setw(20) << "Name"
		<< setw(15) << "Telephone Number"
		<< "Save Time";
}

EntryNode* TelDir::findEntry(string name)
{
	EntryNode *entry = head;
	EntryNode *result = nullptr;
	while (entry) {
		if (entry->name == name) {
			result = entry;
			break;
		}
	}
	return result;
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
		cout << entry;
	}
}

void TelDir::showEntryByName(string name)
{
	EntryNode *entry = findEntry(name);
	if (entry) {
		showTitle();
		cout << entry;
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
		modifyTelNumber(entry);
		break;
	case 2:
		modifyName(entry);
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
	string telNumber;
	cin >> telNumber;
	if (confirm) {
		entry->telNumber = telNumber;
	}
}

void TelDir::modifyName(EntryNode *entry)
{
	cout << "Input name:";
	string name;
	string telNumber = entry->telNumber;
	cin >> name;

	if (confirm()) {
		if (addNewEntry) {
			delEntry(entry);
		} else {
			cout << "Can not create new entry.";
		}
	}
}

void TelDir::delEntryByName(string name)
{
	EntryNode *entry = findEntry(name);
	if (entry) {
		showTitle();
		cout << entry;
		if (confirm()) {
			delEntry(entry);
		}
	} else {
		cout << "No such entry.";
	}
}

void TelDir::modifyEntryByName(string name)
{
	EntryNode *entry = findEntry(name);
	if (entry) {
		modifyEntry(entry);
	} else {
		cout << "No such entry.";
	}
}

void TelDir::showEntryByFirstChar(char c)
{

}

