#include "class/2_Game_Control/Input.hpp"
#include "class/3_Game_Classes/Player/Player.hpp"
#include <chrono>
#include <thread>
#include <iostream>

//Initialize world
void Init()
{

}

//Looping of game
void Update()
{
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();

    while (1)
    {
        KeyCode keycode = Input::instance->DetermineInputs();
        Player::instance->PlayerMovement(keycode);
        //Draw();
        t += std::chrono::milliseconds(33);
        std::this_thread::sleep_until(t);
    }
}

int	main()
{
    Init();
    Update();

       
    return 0;
}