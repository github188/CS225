#include "rgbapixel.h"

RGBAPixel::RGBAPixel() : red(0xff), green(0xff), blue(0xff), alpha(0xff) {
}

RGBAPixel::RGBAPixel(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b), alpha(0xff) {
}
