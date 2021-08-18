#ifndef _DATE_H
#define _DATE_H

#include<iostream>
#include<iomanip>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
	bool checkleap() const;
public:
	Date();
	Date(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	~Date();
};
#endif
