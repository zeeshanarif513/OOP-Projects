#pragma once
#ifndef _COLOR_H
#define _COLOR_H

class color {
private:
	unsigned char red, green, blue;
public:
	color(unsigned char = 0, unsigned char = 0, unsigned char = 0);
	void setColor(unsigned char, unsigned char, unsigned char);
	void setRed(unsigned char);
	void setGreen(unsigned char);
	void setBlue(unsigned char);
	unsigned char getRed() const;
	unsigned char getGreen() const;
	unsigned char getBlue() const;
	char* colorName() const;
};
#endif