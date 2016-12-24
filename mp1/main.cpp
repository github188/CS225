#include "png.h"

int main()
{
	PNG in = PNG("in.png");
	PNG out = PNG(in.width(),in.height());
	for(unsigned int xi=0; xi<in.width(); xi++)
	{
		for(unsigned int yi=0; yi<in.height(); yi++)
		{
			RGBAPixel * inpixel = in.operator()(xi,yi);
			RGBAPixel * outpixel = out.operator()(in.width()-1-xi,in.height()-1-yi);
			outpixel->red = inpixel->red;
			outpixel->green = inpixel->green;
			outpixel->blue = inpixel->blue;
		}
	}
	out.writeToFile("out.png");
	return 0;
}
