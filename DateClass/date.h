#ifndef _DATE_H
#define _DATE_H

class Date {
private:
	int day;
	int month;
	int year;
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
