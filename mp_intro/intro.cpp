#include "RGB/png.h"
#include "RGB/rgbapixel.h"
#include "intro.h"

#include <string>
#include <cmath>
#include <cstdlib>

void rotate(std::string inputFile, std::string outputFile) {
	PNG pic(inputFile);
	PNG outPic(pic);
	for (size_t yi = 0; yi < pic.height(); yi++) {
		for (size_t xi = 0; xi < pic.width(); xi++) {
				outPic(pic.width() -1 - xi, pic.height() -1 - yi)->red = pic(xi, yi)->red;
				outPic(pic.width() -1 - xi, pic.height() -1 - yi)->green = pic(xi, yi)->green;
				outPic(pic.width() -1 - xi, pic.height() -1 - yi)->blue = pic(xi, yi)->blue;

	    }
    }
	outPic.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
	PNG png(width, height);
	for (size_t yi = 0; yi < png.height(); yi++) {
		for (size_t xi = 0; xi < png.width(); xi++) {
			int k = rand() % 3;
			switch(k) {
				case 1:
					png(xi, yi)->blue  = rand() % 254;
					break;
				case 2:
					png(xi, yi)->green = rand() % 254;
					break;
				default:
					png(xi, yi)->red   = rand() % 254;
			}
		}
	}
	return png;
}
