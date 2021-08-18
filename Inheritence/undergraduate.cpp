#include"undergraduate.h"

Undergraduate::Undergraduate():Student(),projectTitle(),projectSupervisor()
{
}

Undergraduate::Undergraduate(const string& Title,const string& FacQual, const string& FacDes, const string& FacExp, int FacPub, const string& FacCNIC, const string& FacName, const string& FacAdd, const Date& FacDOB, int StdSem, int StdNumC, string StdNameC[], int StdMarks[], string StdCNIC, string StdName, string StdAdd, Date StdDOB):Student(StdSem,StdNumC,StdNameC,StdMarks,StdCNIC,StdName,StdAdd,StdDOB),projectTitle(Title),projectSupervisor(FacQual,FacDes,FacExp,FacPub,FacCNIC,FacName,FacAdd,FacDOB)
{
}

Undergraduate::Undergraduate(const string& Title, const Faculty& Supervisor, int StdSem, int StdNumC, string StdNameC[], int StdMarks[], string StdCNIC, string StdName, string StdAdd, Date StdDOB):Student(StdSem,StdNumC,StdNameC,StdMarks,StdCNIC,StdName,StdAdd,StdDOB),projectTitle(Title),projectSupervisor(Supervisor)
{
}

void Undergraduate::setprojectTitle(const string& Title)
{
	projectTitle = Title;
}

void Undergraduate::setprojectSupervisor(const Faculty& Supervisor)
{
	projectSupervisor = Supervisor;
}

void Undergraduate::setprojectSupervisor(const string& qual, const string& des, const string& exp, int pub)
{
	projectSupervisor.setqualification(qual);
	projectSupervisor.setDesignation(des);
	projectSupervisor.setExpertise(exp);
	projectSupervisor.setNumofPub(pub);

}

string Undergraduate::getprojectTitle()
{
	return projectTitle;
}

Faculty Undergraduate::getprojectSupervisor()
{
	return projectSupervisor;
}

char Undergraduate::CalculateGrade() const
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
	else if (per >= 50)
		return 'D';
	else
		return 'F';
}

Undergraduate::~Undergraduate()
{

}