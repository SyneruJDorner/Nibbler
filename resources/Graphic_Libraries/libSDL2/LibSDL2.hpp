#ifndef GLFW_LIB_H
# define GLFW_LIB_H

    #include "../IGraphicsLib.hpp"
    #include <iostream>
    #include "../utils/Exceptions/GraphicLibraryExceptions.hpp"

    #include <SDL2/SDL.h>
    
    class LibSDL2: public IGraphicsLib
    {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

    public:
        LibSDL2(void);
        ~LibSDL2(void);
        LibSDL2(const LibSDL2 &other);
        LibSDL2 *operator=(const LibSDL2 &other);

        void init(int width, int height);
        void events();
        void updateDisplay();
        void draw(Vector2 point);
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H