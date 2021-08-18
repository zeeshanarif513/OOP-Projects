#include"student.h"

Student::Student() :Person()
{
	semester = 0;
	numCourses = 0;
	coursesName = NULL;
	marks = NULL;
}

Student::Student(int sem, int numC,string* nameC, int m[], string cnic, string n, string a, Date birthDate) :Person(cnic, n, a, birthDate)
{
	semester = sem;
	numCourses = numC;
	///*if (sizeof(nameC) / sizeof(nameC[0]) != numCourses)
	//{
	//	cout << "Error!!!!Courses names are not equal to number of courses." << endl;
	//	system("pause");
	//	exit(0);
	//	
	//}*/
	coursesName = new string[numCourses];
	for (int i = 0; i < numCourses; i++)
		coursesName[i] = nameC[i];
	marks = new int[numCourses];
	for (int i = 0; i < numCourses; i++)
		marks[i] = m[i];
}

Student::Student(int sem, int numC, string* nameC, int m[], const string& cnic, const string& n, const string& a, int dd, int mm, int yy) :Person(cnic, n, a, dd, mm, yy)
{
	semester = sem;
	numCourses = numC;
	/*if (sizeof(nameC) / sizeof(nameC[0]) != numC)
	{
		cout << "Error!!!!Courses names are not equal to number of courses." << endl;
		system("pause");
		exit(0);
		
	}*/
	coursesName = new string[numCourses];
	for (int i = 0; i < numCourses; i++)
		coursesName[i] = nameC[i];
	marks = new int[numCourses];
	for (int i = 0; i < numCourses; i++)
		marks[i] = m[i];
}

void Student::setSemester(int sem)
{
	semester = sem;
}

void Student::setNumCourses(int numC)
{
	numCourses = numC;
}

void Student::setCoursesName(string* nameC,int n)
{
	numCourses = n;
	/*if (sizeof(nameC) / sizeof(nameC[0]) != n)
	{
		cout << "Error!!!!Courses names are not equal to number of courses." << endl;
		system("pause");
		exit(0);
	}*/
	for (int i = 0; i < numCourses; i++)
		coursesName[i] = nameC[i];
}

void Student::setMarks(int m[],int n)
{
	/*if (sizeof(coursesName) / sizeof(coursesName[0]) != n)
	{
		cout << "Error!!!!Marks are not equal to number of courses." << endl;
		system("pause");
		exit(0);
	}*/
	numCourses = n;
	for (int i = 0; i < numCourses; i++)
		marks[i] = m[i];
}

int Student::getSemester() const
{
	return semester;
}

int Student::getNumCourses() const
{
	return numCourses;
}

string* Student::getCoursesName() const
{
	return coursesName;
}

int* Student::getMarks() const
{
	return marks;
}

const Person& Student::getPersonalInfo() const
{
	return (Person&)*this;
}
Student::~Student()
{
	if (coursesName != NULL)
		delete[] coursesName;
	if (marks != NULL)
		delete[] marks;
}