#include <iostream>
#include <stdlib.h>

#include "intro.h"
#include "RGB/png.h"

#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc == 2) 
	{
		unsigned int width = (unsigned int)atoi(argv[1]);
		std::cout << "Calling myArt(" << width << ", " << width << ") and saving it as `art.png`." << std::endl;
		
		PNG png = myArt(width, width);
		png.writeToFile("art.png");
	}
	else 
	{
		std::cout << "Rotating `in.png` as `out.png`" << std::endl;
		rotate("in_02.png", "out.png");
	}
	
	return 0;
}
