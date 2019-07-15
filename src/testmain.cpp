#include "../resources/GLFW/glad/include/glad/glad.h"

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SDL2/SDL.h>

#include <iostream>

void initSDL(SDL_Window *window, SDL_Renderer *render)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("-------");
        return ;
        //   throw SnakeSDLException("SDL could not initialize!");
    }
    
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        0,           // initial x position
        0,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL          // flags - see below
    );

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!render) {
        std::cout << "jeez" << std::endl;
    }

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return ;
    }

}

void updateSDL()
{
    bool isquit = false;
    SDL_Event event;
    while (!isquit) {
        if (SDL_PollEvent( & event)) {
            if (event.type == SDL_QUIT) {
                isquit = true;
            }
        }
    }
}

void initOpenGL()
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
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
}

bool exit_SFML = false;

void updateSFML(sf::RenderWindow *window)
{
    if (!exit_SFML)
    {
        window->clear();
        sf::Event ev;
        window->pollEvent(ev);
        if (ev.type == sf::Event::KeyPressed) {
            switch (ev.key.code) {
            
                case sf::Keyboard::Escape:
                    exit_SFML = !exit_SFML;
                    break;                
                default:
                    break;
            }
        }
        window->display();
    }
}

int main(void)
{  

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    initOpenGL();

    SDL_Window *win = NULL;
    SDL_Renderer *ren = NULL;

    initSDL(win, ren);
    
    while(1)
    {
        glfwPollEvents();
        updateSFML(&window);
        updateSDL();
    }


    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    // Clean up
    SDL_Quit();
}