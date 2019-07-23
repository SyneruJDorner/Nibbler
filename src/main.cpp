#include "class/2_Game_Control/Input.hpp"
#include "class/3_Game_Classes/Player/Player.hpp"
#include "class/1_Manager/GameManager.hpp"
#include <chrono>
#include <thread>
#include <iostream>

/*
Should look something like this
............................................
while (...)
{
treatment Events ();
Update Game Data ();
Update Display ();
}
............................................
*/

/*
Inferface design must resemble bellow
............................................
class INibblerDisplay
{
public:
virtual void init(...) = 0;
virtual void getEvents(...) = 0;
virtual void updateGameData(...) = 0;
virtual void refreshDisplay(...) = 0;
virtual void stop(...) = 0;
};

//Entry points
extern "C"
{
    //These should be short and straight to the point
    INibblerDisplay* getDisplayModule() { return new NibblerDisplayOpenGL(); }
}
............................................
*/

//Initialize world
void Init()
{
    return ;
}

//Looping of game
void Update(GameManager *manager)
{
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();

    while (1)
    {
        e_GraphicLibInput output = manager->getRenderEngine()->getGraphicLib()->events();
        //KeyCode keycode = Input::instance->DetermineInputs();
        
        /*
        switch (keycode)
        {
            case Z:
                manager->getRenderEngine()->changeGraphicLib(0);
                break;
            case X:
                manager->getRenderEngine()->changeGraphicLib(1);
                break;
            case C:
                manager->getRenderEngine()->changeGraphicLib(2);
                break;
            default:
                break;
        }
        */

        switch (output)
        {
            case GLFW:
                manager->getRenderEngine()->changeGraphicLib(GLFW);
                break;
            case SDL2:
                manager->getRenderEngine()->changeGraphicLib(SDL2);
                break;
            case SFML:
                manager->getRenderEngine()->changeGraphicLib(SFML);
                break;
            case ESCAPE:
                return ;
            default:
                break;
        }

        t += std::chrono::milliseconds(33);
        std::this_thread::sleep_until(t);
    }
}

int	main(int ac, char **av)
{
    if (ac > 1 && ac < 4)
    {
        try
        {
            std::string libs[] = {
                "../libraries/libGLFW.so",
                "../libraries/libSDL2.so",
                "../libraries/libSFML.so"
            };

            int width = std::stoi(av[1]);
            int height = std::stoi(av[2]);

            std::cout << "WIDTH: " <<  width << std::endl;
            std::cout << "HEIGHT: " <<  height << std::endl;

            GameManager *manager = new GameManager(libs, width, height);

            Init();
            Update(manager);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr << "ERROR: Incorrect Parameters" << std::endl;
    }

    return 0;
}