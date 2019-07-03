#include "Input.hpp"

//Create a singolton access point.
//You can easily access anything therogh the following.
//Input::instance->WHAT_YOU_WANT();
Input *Input::instance = new Input();

Input::Input()
{

}

Input::Input(Input &obj)
{

}

Input::~Input()
{

}

Input &Input::operator=(Input const &other)
{

}