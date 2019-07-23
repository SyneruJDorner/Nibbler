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
        static e_GraphicLibInput status;
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

        static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H