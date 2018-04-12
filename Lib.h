#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

class TelDir;
class TelEntry;
class EntryNode;

class Date 
{
private:
    int year, month, day, hour, min, sec;
	string week;

public:
    Date();
	Date(const vector<string> &list);

	string weekToStr(int wk) const;

    friend ostream & operator<<(ostream &out, const Date *dt);
	friend fstream & operator<<(fstream &out, const Date *dt);
};

bool confirm(void);
bool checkInput(const string &input, int st, int ed);
int askModifyMethod(void);
void split(vector<string> &list, string &str);
void checkName(string &input);
int getNumber(int st, int ed);

void inputLineFromCin(string &str);
