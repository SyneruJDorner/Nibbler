#include "SDL_Input.hpp"

//Create a singolton access point.
//You can easily access anything therogh the following.
//Input::instance->WHAT_YOU_WANT();
SDL_Input *SDL_Input::instance = new SDL_Input();

SDL_Input::SDL_Input()
{

}

SDL_Input::SDL_Input(SDL_Input &obj)
{
    (void)obj;
}

SDL_Input::~SDL_Input()
{

}

/*
SDL_Input &SDL_Input::operator=(SDL_Input const &other)
{

}
*/