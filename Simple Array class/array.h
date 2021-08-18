#ifndef _ARRAY_H
#define _ARRAY_H

template<typename Type>
class Array{
private:
	int size;
	Type *arr;
	//friend void print(Array);
	friend ostream& operator<<(ostream&, const Array<Type>&);
	friend istream& operator>>(istream&, Array<Type>&);
public:
	Array(int=5);
	Array(Type[], int);
	Array(Array&);
	
	void setval(Type, int);
	int getsize() const;
	Type getval(int) const;
	~Array();
};

#include"array.cpp"

#endif