#include "Input.hpp"
#include <ctime>
#include <sys/select.h>
#define STDIN_FILENO 0

//Create a singolton access point.
//You can easily access anything therogh the following.
//Input::instance->WHAT_YOU_WANT();
Input *Input::instance = new Input();

Input::Input()
{
    ResetInput();
}

Input::Input(Input &obj)
{
    (void)obj;
}

Input::~Input()
{

}

/*
Input &Input::operator=(Input const &other)
{

}
*/

void Input::ResetInput()
{
    this->keyCode = NUL;
}

void Input::SetKeycode(char c)
{
    this->keyCode = static_cast<KeyCode>(c);
}

KeyCode Input::GetPressedKey()
{
    return (this->keyCode);
}

KeyCode Input::DetermineInputs(e_GraphicLibInput output)
{
    KeyCode pressedKey = NUL;

    switch (output)
    {
        case (UP):
            std::cout << "Pressed up." << std::endl;
            pressedKey = W;
            break;
        case (DOWN):
            std::cout << "Pressed down." << std::endl;
            pressedKey = S;
            break;
        case (LEFT):
            std::cout << "Pressed left." << std::endl;
            pressedKey = A;
            break;
        case (RIGHT):
            std::cout << "Pressed right." << std::endl;
            pressedKey = D;
            break;
        default:
            break;
    }

    return pressedKey;
}