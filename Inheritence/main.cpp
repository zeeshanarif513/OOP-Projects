#include"undergraduate.h"
#include"TA.h"


ostream& operator<<(ostream&, const Date&);
istream& operator >> (istream&, Date&);

ostream& operator<<(ostream&, const Person&);
istream& operator >> (istream&, Person&);

ostream& operator<<(ostream&, const Faculty&);
istream& operator >> (istream&, Faculty&);

ostream& operator<<(ostream&, const Student&);
istream& operator >> (istream&, Student&);

ostream& operator<<(ostream&, const Undergraduate&);
istream& operator >> (istream&, Undergraduate&);

ostream& operator<<(ostream&, const Graduate&);
istream& operator >> (istream&, Graduate&);

ostream& operator<<(ostream&, const TA&);
istream& operator >> (istream&, TA&);

int main()
{
	/*Faculty F("MS", "OOP", "TA", 2, "37102-9904481-9", "Zeeshan", "Rawalpindi", 26, 5, 1999);
	cout << F << endl;
	

	int marks[] = { 89,90,70 };
	string names[] = { "MA101","CS121","CS105" };

	Date d1 (26, 5, 1999);
	
	Graduate G("Game", F, "Graphics", 8, 3, names, marks, "37102-9904481-9", "Zeeshan", "Rawalpindi", d1);
	
	Faculty F1("Phd", "OOP", "Assisstant Professor", 25, "37102-9234567-9", "Aslam", "Rawalpindi", 2, 5, 2000);

	TA T("OOP", F1, G, F);

	cout << G << endl;
	cout << F1 << endl;
	cout << T << endl;

	TA t1;
	cout << "Enter TA information: ";
	cin >> t1;
	cout << t1;
	
*/
	Student *ptr = new TA;
	cin >> *ptr;
	cout <<*ptr;
	

	system("pause");
	return 0;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << setfill('0') << setw(2) << d.day << "/";
	out << setfill('0') << setw(2) << d.month << "/";
	out << setfill('0') << setw(4) << d.year;

	return out;
}

