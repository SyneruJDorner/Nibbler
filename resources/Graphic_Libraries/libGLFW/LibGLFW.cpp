
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

e_GraphicLibInput LibGLFW::status = STD;

void LibGLFW::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case GLFW_KEY_ESCAPE:
                glfwDestroyWindow(window);
                glfwTerminate();
                LibGLFW::status = ESCAPE; 
                break;
            case GLFW_KEY_F1:
                LibGLFW::status = GLFW;
                break;
            case GLFW_KEY_F2:
                LibGLFW::status = SDL2;
                break;
            case GLFW_KEY_F3:
                LibGLFW::status = SFML;
                break;
            case GLFW_KEY_A:
                std::cout << "Event GLFW key A" << std::endl;
                LibGLFW::status = LEFT;
                break;
            case GLFW_KEY_D:
                std::cout << "Event GLFW key D" << std::endl;   
                LibGLFW::status = RIGHT;
                break;
            case GLFW_KEY_W:
                std::cout << "Event GLFW key W" << std::endl;
                LibGLFW::status = UP;
                break;
            case GLFW_KEY_S:
                std::cout << "Event GLFW key S" << std::endl;
                LibGLFW::status = DOWN;
                break;
            default:
                LibGLFW::status = STD;
                break;
        }
    }
    else
        LibGLFW::status = STD;
    (void)scancode;
    (void)mods;
}

LibGLFW::LibGLFW(void)
{
    window = NULL;
    LibGLFW::status = STD;
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

    glfwSetKeyCallback(this->window, keyboardCallback);
    glfwMakeContextCurrent(this->window);
    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
}

e_GraphicLibInput LibGLFW::events()
{
    glfwPollEvents();
    return LibGLFW::status;
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
