#include "PRIMITIVES.h"
#include "../../RENDERER/RENDERER.h"

void LoadPrimitiveShaderProgram();

int LoadPrimitives()
{
	// MUST GO FIRST, DONT MOVE THIS
	LoadPrimitiveShaderProgram();

	makeRectangle();
	return EASUI_OK;

}

/*
	Loads all EASUI's primitives' shader programs

	(just rectangle program for now)
*/
void LoadPrimitiveShaderProgram()
{
	printf("Loaded primitive shader program\n");
	GLuint vertexShader = makeShader(PRIMITIVE_VERTEX_SHADER_SOURCE, GL_VERTEX_SHADER);
	GLuint fragmentShader = makeShader(PRIMITIVE_FRAGMENT_SHADER_SOURCE, GL_FRAGMENT_SHADER);

	EASUI_PRIMITIVE_SHADER_PROGRAM = makeShaderProgram(vertexShader, fragmentShader);
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

	GPUBuffer vbo = makeGPUBuffer(GL_ARRAY_BUFFER, sizeof(vertices), vertices, sizeof(float) * 2, GL_STATIC_DRAW);
	GPUBuffer ebo = makeGPUBuffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, sizeof(unsigned int), GL_STATIC_DRAW);

	GLuint vao = makeVao(vbo, ebo);

	RECTANGLE_DATA = (OBJECT_RENDERING_DATA)
	{
		.VAO = vao,
		.PROGRAM = EASUI_PRIMITIVE_SHADER_PROGRAM,

		.INDEX_COUNT = indexCount,
		.VERTEX_COUNT = vertCount,

		.INDEXED = true,

		.MODE = GL_TRIANGLES
	};

	printf("VAO: %u\n", RECTANGLE_DATA.VAO);
	printf("PROGRAM: %u\n", RECTANGLE_DATA.PROGRAM);
	printf("MODE: %u\n", RECTANGLE_DATA.MODE);
}

void RenderRectangle(EASUIvec2 SIZE, const float ROTATION, EASUIvec2 POSITION, EASUIvec3 COLOR)
{

	mat4 transform;
	glm_mat4_identity(transform);

	glm_translate(transform, (vec3) { POSITION.x, POSITION.y, 0.1f });
	//glm_rotate(transform, ROTATION, (vec3) { 0.f, 0.f, 1.f });
	glm_scale(transform, (vec3) { SIZE.x, SIZE.y, 1.f });
	
	vec4 color = { COLOR.x, COLOR.y, COLOR.z, 1.f };

	glad_glUseProgram(RECTANGLE_DATA.PROGRAM);
	//ProgramUniformCheck(RECTANGLE_DATA.PROGRAM);

	glad_glBindVertexArray(RECTANGLE_DATA.VAO);

	GLint modelLocation = glad_glGetUniformLocation(RECTANGLE_DATA.PROGRAM, MODEL_MAT_UNIFORM_NAME);
	glad_glUniformMatrix4fv(modelLocation, 1, GL_FALSE, (float*)transform);

	GLint colorLocation = glad_glGetUniformLocation(RECTANGLE_DATA.PROGRAM, FRAGMENT_COLOR_UNIFORM_NAME);
	glad_glUniform4fv(colorLocation, 1, (float*)color);

	glad_glDrawElements(RECTANGLE_DATA.MODE, RECTANGLE_DATA.INDEX_COUNT, GL_UNSIGNED_INT, (void*)0);
}