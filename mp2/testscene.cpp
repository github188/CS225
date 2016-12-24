/**********************************************************
 * testscene.cpp -- part of CS225 MP2
 *		  	
 * This file performs some basic tests of the Scene class.
 * It is not intended to catch every possible error.You may 
 * modifty this or write your own testscene.cpp to perform 
 * additional tests.
 *		  	
 *   Author: Jonathan Ray
 *   Date: 02 Feb 2007
 */
		  	
#include <iostream>
using std::cout;
using std::endl;

#include "image.h"
#include "scene.h"

int main()
{
	Scene* set = new Scene(5);
	set->addpicture("in_01.png", 0, 0, 0);
	set->addpicture("in_02.png", 1, 60, 60);
	set->addpicture("in_03.png", 2, 150, 0);
	Image result = set->drawscene();
	result.writeToFile("scene.png");
	set->changemaxlayers(25);	
	set->changemaxlayers(2);
	set->changemaxlayers(5);
cout<<"adding pictures works"<<endl;
	set->changelayer(1, 3);
	result = set->drawscene();
	result.writeToFile("scene2.png");
cout<<"changing layers works"<<endl;
	set->translate(0, 50, 50);
	result = set->drawscene();
	result.writeToFile("scene3.png");
cout<<"translating doesn't cause crashes"<<endl;
	set->getpicture(0)->adjustbrightness(-70,-70,-70);
	result = set->drawscene();
	result.writeToFile("scene4.png");
cout<<"getpicture doesn't cause crashes"<<endl;
	set->deletepicture(3);
	result = set->drawscene();
	result.writeToFile("scene5.png");
cout<<"deleting pictures works"<<endl;
	Scene* sc = new Scene(*set);
	sc->getpicture(0)->flipleft();
	result = set->drawscene();
	result.writeToFile("scene6.png");  //scene 5 and scene 6 should be the same
	result = sc->drawscene();
	result.writeToFile("scene7.png");
cout<<"drawscene doesnt cause crashes.  also copy constructor"<<endl;
	delete set;
cout<<"destructor works"<<endl;
	set = new Scene(5);
cout<<"maxsize constructor works"<<endl;
	*set = *sc;
cout<<"operator= works"<<endl;
	result = set->drawscene();
	result.writeToFile("scene8.png");   //scene7 and scene8 should be the same.
	delete set;
	delete sc;
cout<<"destructor, operator=, maxsizeconstructor all work"<<endl;
	return 0;
}