istream& operator >> (istream& in, Date& d)
{
	cout << endl;
	cout << "Enter year: ";
	in >> d.year;
	while (d.year < 1992 || d.year>2000)
	{
		cout << "Bad input.Please enter a valid year: ";
		in >> d.year;
	}
	cout << "Enter month: ";
	in >> d.month;
	while (d.month < 1 || d.month>12)
	{
		cout << "Bad input.PLease Enter between 1 and 12: ";
		in >> d.month;
	}
	cout << "Enter day: ";
	in >> d.day;
	if ((d.month < 8 && d.month % 2 != 0) || (d.month >= 8 && d.month % 2 == 0))
	{
		while (d.day < 1 || d.day>31)
		{
			cout << "Bad Input.Please enter between 1 and 31: ";
			in >> d.day;
		}
	}

	else if (d.month == 2)
	{
		bool flag = d.checkleap();
		if (flag)
		{

			while (d.day < 1 || d.day>29)
			{
				cout << "bad input.Please enter between 1 and 29: ";
				in >> d.day;
			}
		}
		else
		{
			while (d.day < 1 || d.day>28)
			{
				cout << "bad input.Please enter between 1 and 28: ";
				in >> d.day;
			}
		}
	}
	else
	{
		while (d.day < 1 || d.day>30)
		{
			cout << "Bad input.Please enter between 1 and 30: ";
			in >> d.day;
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "Name : " << p.name << endl;
	out << "CNIC : " << p.CNIC << endl;
	out << "Address : " << p.address << endl;
	out << "Date of Birth : ";
	out << p.DoB;
	return out;
}

istream& operator >> (istream& in, Person& p)
{
	cout << endl;
	cout << "Enter name: ";
	getline(cin, p.name, '\n');
	in.ignore();
	
	cout << "Enter CNIC: ";
	in >> p.CNIC;
	while (!p.checkCNIC())
	{
		in.ignore();
		cout << "Invalid CNIC!!!Please Enter CNIC along with dashes: ";
		in >> p.CNIC;
	}
	in.ignore();
	cout << "Enter Address: ";
	getline(cin, p.address, '\n');
	in.ignore();
	cout << "Enter Date of Birth: ";
	in >> p.DoB;
	return in;
}

ostream& operator<<(ostream& out, const Faculty& f)
{
	cout << endl;
	cout << "Faculty Information: " << endl;
	cout << (Person&)f << endl;
	out << "Qualification : " << f.qualification << endl;
	out << "Designation : " << f.designation << endl;
	out << "Area of Experties : " << f.AreaofExperties << endl;
	out << "Number of Publications : " << f.numPublications;
	return out;
}

istream& operator >> (istream& in, Faculty& f)
{
	cout << endl;
	in >> (Person&)f;
	cout << "Enter Qualification: ";
	getline(cin, f.qualification, '\n');
	in.ignore();
	in.clear();
	cout << "Enter Designation: ";
	getline(cin, f.designation, '\n');
	in.ignore();
	in.clear();
	cout << "Enter area of experties: ";
	getline(cin, f.AreaofExperties, '\n');
	in.ignore();
	in.clear();
	cout << "Enter number of Publication: ";
	in >> f.numPublications;
	return in;

}

ostream& operator<<(ostream& out, const Student& s)
{
	out << (Person&)s << endl;
	out << "Semester : " << s.semester << endl;
	out << "No. of courses : " << s.numCourses << endl;
	out << "Course Name\t\t\tMarks" << endl;
	for (int i = 0; i < s.numCourses; i++)
		out << s.coursesName[i] << "\t\t\t\t" << s.marks[i] << endl;
	return out;
}

istream& operator >> (istream& in, Student& s)
{
	cout << endl;
	in >> (Person&)s;
	cout << "Enter Semester: ";
	in >> s.semester;
	cout << "Enter no. of courses: ";
	in >> s.numCourses;
	delete[]s.coursesName;
	delete[]s.marks;
	s.coursesName = new string[s.numCourses];
	s.marks = new int[s.numCourses];
	for (int i = 0; i < s.numCourses; i++)
	{
		in.ignore();
		in.clear();
		cout << "Enter name of course " << i + 1 << " : ";
		getline(in, s.coursesName[i], '\n');
		in.ignore();
		in.clear();
		cout << "Enter marks of course " << i + 1 << " : ";
		in >> s.marks[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Undergraduate& u)
{
	cout << "Undergraduate student information: " << endl;
	out << (Student&)u << endl;
	out << "Project Title: " << u.projectTitle << endl;
	out << "Project Supervisor Information: " << endl;
	out << u.projectSupervisor;
	return out;
}

istream& operator >> (istream& in, Undergraduate& u)
{
	cout << endl;
	in >> (Student&)u;
	cout << "Enter Project Title: ";
	in >> u.projectTitle;
	in.ignore();
	cout << "Enter Supervisor Information: ";
	in >> u.projectSupervisor;
	return in;
}

ostream& operator<<(ostream& out, const Graduate& g)
{
	out << "Graduate  Student information: " << endl;
	out << (Student&)g << endl;
	out << "Thesis Title: " << g.thesisTitle << endl;
	out << "Faculty Advisor Information: " << endl;
	out << g.facultyAdvisor << endl;
	out << "Area of Research: " << g.areaOfResearch;
	return out;
}

istream& operator >> (istream& in, Graduate& g)
{
	cout << endl;
	in >> (Student&)g;
	cout << "Enter Thesis Title: ";
	in >> g.thesisTitle;
	in.ignore();
	cout << "Enter Faculty Advisor Information: ";
	in >> g.facultyAdvisor;
	cout << "Enter Area of Research: ";
	in >> g.areaOfResearch;
	in.ignore();
	return in;
}

ostream& operator<<(ostream& out, const TA& t)
{
	out << "TA Information : " << endl;
	out << (Graduate&)t << endl;
	out << "Qualification : " << t.getQualifiaction() << endl;
	out << "Designation : " << t.getDesignation() << endl;
	out << "Area of Experties : " << t.getExpertise() << endl;
	out << "Number of Publications : " << t.getNumofPub();
	out << "Course offered: " << t.courseOffer << endl;
	out << "Alloted to: " << endl;
	out << t.AllotedTO;
	return out;
}

istream& operator >> (istream& in, TA& t)
{
	cout << endl;
	cout << "Enter TA information as a Student: ";
	in >> (Graduate&)t;
	cout << "Enter TA information as a faculty member: ";
	in >> (Faculty&)t;
	cout << "Enter the course name that is offered to TA: ";
	in >> t.courseOffer;
	in.ignore();
	cout << "Enter Teacher information whom TA is alloted: ";
	in >> t.AllotedTO;
	return in;
}


