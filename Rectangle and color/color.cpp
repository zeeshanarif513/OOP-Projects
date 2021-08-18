#include"color.h"

color::color(unsigned char r, unsigned char g, unsigned char b)
{
	red = r >= 0 && r <= 255 ? r : 0;
	green = g >= 0 && g <= 255 ? g : 0;
	blue = b >= 0 && b <= 255 ? b : 0;
}

void color::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	red = r >= 0 && r <= 255 ? r : 0;
	green = g >= 0 && g <= 255 ? g : 0;
	blue = b >= 0 && b <= 255 ? b : 0;
}

void color::setRed(unsigned char r)
{
	red = r >= 0 && r <= 255 ? r : 0;
}

void color::setGreen(unsigned char g)
{
	green = g >= 0 && g <= 255 ? g : 0;
}

void color::setBlue(unsigned char b)
{
	blue = b >= 0 && b <= 255 ? b : 0;
}

unsigned char color::getRed() const
{
	return red;
}

unsigned char color::getGreen() const
{
	return green;
}

unsigned char color::getBlue() const
{
	return blue;
}

char* color::colorName() const
{
	if (red)
	{
		if (green)
		{
			if (blue)
			{
				return "white";
			}

			else
			{
				return "Yellow";
			}
		}
		else
		{
			if (blue)
			{
				return "Magenta";
			}

			else
			{
				return "Red";
			}
		}
	}
	else
	{
		if (green)
		{
			if (blue)
			{
				return "Cyon";
			}

			else
			{
				return "Green";
			}
		}
		else
		{
			if (blue)
			{
				return "Blue";
			}

			else
			{
				return "Black";
			}
		}
	}
	

}