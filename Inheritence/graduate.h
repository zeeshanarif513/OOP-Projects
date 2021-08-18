#ifndef _GRADUATE_H
#define _GRADUATE_H
#include"student.h"
#include"faculty.h"

class Graduate :virtual public Student
{
private:
	string thesisTitle;
	Faculty facultyAdvisor;
	string areaOfResearch;
	friend ostream& operator<<(ostream&, const Graduate&);
	friend istream& operator >> (istream&, Graduate&);

public:
	Graduate();
	Graduate(const string&, const string&, const string&, const string&, int, const string&, const string&, const string&, const Date&, const string&, int = 0, int = 0, string[] = {}, int[] = {}, string = "\0", string = "\0", string = "\0", Date = {});
	Graduate(const string&, const Faculty&, const string&, int = 0, int = 0, string[] = {}, int[] = {}, string = "\0", string = "\0", string = "\0", Date = {});
	void setThesisTitle(const string&);
	void setFacultyAdvisor(const Faculty&);
	void setFacultyAdvisor(const string&, const string&, const string&, int);
	void setResearchArea(const string&);
	string getThesisTitle();
	Faculty getFacultyAdvisor();
	string getResearchArea();
	char CalculateGrade() const;
	virtual ~Graduate();

};


#endif