#include "LibSDL2.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibSDL2;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
    instance->terminateWindow();
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

void LibSDL2::init(int width, int height, std::string title)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw GraphicLibraryExceptions::InitFailedException();
    }
    
    // Create an application window with the following settings:
    this->window = SDL_CreateWindow(
        title.c_str(),       // window title
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

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
}

e_GraphicLibInput LibSDL2::events()
{
    SDL_Event event;
    if (SDL_PollEvent( & event))
    {
        if (event.type == SDL_QUIT)
        {
            SDL_DestroyWindow(this->window);
            SDL_DestroyRenderer(this->renderer);
            SDL_Quit();
        }
        if (event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_F1:
                    return GLFW;
                case SDLK_F2:
                    return SDL2;
                case SDLK_F3:
                    return SFML;
                case SDLK_a:
                    std::cout << "Event SDL2 key A" << std::endl;
                    return LEFT;
                case SDLK_d:
                    std::cout << "Event SDL2 key D" << std::endl;
                    return RIGHT;
                case SDLK_w:
                    std::cout << "Event SDL2 key W" << std::endl;
                    return UP;
                case SDLK_s:
                    std::cout << "Event SDL2 key S" << std::endl;
                    return DOWN;
                case SDLK_ESCAPE:
                    SDL_DestroyWindow(this->window);
                    SDL_DestroyRenderer(this->renderer);
                    SDL_Quit();
                    return ESCAPE;
                default:
                    break;
            }
        }
    }
    return STD;
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

void LibSDL2::terminateWindow()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    return ;
}