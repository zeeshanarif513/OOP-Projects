#include"date.h"

Date::Date()
{
	day = month = year = 0;
}

Date::Date(int d, int m, int y)
{
	if (y < 1992 || y>2000)
	{
		cout << "ERROR!!!Invalid year." << endl;
		system("pause");
		exit(0);
	}
	year = y;
	if(m < 1 || m>12)
	{
		cout << "ERROR!!!Invalid month." << endl;
		system("pause");
		exit(0);
	}
	month = m;
	if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
	{
		if (d < 1 || d>31)
		{
			cout << "ERROR!!!Invalid day." << endl;
			system("pause");
			exit(0);
		}
	}

	else if (month == 2)
	{
		bool flag = checkleap();
		if (flag)
		{

			if(d < 1 || d>29)
			{
				cout << "ERROR!!!Invalid day." << endl;
				system("pause");
				exit(0);
			}
		}
		else
		{
			if (d < 1 || d>28)
			{
				cout << "ERROR!!!Invalid month." << endl;
				system("pause");
				exit(0);
			}
		}
	}
	else
	{
		if (d < 1 || d>30)
		{
			cout << "ERROR!!!Invalid month." << endl;
			system("pause");
			exit(0);
		}
	}
	day = d;
	
	
}


void Date::setDay(int d)
{
	if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
	{
		if (d < 1 || d>31)
		{
			cout << "ERROR!!!Invalid day." << endl;
			system("pause");
			exit(0);
		}
	}

	else if (month == 2)
	{
		bool flag = checkleap();
		if (flag)
		{

			if (d < 1 || d>29)
			{
				cout << "ERROR!!!Invalid day." << endl;
				system("pause");
				exit(0);
			}
		}
		else
		{
			if (d < 1 || d>28)
			{
				cout << "ERROR!!!Invalid month." << endl;
				system("pause");
				exit(0);
			}
		}
	}
	else
	{
		if (d < 1 || d>30)
		{
			cout << "ERROR!!!Invalid month." << endl;
			system("pause");
			exit(0);
		}
	}
	day = d;
}

void Date::setMonth(int m)
{
	if (m < 1 || m>12)
	{
		cout << "ERROR!!!Invalid month." << endl;
		system("pause");
		exit(0);
	}
	month = m;
}

void Date::setYear(int y)
{
	if (y < 1992 || y>2000)
	{
		cout << "ERROR!!!Invalid year." << endl;
		system("pause");
		exit(0);
	}
	year = y;
}

void Date::setDate(int d, int m, int y)
{
	if (y < 1992 || y>2000)
	{
		cout << "ERROR!!!Invalid year." << endl;
		system("pause");
		exit(0);
	}
	year = y;
	if (m < 1 || m>12)
	{
		cout << "ERROR!!!Invalid month." << endl;
		system("pause");
		exit(0);
	}
	month = m;
	if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
	{
		if (d < 1 || d>31)
		{
			cout << "ERROR!!!Invalid day." << endl;
			system("pause");
			exit(0);
		}
	}

	else if (month == 2)
	{
		bool flag = checkleap();
		if (flag)
		{

			if (d < 1 || d>29)
			{
				cout << "ERROR!!!Invalid day." << endl;
				system("pause");
				exit(0);
			}
		}
		else
		{
			if (d < 1 || d>28)
			{
				cout << "ERROR!!!Invalid month." << endl;
				system("pause");
				exit(0);
			}
		}
	}
	else
	{
		if (d < 1 || d>30)
		{
			cout << "ERROR!!!Invalid month." << endl;
			system("pause");
			exit(0);
		}
	}
	day = d;

}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}

bool Date::checkleap() const
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

Date::~Date()
{

}
