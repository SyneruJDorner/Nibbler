
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

    glViewport(0.0f, 0.0f, width, height); //the part the openGL will draw (in pixels).

    glMatrixMode(GL_PROJECTION); //determines the properties of the camera that views the objects in the world coordinate frame.

    glLoadIdentity(); //replace the current matrix with the identity Matrix, and starts afresh, because matrix transforms such as glOrtho and glRotate cumulate, so this basically puts us at (0, 0, 0)
  
    glOrtho(0, width, 0, height, 0, 1); //basically setting the coordinate system.

    glMatrixMode(GL_MODELVIEW); //(default matrix mode), defines how your objects are transformed (rotation, translation, scaling) in your world.

    glLoadIdentity();

}

e_GraphicLibInput LibGLFW::events()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    return LibGLFW::status;
}

void LibGLFW::updateDisplay()
{
    return ;
}

void LibGLFW::draw(Vector2 point)
{
    if (point.x > 0 && point.y > 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        int blockSize = 30;

        GLfloat vertices[] = {
            static_cast<GLfloat>((point.x * 10) - (blockSize/2)), static_cast<GLfloat>((point.y * 10) - (blockSize/2)), 0,
            static_cast<GLfloat>((point.x * 10) + (blockSize/2)), static_cast<GLfloat>((point.y * 10) - (blockSize/2)), 0,
            static_cast<GLfloat>((point.x * 10) - (blockSize/2)), static_cast<GLfloat>((point.y * 10) + (blockSize/2)), 0,
            static_cast<GLfloat>((point.x * 10) + (blockSize/2)), static_cast<GLfloat>((point.y * 10) + (blockSize/2)), 0
        };

        GLfloat colour[] = {
            255, 255, 255,
            255, 255, 255,
            255, 255, 255,
            255, 255, 255
        };

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glColorPointer(3, GL_FLOAT, 0, colour);
        glDrawArrays(GL_POLYGON, 0, 4);
        
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

    }
    return ;
}

void LibGLFW::terminateWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
    return ;
}
