#ifndef GRAPHICS_LIB_H
# define GRAPHICS_LIB_H

    #include "../../src/class/3_Game_Classes/Transformation/Vectors/Vector2.hpp"

    class IGraphicsLib
    {
    public:
        virtual ~IGraphicsLib(void) {};

        virtual void init(int width, int height) = 0;
        virtual void events() = 0;
        virtual void updateDisplay() = 0;
        virtual void draw(Vector2 point) = 0;
    };

    typedef IGraphicsLib* createLib_t();
    typedef void destroyLib_t(IGraphicsLib* instance);

#endif // !GRAPHICS_LIB_H
