#include "TelDir.h"

using namespace std;

int main()
{
	string name = "Tom";
	string tel = "123456789";
	TelDir *dir = new TelDir();
	fstream file("1.txt", ios::out);
	dir->addNewEntry(name, tel);
	delete dir;
}