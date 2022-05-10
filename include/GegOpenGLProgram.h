#pragma once
#include <string>

typedef unsigned int GLuint;
typedef unsigned int GLenum;

class GegOGLProgram
{
public:
    GegOGLProgram(const std::string& InVertexFilePath, const std::string& InFragmeFilePath, GLenum InVertexShaderType, GLenum InFragmShaderType);
    ~GegOGLProgram();

    // GLuint GegCreateProgram(const std::string& InVertexFilePath, const std::string& InFragmeFilePath, GLenum InVertexShaderType, GLenum InFragmShaderType);
    GLuint GegGetProgramId();

private:
//     std::string GegReadFile(const std::string& InFilePath);
//     GLuint GegCreateShader(const std::string& InFilePath, GLenum InShaderType);
//     GLuint GegCreateProgram(GLuint InVertId, GLuint InFragId);
    GLuint GegProgramId;
};