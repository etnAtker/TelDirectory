#include "TelEntry.h"

using namespace std;

class TelDir
{
public:
	TelDir();
	TelDir(fstream &file);
	~TelDir();

	bool addNewEntry(string &name, string &telNumber);	//Add new entry by name and telNumber
	void showTelDir(void);
	void showEntryByName(string name);	//Show entries by a exact name
	void showEntryByName(char c);	//Show entries by first character
	void delEntryByName(string name);
	void modifyEntryByName(string name);
	void save(fstream &file);

private:
	EntryNode *head, *tail;

	EntryNode* findInsertPosition(EntryNode *newEntry);	//Find an appropriate position to insert a new entry
	void insertEntry(EntryNode *position, EntryNode *newEntry);
	void showTitle(void);	//Show each column names
	void findEntry(string name, vector<EntryNode*> &list);	//Find all the entry that name is name
	void findEntry(char c, vector<EntryNode*> &list);	//Find all the entry that first character is c
	void delEntry(const EntryNode *entry);	//Delete an entry
	void modifyEntry(EntryNode *entry);
	void modifyTelNumber(EntryNode *entry);
	void modifyName(EntryNode *entry);
	bool addNewEntry(const vector<string> &list);	//Always be called by TelDir(fstream&). Add entry by infomation that list included
	EntryNode* selectEntry(const vector<EntryNode*> &list);	//Return the pointer of entry that user selected 
};
