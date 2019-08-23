#include "RenderEngineExceptions.hpp"

const char * RenderEngineExceptions::LibraryNotFoundException::what() const throw()
{     
    return "Render_Engine_Exception: Graphics Library Not Found.";
};


const char * RenderEngineExceptions::CannotLoadSymbolException::what() const throw()
{     
    return "Render_Engine_Exception: dlsym error: Cannot load Symbol.";
};