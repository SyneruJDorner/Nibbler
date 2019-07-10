#include "glad/include/glad/glad.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetErrorCallback([] (int thing, const char *str) { std::cout << thing << ": " << str << std::endl;});

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window: " << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
    while (1)
    {
        glfwPollEvents();
    }
    
}