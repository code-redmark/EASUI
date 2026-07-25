#include "GEOMETRY.h"

const GPUBuffer makeGPUBuffer(GLenum type, const GLuint size, const void* data, const GLuint stride, const GLenum usage)
{
    char* typeS = type == GL_ARRAY_BUFFER ? "vbo" : "ebo";
    printf("making GPUbuffer for %s\n", typeS);
	GLuint vbo;

	glad_glGenBuffers(1, &vbo);

	glad_glBindBuffer(type, vbo);
	glad_glBufferData(type, size, data, usage);
	glad_glBindBuffer(type, 0);
	
	GLenum err = glad_glGetError();
	if (err != GL_NO_ERROR) printf("[makeGPUBuffer] GL error: %d\n", err);
	else printf("[makeGPUBuffer] GPU buffer created OK (id=%u)\n", vbo);

	return (GPUBuffer)
	{
		.id = vbo,
		.startOffset = 0,
		.stride = stride,
		.size = size
	};
}


const GLuint makeVao(const GPUBuffer vbo, const GPUBuffer ebo)
{
    GLuint vao;

    glad_glGenVertexArrays(1, &vao);
    glad_glBindVertexArray(vao);

    glad_glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
    glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id);

    // Read 2D vertex local space coords off of vbo
    glad_glEnableVertexAttribArray(0);
    glad_glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        vbo.stride,
        (void*)&vbo.startOffset
    );

    glad_glBindVertexArray(0);

    GLenum err = glad_glGetError();
    if (err != GL_NO_ERROR) printf("[makeVao] GL error: %d\n", err);
    else printf("[makeVao] VAO created OK (id=%u)\n", vao);

    return vao;
}