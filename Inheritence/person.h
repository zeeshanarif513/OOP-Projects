#ifndef _PERSON_H
#define _PERSON_H

#include"date.h"
#include<string>

class Person {
private:
	string CNIC;
	string name;
	string address;
	Date DoB;
	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator >> (istream&, Person&);
	bool checkCNIC() const;
public:
	Person();
	Person(const string&, const string&, const string&, int, int, int);
	Person(const string&, const string&, const string&, const Date&);
	void setCNIC(const string&);
	void setName(const string&);
	void setAddress(const string&);
	void setDOB(const Date&);
	void setPerson(const string&, const string&, const string&, const Date&);
	string getCNIC() const;
	string getName() const;
	string getAddress() const;
	Date getDOB() const;
	virtual const Person& getPersonalInfo() const = 0;
	virtual ~Person();
};

#endif
