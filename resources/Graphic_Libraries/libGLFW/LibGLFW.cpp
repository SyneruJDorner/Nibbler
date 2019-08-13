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
    bool isEqual = false;

    for (auto i = this->points.begin(); i != this->points.end(); ++i)
    {
        if (point.position.x == i->position.x)
            if (point.position.y == i->position.y)
                isEqual = true;
    }

    if (!isEqual)
        this->points.push_back(point);

    int blockSize = passInfo.gridSize;//GameManager::instance->GetWorld()->GetGridSize();

    for (auto i = this->points.begin(); i != this->points.end(); ++i)
    {
        glBegin(GL_POLYGON);
            glColor3f(i->color.r, i->color.g, i->color.b);
            glVertex3f((i->position.x * 10) - (blockSize / 2), (i->position.y * 10) - (blockSize / 2), 0.0);
            glVertex3f((i->position.x * 10) + (blockSize / 2), (i->position.y * 10) - (blockSize / 2), 0.0);
            glVertex3f((i->position.x * 10) + (blockSize / 2), (i->position.y * 10) + (blockSize / 2), 0.0);
            glVertex3f((i->position.x * 10) - (blockSize / 2), (i->position.y * 10) + (blockSize / 2), 0.0);
        glEnd();
    }
    
    return;
}

void LibGLFW::terminateWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
    return ;
}
