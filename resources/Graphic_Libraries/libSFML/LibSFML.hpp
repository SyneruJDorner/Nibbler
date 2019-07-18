#ifndef GLFW_LIB_H
#define GLFW_LIB_H

    #include "../IGraphicsLib.hpp"
    #include <iostream>
    #include "../utils/Exceptions/GraphicLibraryExceptions.hpp"

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    
    class LibSFML: public IGraphicsLib
    {
    private:
        sf::RenderWindow window;
    public:
        LibSFML(void);
        ~LibSFML(void);
        LibSFML(const LibSFML &other);
        LibSFML *operator=(const LibSFML &other);

        void init(int width, int height);
        void events();
        void updateDisplay();
        void draw(Vector2 point);
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H