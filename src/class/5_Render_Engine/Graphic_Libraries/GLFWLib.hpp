#ifndef GLFW_LIB_H
#define GLFW_LIB_H

    #include "IGraphicsLib.interface.hpp"
    #include <GLFW/glfw3.h>
    #include "../../../structs/vector2.hpp"

    class GLFWLib: IGraphicsLib
    {
    private:
        GLFWwindow* window;
    public:
        GLFWLib(void);
        ~GLFWLib(void);
        GLFWLib(const GLFWLib &other);
        GLFWLib &operator=(const GLFWLib &other);

        void init(int width, int height);
        void events();
        void updateDisplay();
        void draw(Vector2 point);
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H