#include "PRIMITIVES.h"
#include "../../RENDERER/RENDERER.h"

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

/*
	Loads all EASUI's primitives' shader programs

	(just rectangle program for now)
*/
void LoadPrimitiveShaderProgram()
{
	GLuint vertexShader = makeShader(PRIMITIVE_VERTEX_SHADER_SOURCE, GL_VERTEX_SHADER);
	GLuint fragmentShader = makeShader(PRIMITIVE_FRAGMENT_SHADER_SOURCE, GL_FRAGMENT_SHADER);

	EASUI_PRIMITIVE_SHADER_PROGRAM = MEMORY_ARENA_ALLOC(sizeof(GLuint));
	*EASUI_PRIMITIVE_SHADER_PROGRAM = makeShaderProgram(vertexShader, fragmentShader);
}

void makeRectangle()
{
	const int indexCount = 6;
	const int vertCount = 4;

	// x, y
	const float vertices[] =
	{
		0.f, 0.f, // top-left
		0.f, 1.f, // bottom-left
		1.f, 0.f, // top-right
		1.f, 1.f  // bottom-right
	};
	
	const unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 1
	};

	GPUBuffer vbo = makeGPUBuffer(sizeof(float) * vertCount, vertices, sizeof(float) * 2, GL_STATIC_DRAW);
	GPUBuffer ebo = makeGPUBuffer(sizeof(float) * indexCount, indices, sizeof(int), GL_STATIC_DRAW);

	GLuint vao = makeVao(vbo, ebo);

	RECTANGLE_DATA = MEMORY_ARENA_ALLOC(sizeof(OBJECT_RENDERING_DATA));
	*(RECTANGLE_DATA) = (OBJECT_RENDERING_DATA)
	{
		.VAO = vao,
		.PROGRAM = EASUI_PRIMITIVE_SHADER_PROGRAM,

		.INDEX_COUNT = indexCount,
		.VERTEX_COUNT = vertCount,

		.INDEXED = true,

		.MODE = GL_TRIANGLES
	};
}


void RenderRectangle(EASUIvec2 SIZE, const float ROTATION, EASUIvec2 POSITION, EASUIvec3 COLOR)
{
	printf("Rendering rect\n");

	mat4 transform;
	glm_mat4_identity(transform);
	
	glm_scale(transform, (vec3) { SIZE.x, SIZE.y, 1.f });
	glm_rotate(transform, ROTATION, (vec3) { 0.f, 0.f, 1.f });
	glm_translate(transform, (vec3) { POSITION.x, POSITION.y, 0.f });
	
	vec4 color = { COLOR.x, COLOR.y, COLOR.z, 1.f };

	if (RECTANGLE_DATA == NULL)
	{
		LOG_EASUI_ERROR("Tried to render rectangle but RECTANGLE_DATA is NULL");
		return;
	}

	glad_glUseProgram(RECTANGLE_DATA->PROGRAM);
	glad_glBindVertexArray(RECTANGLE_DATA->VAO);

	GLint modelLocation = glad_glGetUniformLocation(RECTANGLE_DATA->PROGRAM, MODEL_MAT_UNIFORM_NAME);
	glad_glUniformMatrix4fv(modelLocation, 1, GL_FALSE, (GLfloat*)&transform);

	GLint colorLocation = glad_glGetUniformLocation(RECTANGLE_DATA->PROGRAM, FRAGMENT_COLOR_UNIFORM_NAME);
	glad_glUniform4fv(colorLocation, 1, (GLfloat*)&color);

	glad_glDrawElements(RECTANGLE_DATA->MODE, RECTANGLE_DATA->INDEX_COUNT, GL_UNSIGNED_INT, (void*)0);
}