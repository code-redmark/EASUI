#ifndef PRIMITIVES
#define PRIMITIVES

#include "../../../EASUI.h"
#include "../../RENDERING.h"
#include "../../RENDERER/RENDERER.h"
#include "../SETUP/SETUP.h"

/*
	Loads primitive's such as rectangles and basic shapes'
	shaders and buffers
*/
int LoadPrimitives();

/*
	Sets up the VAO and Shaders for a simple rectangle
	that makes up most part of EASUI's elements
*/
void makeRectangle();


#endif
