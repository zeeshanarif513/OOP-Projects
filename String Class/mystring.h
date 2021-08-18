#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<iostream>
using namespace std;

class mystring {
private:
	char* ptr;
	friend ostream& operator<<(ostream&, const mystring&);
	friend istream& operator>>(istream&, mystring&);
public:
	mystring();
	mystring(const char*);
	mystring(const mystring&);
	mystring(const char*, int);
	mystring(char, int);
	mystring(const mystring&, int, int);
	mystring operator=(const mystring&);
	void operator+=(const mystring&);
	mystring operator+(const mystring&);
	bool operator<(const mystring&);
	bool operator>=(const mystring&);
	bool operator>(const mystring&);
	bool operator<=(const mystring&);
	bool operator==(const mystring&);
	bool operator!=(const mystring&);
	char operator[](int) const;
	char& operator[](int);
	void append(int, char);
	void append(const mystring&);
	void append(const mystring&, int);
	void append(const mystring&, int, int);
	void assign(int, char);
	void assign(const mystring&);
	void assign(const mystring&, int);
	void assign(const mystring&, int, int);
	int capacity() const;
	char* begin() const;
	char* c_str() const;
	void clear();
	int compare(const mystring&);
	int compare(int, int, const mystring&);
	void copy(const mystring&, int, int);
	bool empty() const;
	char* end() const;
	void erase(int, int);
	void insert(int, int, char);
	void insert(int, const mystring&);
	void replace(int, int, const mystring&);
	void resize(int, char);
	mystring substr(int, int);
	void swap(mystring&);
	int find(char, int);
	int find(const mystring&, int);

	~mystring();
};

#endif