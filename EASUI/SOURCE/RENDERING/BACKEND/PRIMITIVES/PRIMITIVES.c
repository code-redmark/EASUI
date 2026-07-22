#include "PRIMITIVES.h"

void makeRectangle()
{
	const int indexCount = 6;
	const int vertCount = 4;

	// x, y
	const float vertices[] =
	{
		-1.f, 1.f,
		-1.f, -1.f,
		1.f, 1.f,
		1.f, -1.f
	};
	
	const unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 1
	};

	GPUBuffer vbo = makeGPUBuffer(sizeof(float) * vertCount, vertices, sizeof(float) * 2, GL_STATIC_DRAW);
	GPUBuffer ebo = makeGPUBuffer(sizeof(float) * indexCount, indices, sizeof(int), GL_STATIC_DRAW);

	GLuint vao = makeVao(vbo, ebo);

	RECTANGLE_DATA = MEMORY_ARENA_ALLOC(sizeof(OPENGL_PRIMITIVE_DATA));
	*RECTANGLE_DATA = (OPENGL_PRIMITIVE_DATA)
	{
		.VAO = vao,
		
		.indexCount = indexCount,
		.vertCount = vertCount,

		.MODE = GL_TRIANGLES
	};
}

int LoadPrimitives()
{
	makeRectangle();
	if (RECTANGLE_DATA == NULL)
	{
		LOG_EASUI_CRITICAL_ERROR("COULDN'T SET UP RECTANGLE RENDERING PRIMITIVE\n");
		return EASUI_ERROR;
	}

	return EASUI_OK;
}


