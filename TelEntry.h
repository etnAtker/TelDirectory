#include "Lib.h"

using namespace std;

class TelEntry
{
public:
	string name;
    string telNumber;
	const Date *dt;

    TelEntry(string &name, string &telNumber);
	TelEntry(const vector<string> &list);
	~TelEntry();
};	//Save the data

class EntryNode: public TelEntry
{
public:
	EntryNode *prev, *next;

	EntryNode(string &name, string &telNumber);
	EntryNode(const vector<string> &list);
	
	friend ostream& operator<<(ostream &out, const EntryNode *entry);
	friend fstream& operator<<(fstream &out, const EntryNode *entry);
};	//Change the entry to a node in chain table