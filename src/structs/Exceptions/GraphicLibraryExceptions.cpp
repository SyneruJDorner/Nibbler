#include "GraphicLibraryExceptions.hpp"

const char * GraphicLibraryExceptions::CreateWindowFailedException::what() const throw()
{     
    return "GL_Library_Exception: Create Window Failed.";
};