#include"Rectangle.h"
#include"color.h"

Rectangle::Rectangle() :clr()
{
	width = 1;
	height = 2;
}

Rectangle::Rectangle(int w, int h, unsigned char r, unsigned char g, unsigned char b) :clr(r, g, b)
{
	width = w;
	height = h;
}

Rectangle::Rectangle(int w, int h, const color& c):clr(c)
{
	width = w;
	height = h;
}

Rectangle::Rectangle(const Rectangle& r):clr(r.clr)
{
	width = r.width;
	height = r.height;
}

void Rectangle::setRectangle(int w, int h, unsigned char r, unsigned char g, unsigned char b)
{

	width = w;
	height = h;
	clr.setColor(r, g, b);
}
void Rectangle::setRectangle(int w, int h, const color& c)
{

	width = w;
	height = h;
	clr=c;
}

void Rectangle::setheight(int h)
{
	height = h;
}

void Rectangle::setWidth(int w)
{
	width = w;
}

void Rectangle::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	clr.setColor(r, g, b);
}

void Rectangle::setColor(const color& c)
{
	clr = c;
}

int Rectangle::getHeight() const
{
	return height;
}

int Rectangle::getWidth() const
{
	return width;
}

char* Rectangle::getColor() const
{
	return clr.colorName();
}

int Rectangle::getArea() const
{
	return width*height;
}

int Rectangle::getPerimeter() const
{
	return 2 * (width + height);
}