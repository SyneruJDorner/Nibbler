
#include "LibGLFW.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibGLFW;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
    instance->terminateWindow();
    delete instance;
}

LibGLFW::LibGLFW(void)
{
    window = NULL;
    return ;
}

LibGLFW::~LibGLFW(void)
{
    return ;
}

LibGLFW::LibGLFW(const LibGLFW &other)
{
    *this = other;
}

LibGLFW *LibGLFW::operator=(const LibGLFW &other)
{
    (void)other;
    return this;
}

void LibGLFW::init(int width, int height, std::string title)
{
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetErrorCallback([](int thing, const char *str) {
        std::cout << thing << ": " << str << std::endl;
    });

    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    
    if (window == NULL)
    {
        glfwTerminate();
        throw GraphicLibraryExceptions::CreateWindowFailedException();
    }

    glfwMakeContextCurrent(this->window);
    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
}

e_GraphicLibInput LibGLFW::events()
{
    glfwPollEvents();
    return STD;
}

void LibGLFW::updateDisplay()
{
    return ;
}

void LibGLFW::draw(Vector2 point)
{
    (void)point;
    return ;
}

void LibGLFW::terminateWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
    return ;
}