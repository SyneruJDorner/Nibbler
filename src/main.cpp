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

void HandleEasterEggs(std::string arg)
{
    std::transform (arg.begin(), arg.end(), arg.begin(), ::tolower);
    if (arg == "rainbow")
        GameManager::instance->EnableRainbowMode();
}

//Looping of game
void Update(GameManager *manager)
{
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();
    KeyCode keycode = NUL;

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
                keycode = Input::instance->DetermineInputs(output);
                break;
        }
        manager->passPlayer(keycode);

        if (manager->Collisions())
        {
            std::cout << "END OF GAME" << std::endl;
            return;
        }

        t += std::chrono::milliseconds(GameManager::instance->GetTimeScale());
        std::this_thread::sleep_until(t);
    }
}

int	main(int ac, char **av)
{
    if (ac > 1 && ac < 5)
    {
        try
        {
            std::string libs[] = {
                "../libraries/libGLFW.so",
                "../libraries/libSDL2.so",
                "../libraries/libSFML.so"
            };

            if (ac < 3)
            {
                throw "To few args provided, please provide a width and height";
            }

            int width = std::stoi(av[1]);
            int height = std::stoi(av[2]);
            
            if (ac == 4)
            {
                std::string arg(av[3]);
                HandleEasterEggs(arg);
            }

            if (width < 640 || height < 480)
                throw "The minimum resolution should be 640x480!";
                
            if (width > 1600 || height > 900)
                throw "The maximum resolution should be 1600x900!";

            GameManager *manager = GameManager::instance;
            manager->SetupManagerForInstance(libs, width, height);

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