#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

class Date 
{
private:
    int year, month, day, hour, min, sec;
	string week;

public:
    Date();

	string weekToStr(int wk) const;

    friend ostream & operator<<(ostream &out, const Date *dt);
	friend fstream & operator<<(fstream &out, const Date *dt);
};

bool confirm(void);
bool checkInput(string input, int st, int ed);
int askModifyMethod(void);
