#include"person.h"

Person::Person() :CNIC(), name(), address(), DoB()
{
}

Person::Person(const string& cnic, const string& n, const string& a, int d, int m, int y) : CNIC(cnic), name(n), address(a), DoB(d, m, y)
{
	if (!checkCNIC())
	{
		cout << "ERROR!!!Invalid CNIC" << endl;
		system("pause");
		exit(0);
	}
}


Person::Person(const string& cnic, const string& n, const string& a, const Date& birthDate) : CNIC(cnic), name(n), address(a), DoB(birthDate)
{
	if (!checkCNIC())
	{
		cout << "ERROR!!!Invalid CNIC" << endl;
		system("pause");
		exit(0);
	}
}

void Person::setCNIC(const string& cnic)
{
	if (!checkCNIC())
	{
		cout << "ERROR!!!Invalid CNIC" << endl;
		system("pause");
		exit(0);
	}
	CNIC = cnic;
}

void Person::setName(const string& n)
{
	name = n;
}

void Person::setAddress(const string& a)
{
	address = a;
}

void Person::setDOB(const Date& birthDate)
{
	DoB = birthDate;
}

void Person::setPerson(const string& cnic, const string& n, const string& a, const Date& birthDate)
{
	if (!checkCNIC())
	{
		cout << "ERROR!!!Invalid CNIC" << endl;
		system("pause");
		exit(0);
	}
	CNIC = cnic;
	name = n;
	address = a;
	DoB = birthDate;
}

string Person::getCNIC() const
{
	return CNIC;
}

string Person::getName() const
{
	return name;
}

string Person::getAddress() const
{
	return address;
}

Date Person::getDOB() const
{
	return DoB;
}
bool Person::checkCNIC() const
{
	if (CNIC.size() != 15)
		return false;
	if (CNIC[5] != '-' || CNIC[13] != '-')
		return false;
	for (int i = 0; i < 15; i++)
	{
		if (i == 5 || i == 13)
			i++;
		if (CNIC[i]<'0' || CNIC[i]>'9')
			return false;
	}
	return true;
}

Person::~Person()
{

}