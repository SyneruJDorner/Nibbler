#ifndef GRAPHICS_LIB_H
# define GRAPHICS_LIB_H

    #include "../../src/class/3_Game_Classes/Transformation/Vectors/Vector2.hpp"
    #include <string>
    
    class IGraphicsLib
    {
    public:
        virtual ~IGraphicsLib(void) {};

        virtual void init(int width, int height, std::string title) = 0;
        virtual void events() = 0;
        virtual void updateDisplay() = 0;
        virtual void draw(Vector2 point) = 0;
        virtual void terminateWindow() = 0;
    };

    typedef IGraphicsLib* createLib_t();
    typedef void destroyLib_t(IGraphicsLib* instance);

#endif // !GRAPHICS_LIB_H
