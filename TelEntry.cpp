#include "TelEntry.h"

TelEntry::TelEntry(string &name, string &telNumber)
{
    dt = new Date();
    this->name = name;
    this->telNumber = telNumber;
}

TelEntry::TelEntry(const vector<string> &list)
{
	dt = new Date(list);
	name = list[0];
	telNumber = list[1];
}

TelEntry::~TelEntry()
{
    delete dt;
}

EntryNode::EntryNode(string &name, string &telNumber): TelEntry(name, telNumber)
{
	prev = nullptr;
	next = nullptr;
}

EntryNode::EntryNode(const vector<string> &list): TelEntry(list)
{
	prev = nullptr;
	next = nullptr;
}

ostream& operator<<(ostream &out, const EntryNode *entry)
{
	out << setw(30) << entry->name
		<< setw(30) << entry->telNumber
		<< entry->dt;
	return out;
}

fstream& operator<<(fstream & out, const EntryNode *entry)
{
	out << entry->name << ";"
		<< entry->telNumber << ";";
	out	<< entry->dt;
	return out;
}
