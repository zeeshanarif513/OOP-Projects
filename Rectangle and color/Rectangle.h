#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include"color.h"

class Rectangle {
private:
	int width;
	int height;
	color clr;
public:
	Rectangle();
	Rectangle(int, int, unsigned char, unsigned char, unsigned char);
	Rectangle(int, int, const color&);
	Rectangle(const Rectangle&);
	void setRectangle(int, int, unsigned char, unsigned char, unsigned char);
	void setRectangle(int, int, const color&);
	void setheight(int);
	void setWidth(int);
	void setColor(unsigned char, unsigned char, unsigned char);
	void setColor(const color&);
	int getHeight() const;
	int getWidth() const;
	char* getColor() const;
	int getArea() const;
	int getPerimeter() const;
 };

#endif