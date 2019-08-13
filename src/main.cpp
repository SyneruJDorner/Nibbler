#include "class/2_Game_Control/Input.hpp"
#include "class/3_Game_Classes/Player/Player.hpp"
#include "class/1_Manager/GameManager.hpp"
#include <chrono>
#include <thread>
#include <iostream>

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
                return;
            default:
                break;
        }

        Grid_t point = Grid_t();
        Grid_t point2 = Grid_t();

        point.color.SetColour(0.0, 0.0, 1.0, 1.0);
        point.position.x = (manager->getRenderEngine()->getWidth()/10)/2;
        point.position.y = (manager->getRenderEngine()->getHeight()/10)/2;

        point2.color.SetColour(1.0, 0.0, 0.0, 1.0);
        point2.position.x = ((manager->getRenderEngine()->getWidth() - 60)/10)/2;
        point2.position.y = ((manager->getRenderEngine()->getHeight() - 60)/10)/2;

        manager->getRenderEngine()->getGraphicLib()->draw(point);
        manager->getRenderEngine()->getGraphicLib()->draw(point2);
        manager->getRenderEngine()->getGraphicLib()->updateDisplay();

        t += std::chrono::milliseconds(33);
        std::this_thread::sleep_until(t);
    }
}

int	main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
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

            if (width < 640 || height < 480)
                throw "The minimum resolution should be 640x480!";

            GameManager *manager = new GameManager(libs, width, height);

            Init();
            Update(manager);
        }
        catch (const char* msg)
        {
            std::cerr << msg << std::endl;
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