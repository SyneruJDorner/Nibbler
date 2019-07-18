#include "RenderEngineExceptions.hpp"

const char * RenderEngineExceptions::LibraryNotFoundException::what() const throw()
{     
    return "Render_Engine_Exception: Graphics Library Not Found.";
};