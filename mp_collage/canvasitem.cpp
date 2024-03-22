/**
 * Copyright 2024 University of Oulu
 * Authors:
 *   Elmeri Uotila <roope.uotila@oulu.fi>
 */

#include "canvasitem.h"

CanvasItem::CanvasItem(size_t x, size_t y, Vector2 position, Vector2 scale, RGBAPixel color) {
	resize(x, y);
	// TODO Initialize the pixels transparent so when drawing shapes, the background is transparent

	for (size_t yi = 0; yi < this->height(); yi++) {
		for (size_t xi = 0; xi < this->width(); xi++) {
				RGBAPixel* pixel = (*this)(xi, yi);
				pixel->alpha = 0;
	    }
    }
	// Your code here
	position_ = position;
	color_ = color;
	scale_ = scale;
}

RGBAPixel CanvasItem::getBlendedPixel(size_t x, size_t y){
	RGBAPixel* p = (*this)(x,y);
	RGBAPixel copy = *p;
	// TODO Blend the pixel with color_
	// Multiply the colors per channel and divide by 255
	// Result should be stored in a copy so we don't modify the original PNG
	// This way the color can be easily changed later
	copy.red   = p->red * color_.red / 255;
	copy.green = p->green * color_.green / 255;
	copy.blue  = p->blue * color_.blue / 255;
	
	// Your code here
	
	return copy;
}

Vector2 CanvasItem::position(){
	return position_;
}

Vector2 CanvasItem::scale(){
	return scale_;
}

void CanvasItem::SetPosition(Vector2 pos){
	position_ = pos;
}