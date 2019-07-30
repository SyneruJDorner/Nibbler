#ifndef GLFW_LIB_H
#define GLFW_LIB_H

    #include "../IGraphicsLib.hpp"

    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>

    #include "../utils/Exceptions/GraphicLibraryExceptions.hpp"

    #include "../../GLFW/glad/include/glad/glad.h"

    #define GL_SILENCE_DEPRECATION
    #include <GLFW/glfw3.h>

    class LibGLFW: public IGraphicsLib
    {
    private:
        GLFWwindow* window;
        GLuint vertexArrayID;
        GLuint vertexbuffer;// vertex_shader, fragment_shader, program;
        //GLint mvp_location, vpos_location, vcol_location;
        static e_GraphicLibInput status;
        GLuint programID;
        static const GLfloat g_vertex_buffer_data[9];

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

        GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
        
        static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

    extern "C" IGraphicsLib *createLib();
    extern "C" void destroyLib(IGraphicsLib* instance);

#endif // !GLFW_LIB_H