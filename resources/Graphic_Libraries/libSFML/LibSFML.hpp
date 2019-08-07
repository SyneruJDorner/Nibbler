#ifndef SFML_LIB_H
#define SFML_LIB_H

    #include "../IGraphicsLib.hpp"
    #include <iostream>
    #include "../utils/Exceptions/GraphicLibraryExceptions.hpp"

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    
    class LibSFML: public IGraphicsLib
    {
    private:
        sf::RenderWindow *window;
    public:
        LibSFML(void);
        ~LibSFML(void);
        LibSFML(const LibSFML &other);
        LibSFML *operator=(const LibSFML &other);

        void init(int width, int height, std::string title);
        e_GraphicLibInput events();
        void updateDisplay();
        void draw(Grid_t point);
        void terminateWindow();
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H