#ifndef SDL2_LIB_H
# define SDL2_LIB_H

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

        void init(int width, int height, std::string title);
        e_GraphicLibInput events();
        void updateDisplay();
        void draw(Vector2 point);
        void terminateWindow();

    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !SDL2_LIB_H