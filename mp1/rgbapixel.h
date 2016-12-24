#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H

class RGBAPixel
{
public:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
	RGBAPixel();
	RGBAPixel(unsigned char r, unsigned char g, unsigned char b);
};
#endif
