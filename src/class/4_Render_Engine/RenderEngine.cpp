#include "RenderEngine.hpp"

RenderEngine::RenderEngine()
{
    return ;
}

RenderEngine::RenderEngine(std::string *libDir, int width, int height, int gridSize, int activeLib)
{

    this->libDirectories = new std::string[3];

    for (int i = 0; i < 3; i++)
        this->libDirectories[i] = libDir[i];

    this->activeLibNum = -1;
    this->passInfo.width = width;
    this->passInfo.height = height;
    this->passInfo.gridSize = gridSize;

    setGraphicLib(activeLib);
}

RenderEngine::RenderEngine(const RenderEngine &obj)
{
    *this = RenderEngine(obj.getLibDirectories(), obj.getWidth(), obj.getHeight(), obj.GetGridSize(), obj.getActiveLibNum());
}

RenderEngine::~RenderEngine()
{
    delete this->dlsym_error;
	delete this->activeLib;
    delete [] this->libDirectories;
}


RenderEngine &RenderEngine::operator=(const RenderEngine &other)
{
    RenderEngine *renderEngine = new RenderEngine();
    renderEngine->activeLib = other.activeLib;
    renderEngine->activeLibNum = other.activeLibNum;
    renderEngine->createLib = other.createLib;
    renderEngine->destroyLib = other.destroyLib;
    renderEngine->dlsym_error = other.dlsym_error;
    renderEngine->graphicLib = other.graphicLib;
    renderEngine->libDirectories = other.libDirectories;
    renderEngine->passInfo = other.passInfo;
    return *renderEngine;
}


IGraphicsLib *RenderEngine::getGraphicLib() const
{
    return this->activeLib;
}

void RenderEngine::setGraphicLib(int libNumber)
{
    if (libNumber > 2)
        throw RenderEngineExceptions::LibraryNotFoundException();
    
    if (libNumber != this->activeLibNum)
    {
        //Load The Library
        this->graphicLib = dlopen(this->libDirectories[libNumber].c_str(), RTLD_LAZY | RTLD_LOCAL);
        
        if (!graphicLib)
        {
            //Throw Custom Exception, with error string 
            throw RenderEngineExceptions::LibraryNotFoundException();
        }

        //Reset errors
        dlerror();

        //Load Symbols
        this->createLib = (createLib_t *) (dlsym(this->graphicLib, "createLib"));
        this->dlsym_error = dlerror();

        if (dlsym_error)
        {
            //Throw Custom Exception, with error string 
            throw RenderEngineExceptions::CannotLoadSymbolException();
        }

        this->destroyLib = (destroyLib_t *) (dlsym(this->graphicLib, "destroyLib"));
        this->dlsym_error = dlerror();

        if (dlsym_error)
        {
            //Throw Custom Exception, with error string 
            throw RenderEngineExceptions::CannotLoadSymbolException();
        }

        this->activeLib = this->createLib();
        this->activeLib->init(passInfo, "Nibbler");
        this->activeLibNum = libNumber;
    }
}

void RenderEngine::resetGraphicLib()
{
    this->destroyLib(this->activeLib);
}

void RenderEngine::changeGraphicLib(int libNumber)
{
    if (libNumber != this->activeLibNum)
    {
        resetGraphicLib();
        setGraphicLib(libNumber);
    }
}

int RenderEngine::getWidth() const
{
    return this->passInfo.width;
}

int RenderEngine::getHeight() const
{
    return this->passInfo.height;
}

int RenderEngine::getActiveLibNum() const
{
    return this->activeLibNum;
}

void RenderEngine::setLibDirectories(std::string libDir[])
{
    for (int i = 0; i < 3; i++)
        this->libDirectories[i] = libDir[i];
}

std::string *RenderEngine::getLibDirectories() const
{
    return this->libDirectories;
}

int RenderEngine::GetGridSize() const
{
    return (this->passInfo.gridSize);
}