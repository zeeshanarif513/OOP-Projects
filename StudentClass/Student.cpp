#include<string>
#include"student.h"



void student::setID(int n)
{
	id = n;
}
void student::setName(char a[], int size)
{
	strcpy(name, a);
}
void student::setMarks(int m)
{
	marks = m;
}
void student::setData(int ID, char a[], int size, int m)
{
	id = ID;
	strcpy(name, a);
	marks = m;
}

int student::getID()
{
	return id;
}

char* student::getName()
{
	return name;
}

int student::getMarks()
{
	return marks;
}
char student::getGrade()
{
	if (marks >= 90)
		return 'A';
	else if (marks >= 80)
		return 'B';
	else if (marks >= 60)
		return 'C';
	else if (marks >= 50)
		return 'D';
	else
		return 'F';
}