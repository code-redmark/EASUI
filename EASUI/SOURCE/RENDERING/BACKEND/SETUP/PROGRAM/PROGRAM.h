#ifndef GL_SHADER_PROGRAM_PROD
#define GL_SHADER_PROGRAM_PROD

#include <GLAD/glad.h>
#include "../../../RENDERING.h"
#include <cglm/cglm.h>
#include <stdio.h>

GLuint makeShader(const char* source, GLenum SHADER_TYPE);
GLuint makeShaderProgram(GLuint vertShader, GLuint fragShader);


/*
	Gets a shader program's attribute through its name
*/
void getShaderProgramAttribute(GLuint program, GLuint attribute, const char* attrName);


#endif 