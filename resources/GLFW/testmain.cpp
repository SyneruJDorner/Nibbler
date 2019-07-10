#include "include/GLFW/glfw3.h"
#include <iostream>

int main(void)
{
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        std::cout << "FAILED!" << std::endl;
        // Window or OpenGL context creation failed
    }
}