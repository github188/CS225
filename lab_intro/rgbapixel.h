// Copyright 2016 Kailang Fu

#ifndef RGBAPIXEL_H_
#define RGBAPIXEL_H_

typedef unsigned char uint8_t;

class RGBAPixel {
 public:
    // Byte for the red component of the pixel.
    uint8_t red;
    // Byte for the green component of the pixel.
    uint8_t green;
    // Byte for the blue component of the pixel.
    uint8_t blue;
    // Byte for the alpha component of the pixel.
    uint8_t alpha;

    // Constructs a default RGBAPixel.
    // A default pixel is completely opaque (non-transparent) and white.
    RGBAPixel();

    // Constructs an opaque RGBAPixel with the given red, green, blue color values.
    // The alpha component of the pixel constructed should be 255.
    RGBAPixel(uint8_t red, uint8_t green, uint8_t blue);
};

#endif  // RGBAPIXEL_H_
