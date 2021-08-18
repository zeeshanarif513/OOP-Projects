#ifndef _DISTANCE_H
#define _DISTANCE_H

#include<iostream>
using namespace std;
class distnce {
private:
	int feet;
	int inch;
	void simplify();
	friend ostream& operator<<(ostream&, const distnce&);
	friend istream& operator>>(istream&, distnce&);
public:
	distnce();
	distnce(int);
	distnce(int, int);
	void setFeet(int);
	void setInch(int);
	void setDistance(int, int);
	int getFeet();
	int getinch();
	distnce operator+(const distnce&);
	distnce operator-(const distnce&);
	distnce operator++();
	distnce operator++(int);
	distnce operator--();
	distnce operator--(int);
	bool operator<(const distnce&);
	bool operator>(const distnce&);
	bool operator<=(const distnce&);
	bool operator>=(const distnce&);
	bool operator==(const distnce&);
	bool operator!=(const distnce&);
	distnce& operator=(const distnce&);

};

#endif