#include "SETUP.h"

const GPUBuffer makeGPUBuffer(const GLuint size, const void* data, const GLuint stride, const GLenum usage)
{
	GLuint vbo;
	glad_glCreateBuffers(1, &vbo);
	glad_glNamedBufferData(vbo, size, data, usage);

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
	glad_glCreateVertexArrays(1, &vao);
	glad_glVertexArrayVertexBuffer(vao, 0, vbo.id, vbo.startOffset, vbo.stride);
	glad_glVertexArrayElementBuffer(vao, ebo.id);

	return vao;
}