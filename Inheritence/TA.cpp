#include "TA.h"



TA::TA():Graduate(),Faculty(),courseOffer(),AllotedTO(),Student()
{
}

TA::TA(const string& course, const Faculty& allotedTO, const Graduate& TAasSTD, const Faculty& TAasFAC):Graduate(TAasSTD),Faculty(TAasFAC),courseOffer(course),AllotedTO(allotedTO),Student(TAasSTD)
{
}

void TA::setCourseOffer(const string& course)
{
	courseOffer = course;
}

void TA::setAllotedTO(const Faculty& allotedTO)
{
	AllotedTO = allotedTO;
}

string TA::getCourseOffer()
{
	return courseOffer;
}

Faculty TA::getAllotedTO()
{
	return AllotedTO;
}

TA::~TA()
{

}
