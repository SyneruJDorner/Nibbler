#ifndef GRAPHICS_LIB_H
# define GRAPHICS_LIB_H

    class IGraphicsLib
    {
    public:
        virtual ~IGraphicsLib(void) {};

        virtual void init(int width, int height) = 0;
        virtual void events() = 0;
        virtual void updateDisplay() = 0;
        
    };

    typedef IGraphicsLib* createLib_t();
    typedef void destroyLib_t(IGraphicsLib* instance);

#endif // !GRAPHICS_LIB_H
