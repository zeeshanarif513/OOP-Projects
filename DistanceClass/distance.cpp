#include"distance.h"

distnce::distnce()
{
	feet = 0;
	inch = 0;
}

distnce::distnce(int i)
{
	feet = i / 12;
	inch = i % 12;
}

distnce::distnce(int f, int i)
{
	feet = f;
	inch = i;
	simplify();
}

void distnce::simplify()
{
	feet = feet + inch / 12;
	inch = inch % 12;
}


void distnce::setFeet(int f)
{
	feet = f;
	simplify();
}

void distnce::setInch(int i)
{
	feet = i / 12;
	inch = i % 12;
}

void distnce::setDistance(int f, int i)
{
	feet = f;
	inch = i;
	simplify();
}

int distnce::getFeet()
{
	return feet;
}

int distnce::getinch()
{
	return inch;
}

distnce distnce::operator+(const distnce& d)
{
	distnce res;
	res.feet = feet + d.feet + (inch + d.inch) / 12;
	res.inch = (inch + d.inch) % 12;
	return res;
}

distnce distnce::operator-(const distnce& d)
{
	distnce res;
	res.feet = (feet>d.feet)?feet - d.feet:d.feet-feet;
	res.inch = (inch>d.inch)?inch - d.inch:d.inch-inch;
	return res;
}

distnce distnce::operator++()
{
	feet = feet + 1;
	inch = inch + 1;
	return *this;
}

distnce distnce::operator++(int)
{
	distnce temp = *this;
	feet = feet + 1;
	inch = inch + 1;
	return temp;
}

distnce distnce::operator--()
{
	feet = feet - 1;
	inch = inch - 1;
	return *this;
}

distnce distnce::operator--(int)
{
	distnce temp = *this;
	feet = feet - 1;
	inch = inch - 1;
	return temp;
}

bool distnce::operator<(const distnce& d)
{
	return ((feet * 12 + inch) < (d.feet * 12 + d.inch));
}

bool distnce::operator>(const distnce& d)
{
	return ((feet * 12 + inch) > (d.feet * 12 + d.inch));
}

bool distnce::operator<=(const distnce& d)
{
	return !(*this > d);
}

bool distnce::operator>=(const distnce& d)
{
	return !(*this < d);
}

bool distnce::operator==(const distnce& d)
{
	return ((feet * 12 + inch) == (d.feet * 12 + d.inch));
}

bool distnce::operator!=(const distnce& d)
{
	return !(*this == d);
}

distnce& distnce::operator=(const distnce& d)
{
	feet = d.feet;
	inch = d.inch;
	return *this;
}
