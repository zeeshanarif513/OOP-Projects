//Muhammad Zeeshan Arif
//BSCS(2nd)

#include<fstream>
#include<iostream>
#include<string>
using namespace std;
const int SIZE = 15;
const char* FileName = "data.dat";
struct DoB {
	int day;
	int month;
	int year;
};
struct student {
	int id;
	char name[100];
	DoB birthDate;
	int marks;
};
void insert(student[], int&, int);
void Delete(student[], int&, int);
int findElement(student[], int, int);
void modify(student[], int, int);
void displayData(student[], int);
void fileWrite(student [], fstream &, int);
int main()
{
	int Id, loc, numElements;
	student std[SIZE];
	fstream file;
	file.open(FileName,ios::in | ios::binary);
	if (!file)
	{
		cout << "File could not be opened." << endl;
		
	}
	else {
		file.read((char*)&numElements, sizeof(int));
		file.read((char*)std, (sizeof(student))*numElements);
		file.close();


		char  operation;
		do
		{
			cout << "________Menu________" << endl;
			cout << "For insertion press I or i." << endl;
			cout << "For deletion press D or d." << endl;
			cout << "For finding a structure in array press F or f." << endl;
			cout << "For modification in array press M or m." << endl;
			cout << "For printing the data press P or p" << endl;
			cout << "Press X or x to exit." << endl;
			cin >> operation;
			switch (operation)
			{
			case 'I':
			case 'i':
				if (numElements == SIZE)
				{
					cout << "Sorry!Array is full." << endl;
					break;
				}
				cout << endl << "Enter the ID you want to insert: ";
				cin >> Id;
				loc = findElement(std, numElements, Id);
				if (loc == -1)
					insert(std, numElements, Id);
				else
				{
					cout << "Error! ID already exist." << endl;
				}
				break;
			case 'D':
			case 'd':
				if (numElements == 0)
				{
					cout << "Error!Array is empty." << endl;
					break;
				}

				cout << "Enter the id you want to delete in the array: ";
				cin >> Id;
				Delete(std, numElements, Id);
				break;
			case 'F':
			case 'f':
				if (numElements == 0)
				{
					cout << "Error!Array is empty." << endl;
					break;
				}
				cout << "enter Student id you want to search: ";
				cin >> Id;
				loc = findElement(std, numElements, Id);
				if (loc == -1)
					cout << "Student ID " << Id << " is not found ." << endl;
				else
				{
					cout << "Student ID " << Id << " is found ." << endl << endl;
					cout << "Student ID: " << std[loc].id << endl;
					cout << "Student name: " << std[loc].name << endl;
					cout << "Date of Birth: " << std[loc].birthDate.day << "/" << std[loc].birthDate.month << "/" << std[loc].birthDate.year << endl;
					cout << "Student marks: " << std[loc].marks << endl;
				}
				break;
			case 'M':
			case 'm':
				if (numElements == 0)
				{
					cout << "Error!Array is empty." << endl;
					break;
				}
				cout << "Enter the Student ID you want to modify: ";
				cin >> Id;
				loc = findElement(std, numElements, Id);
				if (loc == -1)
					cout << "Student ID " << Id << " is not found ." << endl;
				else
				{
					modify(std, numElements, loc);
				}
				break;
			case 'P':
			case 'p':
				displayData(std, numElements);
				break;
			case 'X':
			case 'x':
				fileWrite(std, file, numElements);
				break;
			default:
				cout << "Error!You entered wrong choice." << endl;
			}

		} while (operation != 'X' && operation != 'x');
		
	}

	system("pause");
	return 0;
}
void insert(student arr[], int& size, int Id)
{
	int i, loc;
	for (loc = 0; loc < size; loc++)
	{
		if (arr[loc].id >= Id)
			break;
	}
	for (i = size - 1; i >= loc; i--)
	{
		arr[i+1]=arr[i];
	}
	arr[loc].id = Id;
	cout << "Enter Student Name: ";
	cin.ignore();
	cin.getline(arr[loc].name, 100);
	cout << "Enter Student Birth Date: " << endl;
	cout << "Enter day: ";
	cin >> arr[loc].birthDate.day;
	cout << "Enter month: ";
	cin >> arr[loc].birthDate.month;
	cout << "Enter year: ";
	cin >> arr[loc].birthDate.year;
	cout << "Enter Student marks: ";
	cin >> arr[loc].marks;
	size++;
}
void Delete(student arr[], int& size, int n)
{
	int i, loc;
	for (loc = 0; loc < size; loc++)
	{
		if (arr[loc].id == n)
			break;
	}
	if (loc != size)
	{
		for (i = loc; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
	else
		cout << "The number you entered is not present in the array." << endl;
}
int findElement(student arr[], int size, int searchID)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].id == searchID)
			return i;
	}
	return -1;
}
void modify(student arr[], int size, int loc)
{
	int choice;
	cout << "Press 1 if you want to modify Student name." << endl;
	cout << "Press 2 if you want to modify Student Birth Date." << endl;
	cout << "Press 3 if you want to modify Student marks." << endl;
	cout << "Enter a choice: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter the correct name: ";
		cin.ignore();
		cin.getline(arr[loc].name, 100);
		break;
	case 2:
		cout << "Enter correct Birth Date: " << endl;
		cout << "Enter day: ";
		cin >> arr[loc].birthDate.day;
		cout << "Enter month: ";
		cin >> arr[loc].birthDate.month;
		cout << "Enter year: ";
		cin >> arr[loc].birthDate.year;
		break;
	case 3:
		cout << "Enter the corrected marks: ";
		cin >> arr[loc].marks;
		break;
	default:
		cout << "Sorry! Wrong choice." << endl;
	}
}
void displayData(student arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl << endl;
		cout << "Student ID: " << arr[i].id << endl;
		cout << "Student name: " << arr[i].name << endl;
		cout << "Date of Birth: " << arr[i].birthDate.day << "/" << arr[i].birthDate.month << "/" << arr[i].birthDate.year << endl;
		cout << "Student marks: " << arr[i].marks << endl;
	}
}
void fileWrite(student arr[], fstream &file, int size)
{
	file.open(FileName, ios::out | ios::binary);
	if (!FileName)
	{
		cout << "File is not opened." << endl;

	}
	else {
		file.write((char*)&size, sizeof(int));
		file.write((char*)arr, (sizeof(student))*size);
		file.close();
	}

}