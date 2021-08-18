#ifndef _UNDERGRADUATE_H
#define _UNDERGRADUATE_H
#include"student.h"
#include"faculty.h"

class Undergraduate :public Student
{
private:
	string projectTitle;
	Faculty projectSupervisor;
	friend ostream& operator<<(ostream&, const Undergraduate&);
	friend istream& operator >> (istream&, Undergraduate&);

public:
	Undergraduate();
	Undergraduate(const string&, const string&, const string&, const string&, int, const string&, const string&, const string&, const Date&, int = 0, int = 0, string[] = {}, int[] = {}, string = "\0", string = "\0", string = "\0", Date = {});
	Undergraduate(const string&, const Faculty&, int = 0, int = 0, string[] = {}, int[] = {}, string = "\0", string = "\0", string = "\0", Date = {});
	void setprojectTitle(const string&);
	void setprojectSupervisor(const Faculty&);
	void setprojectSupervisor(const string&, const string&, const string&, int);
	string getprojectTitle();
	Faculty getprojectSupervisor();
	char CalculateGrade() const;
	virtual ~Undergraduate();
};


#endif