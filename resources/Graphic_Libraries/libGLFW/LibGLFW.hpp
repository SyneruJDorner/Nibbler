#ifndef GLFW_LIB_H
#define GLFW_LIB_H

    #include "../IGraphicsLib.hpp"
    #include <iostream>
    #include "../utils/Exceptions/GraphicLibraryExceptions.hpp"

    #include "../../GLFW/glad/include/glad/glad.h"

    #define GL_SILENCE_DEPRECATION
    #include <GLFW/glfw3.h>
    

    class LibGLFW: public IGraphicsLib
    {
    private:
        GLFWwindow* window;
    public:
        LibGLFW(void);
        ~LibGLFW(void);
        LibGLFW(const LibGLFW &other);
        LibGLFW *operator=(const LibGLFW &other);

        void init(int width, int height, std::string title);
        e_GraphicLibInput events();
        void updateDisplay();
        void draw(Vector2 point);
        void terminateWindow();
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H