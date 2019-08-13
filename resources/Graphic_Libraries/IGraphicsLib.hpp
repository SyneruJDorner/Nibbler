#ifndef GRAPHICS_LIB_H
# define GRAPHICS_LIB_H

    # include "../../src/class/6_PassInfo/PassInfo.hpp"
    # include "../../src/class/3_Game_Classes/Grid/Grid.hpp"
    # include <string>

    enum e_GraphicLibInput
    {
        STD = -1,
        GLFW,
        SDL2,
        SFML,
        UP = 4,
        DOWN,
        LEFT,
        RIGHT,
        ESCAPE = 10
    };

    class IGraphicsLib
    {
    public:
        virtual ~IGraphicsLib(void) {};

        virtual void init(PassInfo passInfo, std::string title) = 0;
        virtual e_GraphicLibInput events() = 0;
        virtual void draw(Grid_t point) = 0;
        virtual void updateDisplay() = 0;
        virtual void terminateWindow() = 0;
    };

    typedef IGraphicsLib* createLib_t();
    typedef void destroyLib_t(IGraphicsLib* instance);

#endif // !GRAPHICS_LIB_H
