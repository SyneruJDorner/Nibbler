#include "GraphicLibraryExceptions.hpp"

const char * GraphicLibraryExceptions::CreateWindowFailedException::what() const throw()
{     
    return "GL_Library_Exception: Create Window Failed.";
};

const char * GraphicLibraryExceptions::InitFailedException::what() const throw()
{     
    return "GL_Library_Exception: Failed to Initialize.";
};

const char * GraphicLibraryExceptions::RenderInitFailed::what() const throw()
{     
    return "GL_Library_Exception: Failed to Initialize Renderer.";
};
