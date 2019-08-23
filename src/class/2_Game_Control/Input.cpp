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

Input::Input(const Input &obj)
{
    Input *input = new Input();
    input->instance = obj.instance;
    input->keyCode = obj.keyCode;
}

Input::~Input()
{

}

Input &Input::operator=(const Input &other)
{
    Input *input = new Input();
    input->instance = other.instance;
    input->keyCode = other.keyCode;
    return *input;
}

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
            pressedKey = W;
            break;
        case (DOWN):
            pressedKey = S;
            break;
        case (LEFT):
            pressedKey = A;
            break;
        case (RIGHT):
            pressedKey = D;
            break;
        default:
            break;
    }

    return pressedKey;
}