#include "GEOMETRY.h"

const GPUBuffer makeGPUBuffer(const GLuint size, const void* data, const GLuint stride, const GLenum usage)
{
	GLuint vbo;

	glad_glGenBuffers(1, &vbo);

	glad_glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glad_glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glad_glBindBuffer(GL_ARRAY_BUFFER, 0);
	
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

    return vao;
}