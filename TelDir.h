#include "TelEntry.h"

using namespace std;

class TelDir
{
public:
	TelDir();
	TelDir(fstream &file);

	bool addNewEntry(string &name, string &telNumber);
	void showTelDir(void);
	void showEntryByName(string name);
	void showEntryByName(char c);
	void delEntryByName(string name);
	void modifyEntryByName(string name);
	void showEntryByFirstChar(char c);
	void save(fstream &file);

private:
	EntryNode *head, *tail;

	EntryNode* findInsertPosition(EntryNode *newEntry);
	void insertEntry(EntryNode *position, EntryNode *newEntry);
	void showTitle(void);
	void findEntry(string name, vector<EntryNode*> &list);
	void findEntry(char c, vector<EntryNode*> &list);
	void delEntry(const EntryNode *entry);
	void modifyEntry(EntryNode *entry);
	void modifyTelNumber(EntryNode *entry);
	void modifyName(EntryNode *entry);
	bool addNewEntry(const vector<string> &list);
	EntryNode* selectEntry(const vector<EntryNode*> &list);
};
