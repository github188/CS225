#include "rgbapixel.h"

//RGBAPixel default constructor
RGBAPixel::RGBAPixel()
{
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}
//RGBAPixel constructor
RGBAPixel::RGBAPixel(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	blue = b;
	green = g;
	alpha = 255;
}
