/*
	Contains all rendering data types and basic functions
*/
#ifndef RENDERING
#define RENDERING

#include <GLAD/glad.h>
#include <cglm/cglm.h>

void INIT_RENDERING();

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

typedef struct OPENGL_PRIMITIVE_DATA OPENGL_PRIMITIVE_DATA;
/*
	Contains data common to EASUIs primitive shapes (rectangles, circles etc.)
*/
struct OPENGL_PRIMITIVE_DATA {
	GLuint VAO;

	size_t vertCount;
	size_t indexCount;


	/*
		Determines the OpenGL rendering
		mode (triangles, lines, points etc.)
	*/
	GLenum MODE;
};


#endif