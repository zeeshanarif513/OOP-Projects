#include<fstream>
#include <iostream>
using namespace std;
const int SIZE = 20;

struct Birthdate {
	int day;
	int month;
	int year;
};
struct Employee {
	int ID;
	char name[50];
	Birthdate DateOfBirth;
	int salary;
};
void insert(Employee Rec[], int& len, int id)
{
	bool flag = true;
	int index, i;
	for (i = 0; i < len; i++)
	{
		if (id == Rec[i].ID) {
			cout << "ID already exists." << endl;
			flag = false;
			break;
		}
	}
	if (flag==true)
	{
		i = 0;
		for (index = 0; index < len; index++)
		{
			if (Rec[index].ID >= id)
				break;
		}
		for (i = len - 1; i >= index; i--)
		{
			Rec[i + 1] = Rec[i];
		}
		cout << "Enter Employee info: " << endl;
		Rec[index].ID=id;
		cin.ignore();
		cout << "Enter name: ";
		cin.getline(Rec[index].name, 50);
		cout << "Enter Date of Birth: " << endl;
		cout << "Enter day: ";
		cin >> Rec[index].DateOfBirth.day;
		cout << "Enter month: ";
		cin >> Rec[index].DateOfBirth.month;
		cout << "Enter year: ";
		cin >> Rec[index].DateOfBirth.year;
		cout << "Enter Salay: ";
		cin >> Rec[index].salary;
		len++;
	}

}
void DeleteValues(Employee Rec[], int& len, int id)
{
	bool flag = false;
	int index, i;
	for (i = 0; i < len; i++)
	{
		if (id == Rec[i].ID) {
			flag = true;
			index = i;
			break;
		}
	}
	if (flag == true) {
		for (i = index; i < len; i++)
		{
			Rec[i] = Rec[i + 1];
		}
		len--;
	}
	
}
int findvalue(Employee Rec[],int len,int id)
{
	int i,index=-1;
	for (i = 0; i < len; i++)
	{
		if (Rec[i].ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void ModifyValues(Employee Rec[], int len, int location)
{
	char choice;
	cout << "Enter N/n for modifying name." << endl;
	cout << "Enter D/d for modifying date of birth." << endl;
	cout << "Enter S/s for modifying salary." << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice) {
	case 'N': case'n':
		cout << "Enter the new name: ";
		cin.ignore();
		cin >> Rec[location].name;
		break;
	case 'D': case 'd':
		cout << "Enter the correct date of birth." << endl;
		cout << "Enter day: ";
		cin >> Rec[location].DateOfBirth.day;
		cout << "Enter month: ";
		cin >> Rec[location].DateOfBirth.month;
		cout << "Enter year: ";
		cin >> Rec[location].DateOfBirth.year;
		break;
	case 'S': case's':
		cout << "Enter new salary: ";
		cin >> Rec[location].salary;
		break;
	default:
		cout << "sorry.wrong choice." << endl;
	}
}
void DisplayArray(Employee Rec[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cout << "***Displaying Data of Employee " << i + 1 << "***" << endl << endl;
		cout << "Employee id: " << Rec[i].ID << endl;
		cout << "Employee name: " << Rec[i].name << endl;
		cout << "Employee date of birth: " << Rec[i].DateOfBirth.day << "/" << Rec[i].DateOfBirth.month << "/" << Rec[i].DateOfBirth.year << endl;
		cout << "Employee salary: " << Rec[i].salary << endl;
	}
}

int main()
{
	Employee emp[SIZE] = { 0 };
	const char* File = "file.dat";
	int numRecord,id,l;
	char option;
	fstream Datafile;
	Datafile.open(File, ios::in | ios::binary); 
	if (Datafile.fail())
			cout << "File could not be opened." << endl;
	else {
		Datafile.read((char*)&numRecord, sizeof(int));
		Datafile.read((char*)emp, sizeof(emp[0])*numRecord);
		Datafile.close();
		
		do
		{
			cout << "Enter I/i to insert" << endl;
			cout << "Enter D/d to Delete Values" << endl;
			cout << "Enter F/f to find" << endl;
			cout << "Enter M/m to Modify Values" << endl;
			cout << "Enter U/u to Display " << endl;
			cout<< "Enter E/e to EXIT: ->  ";
			cin >> option;
			switch (option)
			{
				case 'i': case 'I':
				{
					cout << "Enter the id you want to insert: ";
					cin>>id;
					insert(emp,numRecord,id);
					break;
				}
				case 'd': case 'D':
				{
					if (numRecord == 0)
					{
						cout << "Array is Empty:" << endl;
						break;
					}
					else {
						cout << "enter the id you want to delete: ";
						cin >> id;
						DeleteValues(emp, numRecord, id);
						break;
					}
				}
				case 'f': case 'F':
				{
					cout << "Enter an id: " ;
					cin >> id;
					l=findvalue(emp, numRecord, id);
					if (l == -1)
						cout << "id does not exist." << endl;
					else {
						cout << "id found." << endl;
						cout << "Employee id: " << emp[l].ID << endl;
						cout << "Employee name: " << emp[l].name << endl;
						cout << "Employee date of birth: " << emp[l].DateOfBirth.day << "/" << emp[l].DateOfBirth.month << "/" << emp[l].DateOfBirth.year << endl;
						cout << "Employee salary: " << emp[l].salary << endl;
					}
					break;
				}
				case 'm': case 'M':
				{
					cout << "Enter id: ";
					cin >> id;
					l = findvalue(emp, numRecord, id);
					if (l == -1)
						cout << "id does not exist." << endl;
					else {
						ModifyValues(emp, numRecord, l);
					}
					break;
				}
				case 'u': case 'U':
					if (numRecord == 0)
					{
						cout << "array is empty." << endl;
						break;
					}
					DisplayArray(emp, numRecord);
					break;
				case 'e': case 'E':
					break;
				default:
					cout << "Sorry wrong choice." << endl;
			}

		} while (option != 'e'&&option != 'E');
		Datafile.open(File, ios::out | ios::binary); 
		if (Datafile.fail())
			cout << "File could not be opened." << endl;
		else {
			Datafile.write((char*)&numRecord, sizeof(int));
			Datafile.write((char*)emp, sizeof(emp[0])*numRecord);
			Datafile.close();
		}

	}
	cout << "Program Ended Press Any Key To Exit Screen....." << endl;
	system("pause");
	return 0;
}