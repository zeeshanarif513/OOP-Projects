//Muhammad Zeeshan Arif
//BSCS(2nd)


#include"array.h"
#include<iostream>
using namespace std;

template<typename Type>
ostream& operator<<(ostream&, const Array<Type>&);
template<typename Type>
istream& operator >> (istream&, Array<Type>&);
int main()
{
	int len, x, i;
	Array<int> a1;
	Array<float> a2(5.5);
	int arr[5] = {2,4,6,8,10};
	Array<int> a3(arr, 5);
	Array<int> a4 = a3;
	a1.setval(10, 3);
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	len = a1.getsize();
	cout << "Enter value you want to insert: ";
	cin >> x;
	cout << "Enter index: ";
	cin >> i;
	while (i < 0 || i >= len)
	{
		cout << "wrong input.Please enter between 0 and " << len << ": ";
		cin >> i;
	}
	a2.setval(x, i);
	cout << a2 << endl;
	Array<int> a;
	cin >> a;
	cout << a << endl;
	system("pause");
	return 0;
}

//template<typename Type>
//void print(Array<Type> a)
//{
//	cout << "The size of array is " << a.size << endl;
//	cout << "Array is "<<endl;
//	for (int i = 0; i < a.size; i++)
//		cout << a.arr[i] << " ";
//	cout << endl << endl;
//}

template<typename Type>
ostream& operator<<(ostream& out, const Array<Type>& a)
{
	cout << "The size of array is " << a.size << endl;
	cout << "Array is " << endl;
	for (int i = 0; i < a.size; i++)
		cout << a.arr[i] << " ";
	cout << endl << endl;
	return out;
}

template<typename Type>
istream& operator >> (istream& in, Array<Type>& a)
{
	cout << "Enter the size of array: ";
	in >> a.size;
	for (int i = 0; i < a.size; i++)
	{
		cout << "Enter element at Array[" << i << "]:";
		in >> a.arr[i];
	}
	return in;
}
