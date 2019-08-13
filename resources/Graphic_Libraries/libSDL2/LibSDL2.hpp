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
        PassInfo passInfo;

    public:
        LibSDL2(void);
        ~LibSDL2(void);
        LibSDL2(const LibSDL2 &other);
        LibSDL2 *operator=(const LibSDL2 &other);

        void init(PassInfo passInfo, std::string title);
        e_GraphicLibInput events();
        void updateDisplay();
        void draw(Grid_t point);
        void terminateWindow();
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !SDL2_LIB_H