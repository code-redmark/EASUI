#include "RENDERING.h"

#include "BACKEND/PRIMITIVES/PRIMITIVES.h"

OBJECT_RENDERING_DATA RECTANGLE_DATA = { 0 };

/*
	Basic shader for rendering all of EASUIs primitives
*/
GLuint EASUI_PRIMITIVE_SHADER_PROGRAM = 0;

mat4 currentProjMat = { 0 };

void EASUI__RENDERING_INIT()
{
	LoadPrimitives();
}

//PROJECTION_DATA currentProjData = { 0 };

void UPDATE_PROJECTION_DATA(EASUI_WINDOW* win)
{
	printf("\n\nUpdating proj data!\n\n");
	//currentProjData.CURRENT_WIDTH = win->SIZE.x;
	//currentProjData.CURRENT_HEIGHT = win->SIZE.y;
	glm_ortho(0.f, win->SIZE.x, 0.f, win->SIZE.y, -1.f, 1.f, currentProjMat);
	GLint projMatLoc = glad_glGetUniformLocation(EASUI_PRIMITIVE_SHADER_PROGRAM, PROJ_MAT_UNIFORM_NAME);
		
	glad_glUniformMatrix4fv(projMatLoc, 1, GL_FALSE, (GLfloat*)currentProjMat);
	

	GLenum err = glad_glGetError();
	if (err != GL_NO_ERROR) 
	{
		printf("\n\nPROJECTION UNIFORM UPDATE ERROR: %d\n\n", err);
		exit(-1);
	}
		
}