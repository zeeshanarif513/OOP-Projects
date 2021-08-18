#include"faculty.h"

Faculty::Faculty() : qualification(), designation(), AreaofExperties(), numPublications(0),Person()
{
}

Faculty::Faculty(const string& qual, const string& des, const string& exp, int pub, string cnic, string n, string a, Date birthDate) : qualification(qual), designation(des), AreaofExperties(exp), numPublications(pub), Person(cnic, n, a, birthDate)
{
}

Faculty::Faculty(const string& qual, const string& des, const string& exp, int pub, string cnic, string n, string a, int d, int m, int y) : qualification(qual), designation(des), AreaofExperties(exp), numPublications(pub), Person(cnic, n, a, d, m, y)
{
}

void Faculty::setqualification(const string& qual)
{
	qualification = qual;
}

void Faculty::setDesignation(const string& des)
{
	designation = des;
}

void Faculty::setExpertise(const string& exp)
{
	AreaofExperties = exp;
}

void Faculty::setNumofPub(int pub)
{
	numPublications = pub;
}

string Faculty::getQualifiaction() const
{
	return qualification;
}

string Faculty::getDesignation() const
{
	return designation;
}

string Faculty::getExpertise() const
{
	return AreaofExperties;
}

int Faculty::getNumofPub() const
{
	return numPublications;
}

const Person& Faculty::getPersonalInfo() const
{
	return (Person&)*this;
}
Faculty::~Faculty()
{

}