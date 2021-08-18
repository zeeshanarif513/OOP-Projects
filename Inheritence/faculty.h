#ifndef _FACULTY_H
#define _FACULTY_H

#include"person.h"

class Faculty :virtual public Person
{
private:
	string qualification;
	string designation;
	string AreaofExperties;
	int numPublications;
	friend ostream& operator<<(ostream&, const Faculty&);
	friend istream& operator >> (istream&, Faculty&);
public:
	Faculty();
	Faculty(const string&, const string&, const string&, int, string = "\0", string = "\0", string = "\0", Date = {});
	Faculty(const string&, const string&, const string&, int, string = "\0", string = "\0", string = "\0", int=0,int=0,int=0);
	void setqualification(const string&);
	void setDesignation(const string&);
	void setExpertise(const string&);
	void setNumofPub(int);
	string getQualifiaction() const;
	string getDesignation() const;
	string getExpertise() const;
	int getNumofPub() const;
	const Person& getPersonalInfo() const;
	virtual ~Faculty();
};


#endif
