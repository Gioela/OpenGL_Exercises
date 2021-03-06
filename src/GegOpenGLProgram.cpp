#include <glad/glad.h>
#include "OGLProgram.h"
#include "GegOpenGLProgram.h"

GegOGLProgram::GegOGLProgram(const std::string& InVertexFilePath, const std::string& InFragmeFilePath, GLenum InVertexShaderType, GLenum InFragmShaderType)
{
    GLuint VertexShaderId = CreateShader(InVertexFilePath, InVertexShaderType);
    GLuint FragmeShaderId = CreateShader(InFragmeFilePath, InFragmShaderType);

    GegProgramId = CreateProgram(VertexShaderId, FragmeShaderId);
}

GLuint GegOGLProgram::GegGetProgramId()
{
    return GegProgramId;
}

GegOGLProgram::~GegOGLProgram()
{
    GegProgramId = 0;
}
