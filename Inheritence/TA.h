#ifndef _TA_H
#define _TA_H

#include"graduate.h"
#include"faculty.h"

class TA:public Graduate,public Faculty
{
private:
	string courseOffer;
	Faculty AllotedTO;
	friend ostream& operator<<(ostream&, const TA&);
	friend istream& operator >> (istream&, TA&);
public:
	TA();
	TA(const string&, const Faculty&, const Graduate&, const Faculty&);
	void setCourseOffer(const string&);
	void setAllotedTO(const Faculty&);
	string getCourseOffer();
	Faculty getAllotedTO();
	virtual ~TA();
};

#endif