#ifndef _RATIONAL
#define _RATIONAL

#include<iostream>
using namespace std;
class rational
{
private:
	int num, denom;
	void simplify();
	friend ostream& operator<<(ostream&, const rational&);
	friend istream& operator>>(istream&, rational&);
public:
	rational();
	rational(int, int);
	rational(int);
	void set(int, int);
	void setnum(int);
	void setdenom(int);
	int getnum() const;
	int getdenom() const;
	rational operator+(const rational&);
	rational operator-(const rational&);
	rational operator*(const rational&);
	rational operator/(const rational&);
	rational operator++();
	rational operator++(int);
	rational operator--();
	rational operator--(int);
	bool operator< (const rational&);
	bool operator>= (const rational&);
	bool operator> (const rational&); 
	bool operator<= (const rational&);
	bool operator== (const rational&);
	bool operator!= (const rational&);
	operator double();

};

#endif