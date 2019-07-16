#include "SFML_Input.hpp"

//Create a singolton access point.
//You can easily access anything therogh the following.
//Input::instance->WHAT_YOU_WANT();
SFML_Input *SFML_Input::instance = new SFML_Input();

SFML_Input::SFML_Input()
{
    
}

SFML_Input::SFML_Input(SFML_Input &obj)
{
    (void)obj;
}

SFML_Input::~SFML_Input()
{

}

/*
SFML_Input &SFML_Input::operator=(SFML_Input const &other)
{

}
*/