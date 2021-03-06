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

Date::Date(const vector<string> &list)
{
	stringstream buffer;
	buffer << list[2];
	buffer >> year;
	buffer.clear();
	buffer << list[3];
	buffer >> month;
	buffer.clear();
	buffer << list[4];
	buffer >> day;
	buffer.clear();
	buffer << list[5];
	buffer >> hour;
	buffer.clear();
	buffer << list[6];
	buffer >> min;
	buffer.clear();
	buffer << list[7];
	buffer >> sec;
	week = list[8];
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

ostream& operator<<(ostream &out, const Date *dt)
{
	out << setiosflags(ios::right) << setfill('0')
		<< dt->year << "-"  
		<< setw(2) << dt->month << "-" 
		<< setw(2) << dt->day << " " 
		<< dt->week << " "
		<< setw(2) << dt->hour << ":" 
		<< setw(2) << dt->min << ":" 
		<< setw(2) << dt->sec
		<< resetiosflags(ios::right) << setfill(' ');
	return out;
}

fstream& operator<<(fstream &out, const Date * dt)
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
	cin.ignore(0xffffff, '\n');
	while (1) {
		if (op[0] == 'Y' || op[0] == 'y') {
			return 1;
		} else if (op[0] == 'N' || op[0] == 'n') {
			cout << "Operation canceled." << endl;
			return 0;
		} else {
			cout << "[Y/N]?" << endl;
			cin >> op;
			cin.ignore(0xffffff, '\n');
		}
	}
}

bool checkInput(const string &input, int st, int ed)
{
	for (string::const_iterator ch = input.begin(); ch != input.end(); ch++) {
		if (!('0' <= *ch && *ch <= '9')) {
			return false;
		}
	}
	stringstream ss;
	int num = 0;
	ss << input;
	ss >> num;
	if (!(st <= num && num <= ed)) {
		return false;
	}
	return true;
}

int askModifyMethod(void)
{
	string input;
	cout << "1.Change name.\n2.Change telephone number.\n3.Return\nYour choose:\n";
	return getNumber(1, 3);
}

void split(vector<string> &list, string &str)
{
	auto st = str.begin();
	for (auto ch = str.begin(); ch != str.end(); ch++) {
		if (*ch == ';') {
			string frag(st, ch);
			list.push_back(frag);
			st = ch + 1;
		}
	}
}

void checkName(string &input)
{
	while (input.find(';') != string::npos) {
		cout << "\nName or telephone number can not include \";\", please input again:";
		inputLineFromCin(input);
	}
}

int getNumber(int st, int ed)
{
	string input;
	cin >> input;
	cin.ignore(0xffffff, '\n');
	while (!checkInput(input, st, ed)) {
		cout << "Input error! Please enter a correct number." << endl;
		cin >> input;
		cin.ignore(0xffffff, '\n');
	}
	stringstream ss;
	int num;
	ss << input;
	ss >> num;
	return num;
}

void inputLineFromCin(string &str)
{
	getline(cin, str);
	//cin.ignore();
}
