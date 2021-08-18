//Muhammad Zeeshan Arif
//BSCS(2nd)


#include"mystring.h"


ostream& operator<<(ostream&, const mystring&);
istream& operator >> (istream&, mystring&);

int main()
{
	char str[] = "I am a muslim";
	mystring s1, s2("Zeeshan"), s3(s2);
	mystring s4(str, 4), s5('c', 12);
	mystring s6(str, 7, 6);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << "Enter a string: ";
	cin >> s1;
	cout << s1 << endl;
	s1 = s6;
	cout << s1 << endl;
	s2 += s5;
	cout << s2 << endl;
	mystring s7 = s1 + s2;
	cout << s7 << endl;
	cout << s1[4] << endl;
	s2[3] = 'c';
	cout << s2 << endl;
	s3.append(5, 'y');
	cout << s3 << endl;
	s1.append(s2);
	cout << s1 << endl;
	s4.append(str, 5);
	cout << s4 << endl;
	s1.append(s2, 3, 5);
	cout << s1 << endl;
	s1.assign(12, 'z');
	cout << s1 << endl;
	s2.assign(str);
	cout << s2 << endl;
	s4.assign(str);
	cout << s4 << endl;
	s5.assign(s4, 2, 5);
	cout << s5 << endl;
	int test;
	test = s1.compare(s2);
	cout << test << endl;
	test = s5.compare(2, 4, s4);
	cout << test << endl;
	s1.copy(s2, 2, 5);
	cout << s1 << endl;
	cout << s3 << endl;
	s3.erase(1, 4);
	cout << s3 << endl;
	s3.insert(3, 5, 'g');
	cout << s3 << endl;
	s4.insert(2, str);
	cout << s4 << endl;
	s3.replace(1, 2, s1);
	cout << s3 << endl;
	s2.resize(2, 'A');
	cout << s2 << endl;
	cout << s5.substr(1, 3) << endl;
	s1.swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	char ch;
	int pos, res;
	cout << "Enter a character to be searched: ";
	cin >> ch;
	cout << "Enter the position where you want to start searching: ";
	cin >> pos;
	res = s6.find(ch, pos);
	if (res == -1)
		cout << "Character " << ch << " is not found." << endl;
	else
	{
		cout << "Character " << ch << " is found." << endl;
		cout << "Postion is " << res << endl;
	}
	char s[50];
	cin.ignore();
	cout << "Enter the string you want to search: ";
	cin.getline(s, 50);
	cout << "Enter the position where you want to start searching: ";
	cin >> pos;
	res = s7.find(s, pos);
	if (res == -1)
		cout << "STRING " << s << " is not found." << endl;
	else
	{
		cout << "STRING " << s << " is  found." << endl;
		cout << "Postion is " << res << endl;
	}
	mystring s9;
	cout << "Enter a string: ";
	cin >> s9;
	cout << s9 << endl;

	system("pause");
	return 0;
}

ostream& operator<<(ostream& out, const mystring& s)
{
	if (s.ptr != NULL)
		out << s.ptr;
	return out;
}
istream& operator >> (istream& in, mystring& s)
{
	int i;
	char temp[1000];
	in >> temp;
	for (i = 0; temp[i]; i++);
	if (s.ptr != NULL)
		delete[]s.ptr;
	s.ptr = new char[i + 1];
	for (i = 0; temp[i]; i++)
		s.ptr[i] = temp[i];
	s.ptr[i] = '\0';
	return in;
}
