EXE = intro
OBJS = main.o png.o rgbapixel.o intro.o

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall -Werror
LINKER = g++
LINKER_OPTS = -lpng

all : $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)

main.o : main.cpp RGB/png.h RGB/rgbapixel.h intro.cpp intro.h 
	$(COMPILER) $(COMPILER_OPTS) main.cpp

png.o : RGB/png.cpp RGB/png.h RGB/rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) RGB/png.cpp

rgbapixel.o : RGB/rgbapixel.cpp RGB/rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) RGB/rgbapixel.cpp

intro.o : intro.cpp intro.h
	$(COMPILER) $(COMPILER_OPTS) intro.cpp


clean :
	-rm -f *.o $(EXE)
