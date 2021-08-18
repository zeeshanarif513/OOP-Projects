#include"graduate.h"

Graduate::Graduate():Student(),thesisTitle(),facultyAdvisor(),areaOfResearch()
{
}

Graduate::Graduate(const string& Title, const string& FacQual, const string& FacDes, const string& FacExp, int FacPub, const string& FacCNIC, const string& FacName, const string& FacAdd, const Date& FacDOB, const string& ResearchArea, int StdSem, int StdNumC, string StdNameC[], int StdMarks[], string StdCNIC, string StdName, string StdAdd, Date StdDOB): Student(StdSem, StdNumC, StdNameC, StdMarks, StdCNIC, StdName, StdAdd, StdDOB),thesisTitle(Title),facultyAdvisor(FacQual, FacDes, FacExp, FacPub, FacCNIC, FacName, FacAdd, FacDOB),areaOfResearch(ResearchArea)
{
}

Graduate::Graduate(const string& Title, const Faculty& Advisor, const string& ResearchArea, int StdSem, int StdNumC, string StdNameC[], int StdMarks[], string StdCNIC, string StdName, string StdAdd, Date StdDOB) : Student(StdSem, StdNumC, StdNameC, StdMarks, StdCNIC, StdName, StdAdd, StdDOB), thesisTitle(Title), facultyAdvisor(Advisor), areaOfResearch(ResearchArea)
{
}

void Graduate::setThesisTitle(const string& Title)
{
	thesisTitle = Title;
}

void Graduate::setFacultyAdvisor(const Faculty& Advisor)
{
	facultyAdvisor = Advisor;
}

void Graduate::setFacultyAdvisor(const string& qual, const string& des, const string& exp, int pub)
{
	facultyAdvisor.setqualification(qual);
	facultyAdvisor.setDesignation(des);
	facultyAdvisor.setExpertise(exp);
	facultyAdvisor.setNumofPub(pub);
}

void Graduate::setResearchArea(const string& researchArea)
{
	areaOfResearch = researchArea;
}

string Graduate::getThesisTitle()
{
	return thesisTitle;
}

Faculty Graduate::getFacultyAdvisor()
{
	return facultyAdvisor;
}

string Graduate::getResearchArea()
{
	return areaOfResearch;
}

char Graduate::CalculateGrade() const
{
	int sum = 0, n = getNumCourses();
	float per;
	int *m = getMarks();
	for (int i = 0; i < n; i++)
		sum += m[i];
	per = (float)(sum / (n * 100)) * 100;
	if (per >= 90)
		return 'A';
	else if (per >= 70)
		return 'B';
	else if (per >= 60)
		return 'C';
	else
		return 'F';
}
Graduate::~Graduate()
{

}