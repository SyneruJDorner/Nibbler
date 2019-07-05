#include "class/2_Game_Control/Input.hpp"
#include <chrono>
#include <thread>
#include <iostream>


#include "../resources/source/CINDER/include/cinder/Camera.h"
#include "../resources/source/CINDER/include/cinder/Log.h"
#include "../resources/source/CINDER/include/cinder/Rand.h"
#include "../resources/source/CINDER/include/cinder/app/App.h"
#include "../resources/source/CINDER/include/cinder/app/RendererGl.h"
#include "../resources/source/CINDER/include/cinder/gl/GlslProg.h"
#include "../resources/source/CINDER/include/cinder/gl/gl.h"



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
        Input::instance->DetermineInputs();
        //MoveCharacter();
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