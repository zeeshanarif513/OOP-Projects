//Muhammad Zeeshan Arif
//BSCS(2nd)


#include"Rational.h"
#include<iostream>
using namespace std;
//rational operator+(rational&, rational);
int main()
{
	rational r1, r2(2, 3), r3(-3, 2), r4;
	r1.set(-4, -16);
	cout << r1 << endl;
	cout<<r2 << endl;
	cout<<r3 << endl;
	r1 = r2 + r3;  //r2.operator+( r3);
	cout<<r1 << endl;
	r2 = r1 - r3;
	cout<<r2 << endl;
	r4 = r1*r2;
	cout<<r4 << endl;
	r3 = r4 / r1;
	cout<<r3 << endl;
	cout<<r1 << endl;
	r4 = ++r2;
	r2++;
	cout<<r2 << endl;
	cout<<r4 << endl;
	r4 = r2++;
	cout<<r2 << endl;
	cout<<r4 << endl;
	r2--;
	cout<<r2 << endl;
	r3 = --r4;
	cout<<r3 << endl;
	r1 = r2 + r3;
	cout<<r1 << endl;
	cout << (double)r1 << endl;
	rational r5=2;
	cout << r5 << endl;
	cout << r4 << endl;
	//r3 = r2 + 1;
	cout << r5 << endl;
	r5 = {};
	cout << r5 << endl;
	system("pause");
	return 0;
}
ostream& operator<<(ostream& out, const rational& r)
{
	out << r.num << "/" << r.denom;
	return out;
}
istream& operator >> (istream& in, rational& r)
{
	cout << "Enter value of numerator: ";
	in >> r.num;
	cout << "Enter value of denominator";
	in >> r.denom;
	return in;
}
//rational operator+(rational& r1, rational r2)
//{
//	rational res;
//	res.setnum((r1.getnum()*r2.getdenom()) + (r2.getnum()*r1.getdenom()));
//	res.setdenom(r1.getdenom()*r2.getdenom());
//	return res;
//}