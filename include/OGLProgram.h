#pragma once
#include "Common.h"
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <string>

static std::string ReadFile(const std::string& InFilePath)
{
    // lettura del file
    std::ifstream InputStream(InFilePath, std::ios::ate);   // apre lo stream e colloca il cursore alla fine del file
    if (!InputStream.is_open()) {
        DIE("Impossible to open file");
    }

    size_t Size = InputStream.tellg();      // tellg ritorna la dimensione dello stream => del file letto
    if (Size == -1) {
        DIE("Impossible read file size");
    }

    std::string Result;
    Result.resize(Size);                    // dimensionata la stringa sulla size dello stream

    InputStream.seekg(0, std::ios::beg);    // riporto il cursore all'inizio del file
    InputStream.read(&Result[0], Size);     // leggo il file e lo scrivo in Result

    InputStream.close();                    // pulisco e chiudo lo stream
    return Result;
}

static GLuint CreateShader(const std::string& InFilePath, GLenum InShaderType)
{
    std::string ShaderStr = ReadFile(InFilePath);
    std::cout << ShaderStr << std::endl;
    
    const char* ShaderSource = ShaderStr.c_str();
    
    GLuint ShaderId = glCreateShader(InShaderType);
    glShaderSource(ShaderId, 1, &ShaderSource, NULL);
    glCompileShader(ShaderId);              // shader compilato sulla GPU

    // interrogo la GPU per informazioni sulla compilazione
    GLint Success;
    glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &Success);
    if (!Success)
    {   
        GLint MaxLogLength;
        glGetShaderiv(ShaderId, GL_INFO_LOG_LENGTH, &MaxLogLength);

        std::vector<GLchar> InfoLog(MaxLogLength);
        glGetShaderInfoLog(ShaderId, MaxLogLength, NULL, InfoLog.data());
        std::string LogStr(InfoLog.begin(), InfoLog.end());
        DIE(LogStr);
    }
    return ShaderId;
}

static GLuint CreateProgram(GLuint InVertId, GLuint InFragId)
{
    GLuint ProgramId = glCreateProgram();
    glAttachShader(ProgramId, InVertId);
    glAttachShader(ProgramId, InFragId);
    glLinkProgram(ProgramId);

    GLint Success;
    glGetProgramiv(ProgramId, GL_LINK_STATUS, &Success);
    if (!Success)
    {   
        GLint MaxLogLength;
        glGetProgramiv(ProgramId, GL_INFO_LOG_LENGTH, &MaxLogLength);

        std::vector<GLchar> InfoLog(MaxLogLength);
        glGetProgramInfoLog(ProgramId, MaxLogLength, NULL, InfoLog.data());
        std::string LogStr(InfoLog.begin(), InfoLog.end());
        DIE(LogStr);
    }

    glDeleteShader(InVertId);
    glDeleteShader(InFragId);
    return ProgramId;
}
