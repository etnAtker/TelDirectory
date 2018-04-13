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

    friend ostream & operator<<(ostream &out, const Date *dt);	//Output date to console
	friend fstream & operator<<(fstream &out, const Date *dt);	//Output date to file
};

bool confirm(void);	//Ask user if it is confirmed.
bool checkInput(const string &input, int st, int ed);	//Check that if the string is a number and between st and ed
int askModifyMethod(void);
void split(vector<string> &list, string &str);	//Split string by ';'
void checkName(string &input);	//Check that if the string includes ';'
int getNumber(int st, int ed);	//Get a number between st and ed;

void inputLineFromCin(string &str); //Input a line of text and clear the input buffer.
