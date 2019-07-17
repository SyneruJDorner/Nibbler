
#include "LibGLFW.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibGLFW;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
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

void LibGLFW::init(int width, int height)
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

    this->window = glfwCreateWindow(width, height, "Nibbler", NULL, NULL);
    
    if (window == NULL)
    {
        glfwTerminate();
        throw GraphicLibraryExceptions::CreateWindowFailedException();
    }

    glfwMakeContextCurrent(this->window);
    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
}

void LibGLFW::events()
{
    glfwPollEvents();
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
