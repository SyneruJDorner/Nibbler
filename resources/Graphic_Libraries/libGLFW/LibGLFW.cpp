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
    (void)action;

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
        case GLFW_KEY_LEFT:
            LibGLFW::status = LEFT;
            break;
        case GLFW_KEY_D:
        case GLFW_KEY_RIGHT:
            LibGLFW::status = RIGHT;
            break;
        case GLFW_KEY_W:
        case GLFW_KEY_UP:
            LibGLFW::status = UP;
            break;
        case GLFW_KEY_S:
        case GLFW_KEY_DOWN:
            LibGLFW::status = DOWN;
            break;
        default:
            LibGLFW::status = STD;
            break;
    }

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

void LibGLFW::init(PassInfo passInfo, std::string title)
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwSetErrorCallback([](int thing, const char *error) {
        std::cout << thing << ": " << error << std::endl;
    });

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    this->window = glfwCreateWindow(passInfo.width, passInfo.height, (title + " - GLFW").c_str(), nullptr, nullptr);

    //Set the window position
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwSetWindowPos(this->window, (mode->width - passInfo.width) / 2, (mode->height - passInfo.height) / 2);

    // Set GLFW callback mechanism(s)
    glfwSetKeyCallback(this->window, keyboardCallback);

    int screenWidth, screenHeight;

    glfwGetFramebufferSize(this->window, &screenWidth, &screenHeight);

    if (nullptr == this->window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return ;
    }

    glfwMakeContextCurrent(window);

    // Setup glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return ;
    }

    glViewport(0, 0, screenWidth, screenHeight);

    //Set camera rojection based on window resolution (start from top)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, screenHeight, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Cache variables here
    this->passInfo= passInfo;
}

e_GraphicLibInput LibGLFW::events()
{
    glfwPollEvents();
    return LibGLFW::status;
}

void LibGLFW::updateDisplay()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glfwSwapBuffers(this->window);
    glClear(GL_COLOR_BUFFER_BIT);
    return ;
}

GLfloat LibGLFW::screenPosX(float pixelPos)
{
    return static_cast<GLfloat>(2.0f * (pixelPos + 0.5f) / 600 - 1.0f);
}

GLfloat LibGLFW::screenPosY(float pixelPos)
{
    return static_cast<GLfloat>(2.0f * (pixelPos + 0.5f) / 480 - 1.0f);
}

void LibGLFW::draw(Grid_t point)
{
    int blockSize = passInfo.gridSize;
    
    glBegin(GL_POLYGON);
        glColor3f(point.color.r, point.color.g, point.color.b);
        glVertex3f((point.position.x * 10) - (blockSize / 2), (point.position.y * 10) - (blockSize / 2), 0.0);
        glVertex3f((point.position.x * 10) + (blockSize / 2), (point.position.y * 10) - (blockSize / 2), 0.0);
        glVertex3f((point.position.x * 10) + (blockSize / 2), (point.position.y * 10) + (blockSize / 2), 0.0);
        glVertex3f((point.position.x * 10) - (blockSize / 2), (point.position.y * 10) + (blockSize / 2), 0.0);
    glEnd();

    return;
}

void LibGLFW::terminateWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
    return ;
}
