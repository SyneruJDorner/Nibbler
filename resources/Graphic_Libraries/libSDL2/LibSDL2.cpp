#include "LibSDL2.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibSDL2;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
    delete instance;
}

LibSDL2::LibSDL2(void)
{
    window = NULL;
    return ;
}

LibSDL2::~LibSDL2(void)
{
    return ;
}

LibSDL2::LibSDL2(const LibSDL2 &other)
{
    *this = other;
}

LibSDL2 *LibSDL2::operator=(const LibSDL2 &other)
{
    (void)other;
    return this;
}

void LibSDL2::init(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw GraphicLibraryExceptions::InitFailedException();
    }
    
    // Create an application window with the following settings:
    this->window = SDL_CreateWindow(
        "An SDL2 window",       // window title
        0,                      // initial x position
        0,                      // initial y position
        width,                  // width, in pixels
        height,                 // height, in pixels
        SDL_WINDOW_OPENGL       // flags - see below
    );

    if (this->window == NULL) {
        throw GraphicLibraryExceptions::CreateWindowFailedException();
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!this->renderer) {
        throw GraphicLibraryExceptions::RenderInitFailed();
    }
}

void LibSDL2::events()
{
    SDL_Event event;
    if (SDL_PollEvent( & event))
    {
        if (event.type == SDL_QUIT)
        {
            SDL_Quit();
        }
    }
}

void LibSDL2::updateDisplay()
{
    return ;
}

void LibSDL2::draw(Vector2 point)
{
    (void)point;
    return ;
}
