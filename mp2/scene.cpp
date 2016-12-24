// Copyright 2016 Kailang Fu

#include "scene.h"

#include <iostream>

using std::cout;
using std::endl;

/**
 * Initializes this Scene object to be able to hold "max" number of images.
**/
Scene::Scene(int max) {
    this->max = max;

    imgs = new Image*[max];
    xs = new int[max]; ys = new int[max];

    for (int i = 0; i < max; ++i)
        imgs[i] = NULL;
}

/**
 * Frees all space that was dynamically allocated by this Scene.
**/
Scene::~Scene() {
    clear();
}


/**
 * The copy constructor makes this Scene an independent copy of the source.
**/
Scene::Scene(const Scene &source) {
    copy(source);
}

/**
 * The assignment operator for the Scene class.
 * (1) checks for self assignment, 
 * (2) then deletes everything this Scene has allocated,
 * (3) then makes this Scene an independent copy of the source,
 * (4) then returns a reference to the current instance.
**/
const Scene &Scene::operator=(const Scene &source) {
   if (&source == this)
        return *this;

    clear();
    copy(source);

    return *this;
} 

void Scene::clear() {
    for (int i = 0; i < max; ++i)
        if (imgs[i] != NULL) delete imgs[i];

    delete[] imgs;
    delete[] xs; delete ys;
}

void Scene::copy(const Scene &source) {
    max = source.max;

    imgs = new Image*[max];
    xs = new int[max]; ys = new int[max];

    for (int i = 0; i < max; ++i) {
        imgs[i] = new Image(*source.imgs[i]);
        xs[i] = source.xs[i]; ys[i] = source.ys[i];
    }
}

/**
 * Modifies the size of the array of Image pointers without changing their indices.
**/
void Scene::changemaxlayers(int newmax) {
    for (int i = max; i < newmax; ++i)
        if (imgs[i] != NULL) {
            cout << "invalid newmax" << endl;
            return;
        }

    Image **newimgs = new Image*[newmax];
    int *newxs = new int[newmax], *newys = new int[newmax];

    for (int i = 0; i < max; ++i) {
        newimgs[i] = imgs[i];
        newxs[i] = xs[i]; newys[i] = ys[i];
    }

    for (int i = max; i < newmax; ++i)
        newimgs[i] = NULL;    
}

/**
 * This function will add a picture to the scene, by placing it in the array cell corresponding to the given index, and storing its x coordinate and y coordinate.
**/
void Scene::addpicture(const char *FileName, int index, int x, int y) {
    if (!valid(index)) {
        cout << "index out of bounds" << endl;
        return;
    }

    Image *img = new Image();
    img->readFromFile(FileName);

    if (imgs[index] != NULL)
        delete imgs[index];

    imgs[index] = img;
    xs[index] = x; ys[index] = y;
}

/**
 * Moves an Image from one layer to another.
**/
void Scene::changelayer(int index, int newindex) {
    if (!valid(index) || !valid(newindex)) {
        cout << "invalid index" << endl;
        return;
    }

    if (index == newindex) return;

    if (imgs[newindex] != NULL)
        delete imgs[newindex];

    imgs[newindex] = imgs[index];
    xs[newindex] = xs[index]; ys[newindex] = ys[index];

    imgs[index] = NULL;
}

/**
 * Changes the x and y coordinates of the Image in the specified layer.
**/
void Scene::translate(int index, int xcoord, int ycoord) {
    if (!valid(index) || imgs[index] == NULL) {
        cout << "invalid index" << endl;
        return;
    }

    xs[index] = xcoord; ys[index] = ycoord;
}

/**
 * Deletes the Image at the given index.
**/
void Scene::deletepicture(int index) {
    if (!valid(index) || imgs[index] == NULL) {
        cout << "invalid index" << endl;
        return;
    }

    delete imgs[index];
    imgs[index] = NULL;
}

/**
 * This function will return a pointer to the Image at the specified index, not a copy of it.
**/
Image *Scene::getpicture(int index) const {
    if (!valid(index)) {
        cout << "invalid index" << endl;
        return NULL;
    }

    return imgs[index];
}

/**
 * Draws the whole scene on one Image and returns that Image by value.
**/
Image Scene::drawscene() const {
    int maxw = 0, maxh = 0;
    for (int i = 0; i < max; ++i) {
        if (imgs[i] == NULL) continue;

        int maxx = xs[i] + imgs[i]->width(), maxy = ys[i] + imgs[i]->height();
        if (maxx > maxw) maxw = maxx;
        if (maxy > maxh) maxh = maxy;
    }

    Image *img = new Image();
    img->resize(maxw, maxh);

    for (int i = 0; i < max; ++i) {
        if (imgs[i] == NULL) continue;

        int w = imgs[i]->width(), h = imgs[i]->height();

        for (int x = 0; x < w; ++x)
            for (int y = 0; y < h; ++y)
                *(*img)(xs[i] + x, ys[i] + y) = *(*imgs[i])(x, y);
    }

    return *img;
}

bool Scene::valid(int i) const {
    return 0 <= i && i < max;
}
