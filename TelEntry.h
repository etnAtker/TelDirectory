#include "Lib.h"

using namespace std;

class TelEntry
{
public:
	string name;
    string telNumber;
	const Date *dt;

    TelEntry(string name, string telNumber);
	~TelEntry();
};

class EntryNode: public TelEntry
{
public:
	EntryNode *prev, *next;

	EntryNode(string name, string telNumber);
	
	friend ostream & operator<<(ostream &out, const EntryNode *entry);
};