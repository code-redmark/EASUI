#ifndef PRIMITIVES
#define PRIMITIVES

#include "../../../EASUI.h"
#include "../../RENDERING.h"
#include "../../RENDERER/RENDERER.h"
#include "../SETUP/GEOMETRY/GEOMETRY.h"
#include "../../BACKEND/SETUP/PROGRAM/PROGRAM.h"

/*
	Loads primitive's such as rectangles and basic shapes'
	shaders and buffers
*/
int LoadPrimitives();

void LoadPrimitiveShaderProgram();

/*
	Sets up the VAO and Shaders for a simple rectangle
	that makes up most part of EASUI's elements
*/
void makeRectangle();

/*
	Renders a basic rectangle
*/
void RenderRectangle(EASUIvec2 SIZE,  const float ROTATION, EASUIvec2 POSITION , EASUIvec3 COLOR);



#endif
