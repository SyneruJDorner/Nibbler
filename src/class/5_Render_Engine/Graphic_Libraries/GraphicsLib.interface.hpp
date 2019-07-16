#ifndef GRAPHICS_LIB_H
# define GRAPHICS_LIB_H

    class GraphicsLib
    {
        virtual init(int width, int height) = 0;
        ~init(void);

        virtual void checkEvents() = 0;
        virtual void updateDisplay() = 0;

    };

#endif // !GRAPHICS_LIB_H
