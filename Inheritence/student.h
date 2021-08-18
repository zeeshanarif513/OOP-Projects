#ifndef _STUDENT_H
#define _STUDENT_H

#include"person.h"

class Student :public Person
{
private:
	int semester;
	int numCourses;
	string* coursesName;
	int *marks;
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator >> (istream&, Student&);
public:
	Student();
	Student(int, int, string*, int[], string = "\0", string = "\0", string = "\0", Date = {});
	Student(int, int, string*, int[], const string&, const string&, const string&, int, int, int);
	void setSemester(int);
	void setNumCourses(int);
	void setCoursesName(string*,int);
	void setMarks(int[],int);
	int getSemester() const;
	int getNumCourses() const;
	string* getCoursesName() const;
	int* getMarks() const;
	const Person& getPersonalInfo() const;
	virtual char CalculateGrade() const = 0;
	virtual ~Student();
};

#endif