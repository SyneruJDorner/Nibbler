#ifndef GLFW_LIB_H
#define GLFW_LIB_H

    #include "../IGraphicsLib.hpp"

    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>
    #include <cmath>

    #include "../utils/Exceptions/GraphicLibraryExceptions.hpp"

    #include "../../GLFW/glad/include/glad/glad.h"

    #define GL_SILENCE_DEPRECATION
    #include <GLFW/glfw3.h>

    class LibGLFW: public IGraphicsLib
    {
    private:
        GLFWwindow* window;
        GLuint vertexArrayID;
        GLuint VAO[2];
        GLuint VBO, EBO;
        std::vector<Grid_t> points;
        //GLint mvp_location, vpos_location, vcol_location;
        static e_GraphicLibInput status;
        GLuint programID;
        static const GLfloat g_vertex_buffer_data[9];
        std::vector<GLfloat *> buffers;
        PassInfo passInfo;

    public:
        LibGLFW(void);
        ~LibGLFW(void);
        LibGLFW(const LibGLFW &other);
        LibGLFW *operator=(const LibGLFW &other);

        void init(PassInfo passInfo, std::string title);
        e_GraphicLibInput events();
        void updateDisplay();
        void draw(Grid_t point);
        void terminateWindow();
        GLfloat screenPosX(float pixelPos);
        GLfloat screenPosY(float pixelPos);
        void renderQueue(Vector2 point);
       
        static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H