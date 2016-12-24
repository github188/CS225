// Copyright 2016 Kailang Fu

#ifndef IMAGE_H
#define IMAGE_H

#include "png.h"

class Image : public PNG {
 public:
    void flipleft();
    void adjustbrightness(int r, int g, int b);
    void invertcolors();

 private:
    const int clump(int v);
};

#endif  // IMAGE_H
