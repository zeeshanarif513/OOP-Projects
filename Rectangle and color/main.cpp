//Muhammad Zeeshan Arif
//BSCS(2nd)

#include"Rectangle.h"
#include"color.h"
#include<iostream>

using namespace std;
void print(const Rectangle&);
int main()
{
	Rectangle r1;
	Rectangle r2(5, 4, 255, 0, 255);
	color c1;
	c1.setColor(255, 0, 0);
	print(r1);
	print(r2);
	r1.setRectangle(5, 4, c1);
	print(r1);
	Rectangle r3 = r1;
	print(r3);

	system("pause");
	return 0;
}

void print(const Rectangle& r)
{
	cout << endl;
	cout << "Height = " << r.getHeight() << endl;
	cout << "Width = " << r.getWidth() << endl;
	cout << "Color = " << r.getColor() << endl;
	cout << "Area = " << r.getArea() << endl;
	cout << "Perimeter = " << r.getPerimeter() << endl;
	cout << endl;
}