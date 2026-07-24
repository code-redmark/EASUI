#ifndef RENDERER
#define RENDERER

#include "../../../EASUI.h"

extern OBJECT_RENDERING_DATA *RECTANGLE_DATA;

/*
	Basic shader for rendering all of EASUIs primitives
*/
extern GLuint* EASUI_PRIMITIVE_SHADER_PROGRAM;

/*
	Goes through all the of the EASUI_WINDOW's elements
	and calls EASUI__RENDER_ELEMENT for each
*/
int EASUI__RENDER_WINDOW(EASUI_WINDOW* WINDOW);

/*
	Renders every EASUI_ELEMENT based on its specific type,
	the rendering happens by rendering multiple primitive 
	objects "on top of each other"
*/
void EASUI__RENDER_ELEMENT(void* ELEMENT);

#endif