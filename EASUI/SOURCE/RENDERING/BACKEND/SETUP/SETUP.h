#ifndef SETUP
#define SETUP

#include <GLAD/glad.h>
#include "../../RENDERING.h"

const GPUBuffer makeGPUBuffer(const GLuint size, const void* data, const GLuint stride, const GLenum usage);
const GLuint makeVao(const GPUBuffer vbo, const GPUBuffer ebo);

#endif
