#ifndef SETUP
#define SETUP

#include <GLAD/glad.h>
#include "../../../RENDERING.h"

const GPUBuffer makeGPUBuffer(const GLuint size, const void* data, const GLuint stride, const GLenum usage);

/*
    Creates a new vao with the given vbo and ebo.


    the function is going to assume that the vbo is going to contain vertex position
    as the first attribute and is going to call glVertexAttribPointer accordingly
*/
const GLuint makeVao(const GPUBuffer vbo, const GPUBuffer ebo);

#endif
