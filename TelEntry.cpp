#include "TelEntry.h"

TelEntry::TelEntry(string name, string telNumber)
{
    dt = new Date();
    this->name = name;
    this->telNumber = telNumber;
}

TelEntry::~TelEntry()
{
    delete dt;
}

EntryNode::EntryNode(string name, string telNumber): TelEntry(name, telNumber)
{
	prev =  nullptr;
	next = nullptr;
	
}

ostream & operator<<(ostream &out, const EntryNode *entry)
{
	out << setw(20) << entry->name
		<< setw(20) << entry->telNumber
		<< entry->dt;
	return out;
}

fstream & operator<<(fstream & out, const EntryNode * entry)
{
	out << entry->name << ";" 
		<< entry->telNumber << ";"
		<< entry->dt << endl;
	return out;
}
