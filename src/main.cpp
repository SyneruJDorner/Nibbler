#include "class/2_Game_Control/Input.hpp"
#include "class/3_Game_Classes/Player/Player.hpp"
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
    
}

//Looping of game
void Update()
{
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();

    while (1)
    {
        KeyCode keycode = Input::instance->DetermineInputs();
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