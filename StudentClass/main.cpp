//Muhammad Zeeshan Arif
//BSCS(2nd)

#include<iostream>
#include"student.h"
using namespace std;


int main()
{
	student s1, s2;
	int id, marks;
	char name[100];
	cout << "Enter data of student 1." << endl;
	cout << "Enter student id: ";
	cin >> id;
	cout << "Enter student name: ";
	cin.ignore();
	cin.getline(name,100);
	cout << "Enter student marks: ";
	cin >> marks;
	s1.setID(id);
	s1.setName(name, 100);
	s1.setMarks(marks);
	cout << "Grade of student 1 is " << s1.getGrade() << endl;
	cout << "Enter data of student 2." << endl;
	cout << "Enter student id: ";
	cin >> id;
	cout << "Enter student name: ";
	cin.ignore();
	cin.getline(name, 100);
	cout << "Enter student marks: ";
	cin >> marks;
	s2.setData(id, name, 100, marks);
	cout << "Grade of student 2 is " << s2.getGrade() << endl;
	system("pause");
	return 0;

}