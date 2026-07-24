#include "PROGRAM.h"


GLuint makeShader(const char* source, GLenum SHADER_TYPE)
{
    GLuint shader = glad_glCreateShader(SHADER_TYPE);
    glad_glShaderSource(shader, 1, &source, NULL);
    glad_glCompileShader(shader);

    GLint compileSuccess;
    glad_glGetShaderiv(shader, GL_COMPILE_STATUS, &compileSuccess);
    if (compileSuccess == GL_FALSE) {
        char infoLog[512];
        glad_glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Shader compile error: %s\n", infoLog);
    }

    return shader;
}

GLuint makeShaderProgram(GLuint vertShader, GLuint fragShader)
{
    GLint linkSuccess;

    GLuint program = glad_glCreateProgram();
    glad_glAttachShader(program, vertShader);
    glad_glAttachShader(program, fragShader);

    glad_glLinkProgram(program);
    glad_glGetProgramiv(program, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess) {
        char infoLog[512];
        glad_glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("Shader compile error: %s\n", infoLog);
    }

    GLint status;

    glad_glValidateProgram(program);
    glad_glGetProgramiv(program, GL_VALIDATE_STATUS, &status);

    if (status == GL_FALSE) {
        char infoLog[512];
        glad_glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("Shader compile error: %s\n", infoLog);
    }

    // we set the
    mat4 view_matrix;
    glm_mat4_identity(view_matrix);

    glad_glUseProgram(program);

    GLint location = glad_glGetUniformLocation(program, VIEW_MAT_UNIFORM_NAME);
    glad_glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat*)view_matrix);

    glad_glUseProgram(0);

    return program;
}