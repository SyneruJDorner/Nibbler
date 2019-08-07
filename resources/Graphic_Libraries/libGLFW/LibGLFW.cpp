/*
// Local headers
#include "program.hpp"
#include "gloom/gloom.hpp"
​
    void runProgram(GLFWwindow* window)
    {
        // Set GLFW callback mechanism(s)
        glfwSetKeyCallback(window, keyboardCallback);
​
        // Enable depth (Z) buffer (accept "closest" fragment)
        glDisable(GL_DEPTH_TEST);
        //glDepthFunc(GL_LESS);
​
        // Configure miscellaneous OpenGL settings
        glDisable(GL_CULL_FACE);
​
        // Set default colour after clearing the colour buffer
        glClearColor(0.6f, 0.3f, 0.4f, 1.0f);
​
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
​
        // Set up your scene here (create Vertex Array Objects, etc.)
​
        // Rendering Loop
        while (!glfwWindowShouldClose(window))
        {
            // Clear colour and depth buffers
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glColor4f(0.3f, 0.3f, 0.4f, 1.0f);
​
            // Draw your scene here
            glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
                glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
                glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
                glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
​
                glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
                glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
                glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
            glEnd();                            // Finished Drawing The Triangle
​
            // Handle other events
            glfwPollEvents();
​
            // Flip buffers
            glfwSwapBuffers(window);
        }
    }
​
​
    void keyboardCallback(GLFWwindow* window, int key, int scancode,
                          int action, int mods)
    {
        // Use escape key for terminating the GLFW window
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }
Collapse

*/


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
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


    glfwSetErrorCallback([](int thing, const char *error) {
        std::cout << thing << ": " << error << std::endl;
    });

    std::string newTitle = title + " - GLFW";

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    this->window = glfwCreateWindow(width, height, newTitle.c_str(), nullptr, nullptr);

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

    int blockSize = 30;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, 600, 480, 0, -1.0, 1.0);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    for (auto i = this->points.begin(); i != this->points.end(); ++i)
    {
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex3f((i->position.x * 10) - (blockSize / 2), (i->position.y * 10) - (blockSize / 2), 0.0);
            glVertex3f((i->position.x * 10) + (blockSize / 2), (i->position.y * 10) - (blockSize / 2), 0.0);
            glVertex3f((i->position.x * 10) + (blockSize / 2), (i->position.y * 10) + (blockSize / 2), 0.0);
            glVertex3f((i->position.x * 10) - (blockSize / 2), (i->position.y * 10) + (blockSize / 2), 0.0);
        glEnd();
    }

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(30.0, 0.0, 0.0);
        glVertex3f(30.0, 30.0, 0.0);
        glVertex3f(0.0, 30.0, 0.0);
    glEnd();

    glfwSwapBuffers(this->window);
   
    return ;
}

void LibGLFW::terminateWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
    return ;
}
