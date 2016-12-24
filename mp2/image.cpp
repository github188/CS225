// Copyright 2016 Kailang Fu

#include "image.h"

#include "rgbapixel.h"

/**
 * Flips the image about a vertical line through its center by swapping pixels.
**/
void Image::flipleft() {
    int w = width(), h = height();
    RGBAPixel p;

    for (int x = 0; x < w / 2; ++x)
        for (int y = 0; y < h; ++y) {
            p = *(*this)(x, y);
            *(*this)(x, y) = *(*this)(w - x - 1, y);
            *(*this)(w - x - 1, y) = p;
        }
}

/**
 * Adds to the red, green, and blue parts of each pixel in the image.
**/
void Image::adjustbrightness(int r, int g, int b) {
    int w = width(), h = height();

    for (int x = 0; x < w; ++x)
        for (int y = 0; y < h; ++y) {
            RGBAPixel &p = *(*this)(x, y);
            p.red = clump(p.red + r);
            p.green = clump(p.green + g);
            p.blue = clump(p.blue + b);
        }
}

/**
 * Makes each RGB component of each pixel iequal to 255 minus its original value.
**/
void Image::invertcolors() {
    int w = width(), h = height();

    for (int x = 0; x < w; ++x)
        for (int y = 0; y < h; ++y) {
            RGBAPixel &p = *(*this)(x, y);
            p.red = 0xff - p.red;
            p.green = 0xff - p.green;
            p.blue = 0xff - p.blue;
        }
}

/**
 * Clump the input to a range of [0, 0xff].
**/
const int Image::clump(int v) {
    if (v < 0) return 0;
    if (v > 0xff) return 0xff;

    return v;
}
