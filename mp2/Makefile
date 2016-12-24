COMPILER = g++
COMPILER_FLAGS = -c -g -O0 -Wall
LINKER = g++

all: testimage testscene

testscene : testscene.o scene.o png.o rgbapixel.o image.o
	$(LINKER) testscene.o scene.o png.o rgbapixel.o image.o -lpng -o testscene

testscene.o : testscene.cpp scene.h
	$(COMPILER) $(COMPILER_FLAGS) testscene.cpp

scene.o : scene.cpp scene.h
	$(COMPILER) $(COMPILER_FLAGS) scene.cpp

testimage : testimage.o png.o rgbapixel.o image.o
	$(LINKER) testimage.o png.o rgbapixel.o image.o -lpng -o testimage

testimage.o : testimage.cpp image.h
	$(COMPILER) $(COMPILER_FLAGS) testimage.cpp

image.o : image.cpp image.h
	$(COMPILER) $(COMPILER_FLAGS) image.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(COMPILER) $(COMPILER_FLAGS) rgbapixel.cpp

clean :
	- rm -f *.o testimage testscene
