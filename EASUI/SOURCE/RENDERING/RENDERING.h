/*
	Contains all rendering data types and basic functions
*/
#ifndef EASUI_RENDERING_H
#define EASUI_RENDERING_H

#include "../../EASUI.h"
#include <GLAD/glad.h>
#include <cglm/cglm.h>

typedef struct OBJECT_RENDERING_DATA OBJECT_RENDERING_DATA;
extern OBJECT_RENDERING_DATA RECTANGLE_DATA;

/*
	Basic shader for rendering all of EASUIs primitives
*/
extern GLuint EASUI_PRIMITIVE_SHADER_PROGRAM;

#define PRIMITIVE_VERTEX_SHADER_SOURCE \
"#version 330 core\n" \
"\n" \
"layout(location = 0) in vec2 aPosition;\n" \
"\n" \
"uniform mat4 uModel;\n" \
"uniform mat4 uView;\n" \
"uniform mat4 uProjection;\n" \
"\n" \
"void main()\n" \
"{\n" \
"    gl_Position = uProjection * uView * uModel * vec4(aPosition, 0.0, 1.0);\n" \
"}\n"


#define PRIMITIVE_FRAGMENT_SHADER_SOURCE \
"#version 330 core\n" \
"\n" \
"uniform vec4 uColor;\n" \
"\n" \
"out vec4 FragColor;\n" \
"\n" \
"void main()\n" \
"{\n" \
"    FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n" \
"}\n"

#define MODEL_MAT_UNIFORM_NAME "uModel"
#define VIEW_MAT_UNIFORM_NAME "uView"
#define PROJ_MAT_UNIFORM_NAME "uProjection"

#define FRAGMENT_COLOR_UNIFORM_NAME "uColor"

/*
	EASUI.h INIT function rendering part

	Initializes rendering globals and
	loads primitives
*/
void EASUI__RENDERING_INIT();

typedef struct GPUBuffer GPUBuffer;

/*
	Contains the data relative to a buffer
	created on the GPU through glCreateBuffers
*/
struct GPUBuffer {
	GLuint id;
	GLint startOffset;
	size_t size;
	GLuint stride;
};


/*
	Contains all the data needed to render an object
	with OpenGL glDrawArrays() or glDrawElements()
*/
struct OBJECT_RENDERING_DATA {
	GLuint VAO;
	GLuint PROGRAM;

	size_t VERTEX_COUNT;

	bool INDEXED;
	size_t INDEX_COUNT;


	/*
		Determines the OpenGL rendering
		mode (triangles, lines, points etc.)
	*/
	GLenum MODE;
};

typedef struct PROJECTION_DATA PROJECTION_DATA;

//struct PROJECTION_DATA
//{
//	mat4 CURRENT_PROJECTION_MAT;
//	unsigned int CURRENT_WIDTH;
//	unsigned int CURRENT_HEIGHT;
//};
//
//extern PROJECTION_DATA currentProjData;
extern mat4 currentProjMat;

void UPDATE_PROJECTION_DATA(EASUI_WINDOW* win);

#endif