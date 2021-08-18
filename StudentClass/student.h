#ifndef _STUDENT_H
#define _STUDENT_H



class student {
private:
	int id;
	string name;
	int marks;

public:
	void setID(int);
	void setName(char[], int);
	void setMarks(int);
	void setData(int, char[], int, int);
	int getID();
	char* getName();
	int getMarks();
	char getGrade();

#endif