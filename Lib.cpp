#include "Lib.h"

Date::Date()
{
	time_t now = time(NULL);
	tm *local = localtime(&now);
	year = local->tm_year + 1900;
	month = local->tm_mon + 1;
	day = local->tm_mday;
	week = weekToStr(local->tm_wday);
	hour = local->tm_hour;
	min = local->tm_min;
	sec = local->tm_sec;
}

string Date::weekToStr(int week) const
{
	string wk;
	switch (week) {
	case 0:
		wk.assign("Sunday");
		return wk;
	case 1:
		wk.assign("Monday");
		return wk;
	case 2:
		wk.assign("Tuesday");
		return wk;
	case 3:
		wk.assign("Wednesday");
		return wk;
	case 4:
		wk.assign("Thursday");
		return wk;
	case 5:
		wk.assign("Friday");
		return wk;
	case 6:
		wk.assign("Saturday");
		return wk;
	}
}

ostream & operator<<(ostream &out, const Date *dt)
{
	out << dt->year << "-" << dt->month << "-" << dt->day
		<< " " << dt->week << " "
		<< dt->hour << ":" << dt->min << ":" << dt->sec;
	return out;
}

fstream & operator<<(fstream & out, const Date * dt)
{
	out << dt->year << ";"
		<< dt->month << ";"
		<< dt->day << ";"
		<< dt->hour << ";"
		<< dt->min << ";"
		<< dt->sec << ";"
		<< dt->week << ";";
	return out;
}

bool confirm(void)
{
	cout << "Are you sure?[Y/N]" << endl;
	string op;
	cin >> op;
	while (1) {
		if (op[0] == 'Y' || op[0] == 'y') {
			return 1;
		} else if (op[0] == 'N' || op[0] == 'n') {
			cout << "Operation canceled." << endl;
			return 0;
		} else {
			cout << "[Y/N]?" << endl;
		}
	}
}

bool checkInput(string input, int st, int ed)
{
	if (st + '0' <= input[0] && input[0] <= ed + '0') {
		return true;
	}
	return false;
}

int askModifyMethod(void)
{
	int method;
	string input;
	cout << "1.Change name.\n2.Change telephone number.\n3.Return\nYour choose:\n";
	cin >> input;
	while (!checkInput(input, 1, 3)) {
		cout << "1.Change name.\n2.Change telephone number.\n3.Return\nYour choose:\n";
	}
	return (input[0] - '0');
}