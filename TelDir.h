#include "TelEntry.h"

using namespace std;

class TelDir
{
public:
	TelDir();

	bool addNewEntry(string name, string telNumber);
	void showTelDir(void);
	void showEntryByName(string name);
	void delEntryByName(string name);
	void modifyEntryByName(string name);
	void showEntryByFirstChar(char c);

private:
	EntryNode * head, *tail;

	EntryNode* findInsertPosition(EntryNode *newEntry);
	void insertEntry(EntryNode *position, EntryNode *newEntry);
	void showTitle(void);
	EntryNode* findEntry(string name);
	void delEntry(const EntryNode *entry);
	void modifyEntry(EntryNode *entry);
	void modifyTelNumber(EntryNode *entry);
	void modifyName(EntryNode *entry);
};
