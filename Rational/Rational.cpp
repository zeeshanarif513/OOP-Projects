#include"Rational.h"
void rational::simplify()
{
	int dividend, divisor, rem;
	dividend = num < 0 ? -num : num;
	divisor = denom;
	rem = dividend%divisor;
	while (rem != 0)
	{
		dividend = divisor;
		divisor = rem;
		rem = dividend%divisor;
	}
	num /= divisor;
	denom /= divisor;
}
rational::rational()
{
	num = 0;
	denom = 1;
}
rational::rational(int n, int d)
{
	num = n;
	denom = d == 0 ? 1 : d;
	if (denom<0)
	{
		num = -num;
		denom = -denom;
	}
	simplify();
}
rational::rational(int n)
{
	num = n;
	denom = 1;
}
void rational::set(int n, int d)
{
	num = n;
	denom = d == 0 ? 1 : d;
	if (denom<0)
	{
		num = -num;
		denom = -denom;
	}
	simplify();
}
void rational::setnum(int n)
{
	num = n;
}
void rational::setdenom(int d)
{
	denom = d == 0 ? 1 : d;
	if (denom<0)
	{
		denom = -denom;
	}
}
int rational::getnum() const
{
	return num;
}
int rational::getdenom() const
{
	return denom;
}
rational rational::operator+(const rational& r)
{
	rational res;
	res.num = (num*r.denom) + (r.num*denom);
	res.denom = denom*r.denom;
	simplify();
	return res;
}
rational rational:: operator-(const rational& r)
{
	rational res;
	res.num = (num*r.denom) - (r.num*denom);
	res.denom = denom*r.denom;
	simplify();
	return res;
}
rational rational::operator*(const rational& r)
{
	rational res;
	res.num = num*r.num;
	res.denom = denom*r.denom;
	simplify();
	return res;
}
rational rational::operator/(const rational& r)
{
	rational res;
	res.num = num*r.denom;
	res.denom = denom*r.num;
	simplify();
	return res;
}
rational rational::operator++()
{
	num += denom;
	simplify();
	return *this;
}
rational rational::operator++(int)
{
	rational temp = *this;
	num += denom;
	simplify();
	return temp;
}
rational rational::operator--()
{
	num -= denom;
	simplify();
	return *this;
}
rational rational::operator--(int)
{
	rational temp = *this;
	num -= denom;
	simplify();
	return temp;
}
bool rational::operator< (const rational& r)
{
	return num*r.denom<denom*r.num;
}
bool rational::operator>= (const rational& r)
{
	return !(*this<r);
}
bool rational::operator> (const rational& r)
{
	return num*r.denom>denom*r.num;
}
bool rational::operator<= (const rational& r)
{
	return !(*this>r);
}
bool rational::operator== (const rational& r)
{
	return num*r.denom==denom*r.num;
}
bool rational::operator!= (const rational& r)
{
	return !(*this == r);
}
rational::operator double()
{
	return (double)num / denom;
}