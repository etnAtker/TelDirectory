#include "TelEntry.h"

using namespace std;

class TelDir
{
public:
	TelDir();
	TelDir(fstream &file);

	bool addNewEntry(string &name, string &telNumber);
	bool addNewEntry(vector<string> &list);
	void showTelDir(void);
	void showEntryByName(string name);
	void delEntryByName(string name);
	void modifyEntryByName(string name);
	void showEntryByFirstChar(char c);
	void save(fstream &file);

private:
	EntryNode *head, *tail;

	EntryNode* findInsertPosition(EntryNode *newEntry);
	void insertEntry(EntryNode *position, EntryNode *newEntry);
	void showTitle(void);
	EntryNode* findEntry(string name);
	void delEntry(const EntryNode *entry);
	void modifyEntry(EntryNode *entry);
	void modifyTelNumber(EntryNode *entry);
	void modifyName(EntryNode *entry);
};
