#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

class Date 
{
private:
    int year, month, day, week, hour, min, sec;

public:
    Date();

	string weekToStr(void) const;

    friend ostream & operator<<(ostream &out, const Date *dt);
};

bool confirm(void);
bool checkInput(string input, int st, int ed);
int askModifyMethod(void);
